#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include "datetime.h"

/**
 * Models a timestamp in format YYYY-MM-DD HH:MM:SS 
 */
DateTime::DateTime()
{
}

DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day)
{
	hour = hh;
	min = mm;
	sec = ss;
	this->year = year;
	this->month = month;
	this->day = day;
}

/**
   * Return true if the timestamp is less-than other's
   *
   * @return result of less-than comparison of timestamp
   */
bool DateTime::operator<(const DateTime& other) const
{
	// "<" means younger
	// aka date1 < date2 means date1 happened more recently

	if(this->year < other.year) 
	{ 
		return true; 
	} 
	else if(other.year > this->year)
	{
		return false;
	}

	if(this->month < other.month)
	{
		return true;
	}
	else if(other.month < this->month)
	{
		return false;
	}

	if(this->day < other.day)
	{
		return true;
	}
	else if(other.day < this->day)
	{
		return false;
	}

	if(this->hour < other.hour)
	{
		return true;
	}
	else if(other.hour < this->hour)
	{
		return false;
	}

	if(this->min < other.min)
	{
		return true;
	}
	else if(other.min < this->min)
	{
		return false;
	}

	if(this->sec < other.sec)
	{
		return true;
	}
	else if(other.sec < this->sec)
	{
		return false;
	}

	return false;
}

/**
   * Outputs the timestamp to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS
   *
   * @return the ostream passed in as an argument
   */
std::ostream& operator<<(std::ostream& os, const DateTime& other)
{
	os << other.year << "-" << other.month << "-" << other.day;
	os << " " << other.hour << ":" << other.min << ":" << other.sec;
	return os;
}

/**
   * Inputs the timestamp to the given istream expecting the format:
   *   YYYY-MM-DD HH::MM::SS
   *  Returns if an error in the format with the DateTime set to the
   *   current system time/date
   *   
   *
   * @return the istream passed in as an argument
   */
std::istream& operator>>(std::istream& is, DateTime& dt)
{
    std::string year;
	std::string month;
	std::string day;
	std::string hour;
	std::string min;
	std::string sec;

	getline(is, year, '-');
	std::stringstream year_(year);

	getline(is, month, '-');
	std::stringstream month_(month);

	getline(is, day, ' ');
	std::stringstream day_(day);

	getline(is, hour, ':');
	std::stringstream hour_(hour);

	getline(is, min, ':');
	std::stringstream min_(min);

	getline(is, sec, ' ');
	std::stringstream sec_(sec);

	year_ >> dt.year;
	month_ >> dt.month;
	day_ >> dt.day;
	hour_ >> dt.hour;
	min_ >> dt.min;
	sec_ >> dt.sec;

	return is;
}
