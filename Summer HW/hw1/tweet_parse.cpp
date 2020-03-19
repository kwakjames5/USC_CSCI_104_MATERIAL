#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main(int argc, char** argv)
{
	char* filename = argv[1];

	//initialize infile
	std::ifstream myfile (filename);

	// only run if infile exists
	if(myfile.is_open())
	{
		// initialize vectors for what we are tracking
		std::vector<std::string> tweets;
		std::vector<std::string> users;
		std::vector<std::string> hashtags;
		std::string temp;

		//pushes tweets into tweets vector when a tweet exists on a line
		while(getline(myfile, temp))
		{
			if(!temp.empty())
			{
				tweets.push_back(temp);
			}
		}

		// runs for number of tweets
		for(unsigned int i = 0; i < tweets.size(); i++)
		{
			// initialize stringstreams so we know which tweet to use
			std::stringstream ss;
			ss << tweets[i];
			std::string storage;

			// works when stringstream is storing stuff into storage
			while(ss >> storage)
			{
				// checks for unique users
				if(storage.at(0) == '@')
				{
					bool found = false;

					for(unsigned int j = 0; j < users.size(); j++)
					{
						if(users[j].compare(storage) == 0)
						{
							found = true;
							break;
						}
					}

					if(!found)
					{
						users.push_back(storage);
					}
				}
				//checks for unique hashtags
				else if(storage.at(0) == '#')
				{
					bool found = false;

					for(unsigned int k = 0; k < hashtags.size(); k++)
					{
						if(hashtags[k].compare(storage) == 0)
						{
							found = true;
							break;
						}
					}

					if(!found)
					{
						hashtags.push_back(storage);
					}
				}
			}
		}

		// output message
		std::cout << "1. Number of tweets=" << tweets.size() << std::endl;
		std::cout << "2. Unique users" << std::endl;

		for(unsigned int i = 0; i < users.size(); i++)
		{
			std::cout << users[i].substr(1) << std::endl;
		}

		std::cout << "3. Unique hashtags" << std::endl;

		for(unsigned int i = 0; i < hashtags.size(); i++)
		{
			std::cout << hashtags[i].substr(1) << std::endl;
		}
	}
	else
	{
		// fail case
		std::cout << "File does not open." << std::endl;
		return 0;
	}
}