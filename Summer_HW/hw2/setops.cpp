#include <iostream>
#include <set>
#include <string>
#include "setops.h"

std::set<std::string> operator&(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2)
{
	std::set<std::string>::iterator a = s1.begin();
	std::set<std::string>::iterator b = s2.begin();
	std::set<std::string> temp;

	while ((a != s1.end()) && (b != s2.end()))
	{ 
		if(*a < *b)
		{
			a++;			
		} 
		else if (*b < *a)
		{
			b++;
		}
		else
		{
			temp.insert(*a);
			a++;
			b++;
		}
	}
		return temp;
}

std::set<std::string> operator|(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2)
{
	std::set<std::string>::iterator a = s1.begin();
	std::set<std::string>::iterator b = s2.begin();
	std::set<std::string> temp;

	while ((a != s1.end()) && (b != s2.end()))
	{
		if (*a < *b)
		{
			temp.insert(*a);
			a++;
		}
		else if (*b < *a)
		{
			temp.insert(*b);
			b++;
		}
	}
	return temp;
}

std::set<std::string> operator-(const std::set<std::string>& s1,
                                const std::set<std::string>& s2)
{
	std::set<std::string>::iterator a = s1.begin();
	std::set<std::string>::iterator b = s2.begin();
	std::set<std::string> temp;

	while ((a != s1.end()) && (b != s2.end()))
	{
		if (*a < *b)
		{
			temp.insert(*a);
			a++;
		}
		else if (*b < *a)
		{
			b++;
		}
		else 
		{
			a++;
			b++;
		}
	}
	return temp;
}	