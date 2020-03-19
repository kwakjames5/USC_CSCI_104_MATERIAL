#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <cctype>
#include "tweet.h"
#include "datetime.h"
#include "user.h"
#include "util.h"

Tweet::Tweet()
{
}

Tweet::Tweet(User* user, const DateTime& time, const std::string& text)
{
	user_ = user;
	time_.year = time.year;
    time_.month = time.month;
    time_.day = time.day;
    time_.hour = time.hour;
    time_.min = time.min;
    time_.sec = time.sec;
	text_ = text;

	std::string temp;
    std::stringstream ss(text);
    while (ss >> temp)
    {
      if (temp.at(0) == '#')
      {
        temp.erase(temp.begin());
        convLower(temp);
        hashtags_.insert(temp);
      }
    }
}

DateTime const & Tweet::time() const
{
	return time_;
}

std::string const & Tweet::text() const
{
	return text_;
}

std::set<std::string> Tweet::hashTags() const
{
	return hashtags_;
}

bool Tweet::operator<(const Tweet& other) const
{
	if(this->time_ < other.time_)
	{
		return true;
	} 
	else if(other.time_ < this->time_)
	{
		return false;
	}

	return true;
}
  
std::ostream& operator<<(std::ostream& os, const Tweet& t)
{
	os << t.time() << " " << t.user_->name() << " " << t.text_;
	return os;
}

User* Tweet::user() const
{
	return user_;
}