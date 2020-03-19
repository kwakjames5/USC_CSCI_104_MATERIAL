//g++ -g -Wall -std=c++11 str.cpp str_test.cpp -o str_test
//g++ -g -Wall -std=c++11 str.cpp

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "str.h"

using namespace std;

// Add your implementations here.

Str::Str()
{
	size_ = 0;
	data_ = new char[1];
	data_[size_] = '\0';
}

Str::~Str()
{
	delete[] data_;
}

Str::Str(const char* s)
{
	size_ = strlen(s);
	data_ = new char[strlen(s) + 1];
	for(int i = 0; i < this->size_; i++)
	{
		data_[i] = s[i];
	}
	this->data_[this->size_ + 1] = '\0';
}

Str& Str::operator=(const char* s)
{
	this->size_ = strlen(s);
	delete [] data_;
	this->data_ = new char[this->size_ + 1];
	strcpy(this->data_, s);
	return *this;
}

Str& Str::operator+=(const Str& s)
{
    char* temp = new char[this->size_ + s.size() + 1];

    // adds in this
    for (int i = 0; i < this->size_; i++){
    	temp[i] = this->data_[i];
    }

    // adds in s
    for (unsigned int i = 0; i < s.size(); i++){
    	temp[this->size_ + i] = s.data_[i];
    }

    temp[this->size_ + s.size()] = '\0';

    delete [] this->data_;
    this->data_ = temp;

    return *this;   
}

Str& Str::operator+=(const char* s)
{
	char* temp = this->data_;
	this->data_ = new char[strlen(temp) + strlen(s) + 1];
	this->size_ += strlen(s);

	//concatenates this and s into temp
	strcat(this->data_, temp);
	strcat(this->data_, s);

	this->data_[strlen(data_) + strlen(s)] = '\0';

	delete [] temp;

	return *this;
}

size_t Str::size() const
{
	return size_;
}

char& Str::operator[](unsigned int i)
{
	if(i > unsigned(this->size_ - 1))
    {
    	// throws into error message if out of range
        throw std::out_of_range("out of range");
    }
	else
	{
		return this->data_[i];
	} 
}

char const & Str::operator[](unsigned int i) const
{
	if(i > unsigned(this->size_ - 1))
    {
        throw std::out_of_range("out of range");
    }
	else
	{
		return this->data_[i];
	} 
}

Str Str::operator+(const char* rhs) const
{
	char* temp = new char[this->size_ + strlen(rhs) + 1];

	//concatenates this and rhs into temp
  	strcat(temp, this->data_);
  	strcat(temp, rhs);

  	//set the new string and delete temp
  	Str c1(temp);
  	delete [] temp;

  	return c1;
}

Str Str::operator+(const Str& rhs) const
{
	char* temp = new char[this->size_ + rhs.size_ + 1];

	//concatenates this and rhs into temp
  	strcat(temp, this->data_);
  	strcat(temp, rhs.data_);

  	//set the new string and delete temp
  	Str c1(temp);
  	delete [] temp;

  	return c1;
}

bool Str::operator==(const Str& rhs)
{
	return (this->data_ == rhs.data_ && this->size_ == rhs.size_);
}

bool Str::operator!=(const Str& rhs)
{
	return (this->data_ != rhs.data_ && this->size_ != rhs.size_);
}

bool Str::operator>(const Str& rhs)
{
	return strcmp(this->data_, rhs.data_) > 0;
}

bool Str::operator<(const Str& rhs)
{
	return strcmp(this->data_, rhs.data_) < 0;
}

std::istream& operator>>(std::istream& istr, Str& s)
{
  std::string stemp;
  istr >> stemp;
  s = stemp.c_str();
  return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Str& s)
{
  ostr << s.data_;
  return ostr;
}