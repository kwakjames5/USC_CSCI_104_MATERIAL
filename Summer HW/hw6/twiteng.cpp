#include <map>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "user.h"
#include "tweet.h"
#include "twiteng.h"
#include "datetime.h"

TwitEng::TwitEng()
{
}

TwitEng::~TwitEng()
{
    for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
     it != masterUsers_.end(); it++)
    {
    	delete it->second;
    }
}

bool TwitEng::parse(char* filename)
{
	
	std::ifstream ifile(filename);
	if(ifile.fail())
	{
		std::cout << "Could not read file." << std::endl;
		return 0;
	}

	// reads in number of users
	int userCount = 0;
	ifile >> userCount;
	std::string garbage;
	getline(ifile, garbage);

	std::string username;
	bool mainUser = true;
	std::string line;
	std::string word;
	std::stringstream ss;

	for(int i = 0; i < userCount; i++)
	{
		getline(ifile, line);
		ss << line;

		mainUser = true;

		while(ss >> word)
		{			
			// sees who we are working with
			if(mainUser)
			{
				username = word;

				// is a new user
				if(masterUsers_.find(word) == masterUsers_.end())
				{
					User* newUser = new User(word);
					masterUsers_[word] = newUser; //.insert(std::pair<std::string, User*>(word, newUser));
				}

				mainUser = false;
			}
			else
			{
				// if not a new user, only update follow statuses
				if(!(masterUsers_.find(word) == masterUsers_.end()))
				{
					User* a = masterUsers_.find(username)->second;
					User* b = masterUsers_.find(word)->second;
					a->addFollowing(b);
					b->addFollower(a);
				}
				else // is a new user, make new user and update follow statuses
				{
					User* newUser = new User(word);
					masterUsers_.insert(std::pair<std::string, User*>(word, newUser));

					User* a = masterUsers_.find(username)->second;
					User* b = masterUsers_.find(word)->second;
					a->addFollowing(b);
					b->addFollower(a);
				}
			}
		}
		ss.clear();
	}
	ss.clear();

	while(getline(ifile, line))
	{
		if(line.empty())
		{
			continue;
		}
		else
		{
			std::stringstream ss1(line);

    		DateTime time;
    		std::string text;
    		std::string user;

    		ss1 >> time;
    		if(ss1.fail())
			{
				return true;
			}
			

			ss1 >> username;
			if(ss1.fail())
			{
				return true;
			}

			getline(ss1, text);
			text.erase(0, 1);
			addTweet(username, time, text);
		}
      	
     
	}
	return false;
}

void TwitEng::addTweet(const std::string& username, const DateTime& time, const std::string& text)
{
	// username + tweet
	std::map<std::string, User*>::iterator it;
  	it = masterUsers_.find(username);
  	if(it==masterUsers_.end())
  	{
    	throw std::out_of_range("Username not found");
  	}
  	
  	User *newUser = masterUsers_.find(username)->second;
  	Tweet *newTweet = new Tweet(newUser, time, text);

  	std::set<std::string> temp = newTweet->hashTags();
  	for(std::set<std::string>::iterator it = temp.begin();
  		it != temp.end();
  		it++)
  	{
  		std::map<std::string, std::set<Tweet*>>::iterator it1;
  		it1 = masterHashtags_.find(*it);
  		if(it1 != masterHashtags_.end())
  		{
  			it1->second.insert(newTweet);
  		}
  		else
  		{
  			std::set<Tweet*> temp1;
  			temp1.insert(newTweet);
  			masterHashtags_.insert(std::pair<std::string, std::set<Tweet*>>(*it, temp1));
  		}
  	}

  	newUser->addTweet(newTweet);
	
	// hashtags
	for(int i = 0; (unsigned) i < masterUsers_.size(); i++)
	{
		for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
		it != masterUsers_.end(); it++)
		{
			if(username == it->first)
			{
				Tweet* ntweet = new Tweet(it->second, time, text);
				it->second->addTweet(ntweet);
				std::set<std::string> tweetHashes = ntweet->hashTags();

				for(std::set<std::string>::iterator it1 = tweetHashes.begin(); 
				it1 != tweetHashes.end(); it1++)
				{
					if(!(masterHashtags_.find(*it1) == masterHashtags_.end()))
					{
						masterHashtags_.find(*it1)->second.insert(ntweet);
					} 
					else
					{
						std::set<Tweet*> nset;
						nset.insert(ntweet);
						masterHashtags_[*it1] = nset;
					}
				}
			}
		}
	}


}

std::vector<Tweet*> TwitEng::search(std::vector<std::string>& terms, int strategy)
{
	std::vector<Tweet*> trueVector;
	std::set<Tweet*> temp;


	if(strategy == 0) // AND // NOT WORKING
	{
		temp = masterHashtags_[terms[0]];
		std::set<Tweet*> store;

		for(int i = 1; (unsigned) i < terms.size(); i++)
		{
			for(std::set<Tweet*>::iterator it = temp.begin(); 
			it != temp.end(); it++)
			{
    			if(!(masterHashtags_[terms[i]].find(*it) == masterHashtags_[terms[i]].end()))
    			{
      				store.insert(*it);
    			}
  			}
		}

		for(std::set<Tweet*>::iterator it2 = store.begin(); it2 != store.end(); it2++)
		{
			trueVector.push_back(*it2);
		}
	}
	else if(strategy == 1) // OR
	{
		for(std::vector<std::string>::iterator it = terms.begin(); 
		it != terms.end(); it++)
		{
			if(!(masterHashtags_.find(*it) == masterHashtags_.end()))
			{
				for(std::set<Tweet*>::iterator it1 = masterHashtags_.find(*it)->second.begin();
				it1 != masterHashtags_.find(*it)->second.end(); it1++)
				{
					trueVector.push_back(*it1);
				}
			}
		}
	}

	return trueVector;
}

void TwitEng::dumpFeeds()
{
	for(std::map<std::string, User*>::iterator it = masterUsers_.begin(); 
	it != masterUsers_.end(); it++)
	{
		std::ofstream ofile;
		std::string name = it->first;
		name += ".feed";
		
		ofile.open(name.c_str());
		
		std::vector<Tweet*> feed(it->second->getFeed());
		for(unsigned int i = 0; i < feed.size();
			i++)
		{
			ofile << *(feed.at(i)) << std::endl;
		}
	}
}

void TwitEng::addFollowing(std::string name_of_follower, std::string name_to_follow)
{
	// iterator for follower
	std::map<std::string, User*>::iterator followerit;
	followerit = masterUsers_.find(name_of_follower);

	// iterator for name to follow
	std::map<std::string, User*>::iterator followingit;
	followingit = masterUsers_.find(name_to_follow);

	// when both names exist, update follower and following for both
	if(followerit != masterUsers_.end() && followingit != masterUsers_.end())
	{
		followerit->second->addFollowing(followingit->second);
		followingit->second->addFollower(followerit->second);
	}

	// error messages for when either (or both) of the names
	// do not exist in master user map
	if(masterUsers_.find(name_of_follower) == masterUsers_.end())
	{
    	std::cout << name_of_follower << " is not a current user" << std::endl;
    	return;
    }
    else if(masterUsers_.find(name_to_follow) == masterUsers_.end())
	{
		std::cout << name_to_follow << " is not a current user" << std::endl;
    	return;
    }
    else if(masterUsers_.find(name_to_follow) == masterUsers_.end() 
    	&& masterUsers_.find(name_of_follower) == masterUsers_.end())
    {
    	std::cout << name_to_follow << " and " << name_of_follower << " are not current users" << std::endl;
    	return;
    }
}

void TwitEng::create_save_db(std::string filename)
{
	std::ofstream ofile(filename.c_str());

	// prints users and their following
	for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
		it != masterUsers_.end();
		it++)
	{
		// prints name of a main user
		ofile << it->first << " ";

		// access main user's list of following
		std::set<User*> following = it->second->following();

		// runs through the list of followings
		// and prints them out next to main user
		for(std::set<User*>::iterator it1 = following.begin();
			it1 != following.end();
			it1++)
		{
			ofile << (*it1)->name() << " ";
		}

		// new line
		ofile << std::endl;
	}

	for(std::map<std::string, User*>::iterator it2 = masterUsers_.begin();
		it2 != masterUsers_.end();
		it2++)
	{
		// access each user's tweet(s)
		std::list<Tweet*> tweets = it2->second->tweets();

		for(std::list<Tweet*>::iterator it3 = tweets.begin();
			it3 != tweets.end();
			it3++)
		{
			// dereferenced twice to get back to
			// tweets, then the actual tweet itself
			// and outputs this tweet in ofile
			ofile << **it3 << std::endl;
		}
	}
}

void TwitEng::make_scc(std::string filename)
{
	std::cout << "Did not have time to complete" << std::endl;
}