#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

bool solveStatus(std::vector<std::vector<std::string> >& clauses, std::map<std::string, int>& map_)
{
	// run through all clauses
	for(int i = 0; (unsigned)i < clauses.size(); i++)
	{
		// initial, false status
		// int in order to track 3 different states
		// (true, false, unassigned)
		int status = 0;

		// run through each clause and check
		// every single word and update status
		for(int j = 0; (unsigned)j < clauses.at(i).size(); j++)
		{
			if(stoi(clauses[i][j]) > 0)
			{
				if(map_[clauses[i][j]] == 1)
				{
					status = 1;
					break;
				}
				else if(map_[clauses[i][j]] == -1)
				{
					status = -1;
					break;
				}
			}
			else 
			{
				if(map_[clauses[i][j].substr(1, clauses[i][j].size())] == 0)
				{
					status = 1;
					break;
				} 
				else if(map_[clauses[i][j].substr(1, clauses[i][j].size())] == -1)
				{
					status = -1;
					break;
				}
			}					
		}

		// when status is never updated in the function,
		// status stays false and returns accordingly
		if(status == 0)
		{
			return false;
		}
	}
	// when status == 0 does not run, that means
	// status has a value that means it is a clause
	// that can be solved. return true accordingly.
	return true;
}

bool solve(std::map<std::string, int >::iterator& it, 
	std::vector<std::vector<std::string> >& clauses, 
	std::map<std::string, int>& map_)
{
	// return when the iterator has run to the
	// end of the map_
	if(it == map_.end())
	{
		return true;
	}
	else
	{
		for(int i = 0; i < 2; i++)
		{
			it->second = i;

			// if it can be solved
			if(solveStatus(clauses, map_))
			{
				std::map<std::string, int>::iterator it1 = it;

				// recursive call to function
				if(solve(++it1, clauses, map_))
				{
					return true;
				}
			}
		}		
	}
	return false;
}

int main(int argc, char* argv[])
{
	// error message
	if(argc < 3)
	{
		std::cout << "Enter the necessary files." << std::endl;
		return false;
	}

	// in file
	std::ifstream ifile(argv[1]);

	// out file
	std::ofstream ofile(argv[2]);

	// check for when the in file is not
	// appropriate for the program
	if(ifile.fail())
	{
		std::cout << "File failed" << std::endl;
		return false;
	}

	std::vector<std::vector<std::string> > clauses;
	std::map<std::string, int> map_;
	std::string line;
	std::string word;
	int varCount;
	int clauseCount;

	while(getline(ifile, line))
	{
		std::stringstream ss(line);
		if(ss >> word)
		{
			if(word == "c")
			{
				continue;				
			}
			else if(word == "p")
			{
				// move the ss along when "p" is encountered
				ss >> word;

				// store variable count
				ss >> word;
				varCount = stoi(word);

				// store clause count
				ss >> word;
				clauseCount = stoi(word);
				break;
			}
		}
	}

	for(int i = 1; i <= varCount; i++)
	{
		std::string temp = std::to_string(i);
		map_[temp] = -1;
	}

	for(int i = 0; i < clauseCount; i++)
	{
		std::vector<std::string> temp;
		getline(ifile, line);
		std::stringstream ss(line);

		while(ss >> word)
		{
			if(stoi(word) == 0)
			{
				break;
			}
			else
			{
				temp.push_back(word);
			}
		}
		clauses.push_back(temp);
	}
	
	// set a new iterator for the solve function
	std::map<std::string, int>::iterator it = map_.begin();

	// update the ofile
	if(solve(it, clauses, map_))
	{
		for(std::map<std::string,int>::iterator it1 = map_.begin(); it1!=map_.end(); ++it1)
		{
			ofile << it1->first << " = " << it1->second << std::endl;
		}
	}
	else
	{
		ofile << "No Solution" << std::endl;
	}
	
}