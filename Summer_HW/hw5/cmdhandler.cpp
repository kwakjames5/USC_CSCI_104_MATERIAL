#include "cmdhandler.h"
#include "util.h"
using namespace std;

QuitHandler::QuitHandler()
{

}

QuitHandler::QuitHandler(Handler* next)
  : Handler(next)
{

}

bool QuitHandler::canHandle(const std::string& cmd) const
{
	return cmd == "QUIT";

}

Handler::HANDLER_STATUS_T QuitHandler::process(TwitEng* eng, std::istream& instr) const
{
	eng->dumpFeeds();
	return HANDLER_QUIT;
}



AndHandler::AndHandler()
{
}

AndHandler::AndHandler(Handler* next)
  : Handler(next)
{
}

bool AndHandler::canHandle(const std::string& cmd) const
{
	return cmd == "AND";
}

Handler::HANDLER_STATUS_T AndHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::vector<std::string> searchTerms;
	std::string temp;

	while(instr >> temp)
	{
		searchTerms.push_back(temp);
	}

	std::vector<Tweet*> searchResults = eng->search(searchTerms, 0);
	displayHits(searchResults);

	return HANDLER_OK;
}



OrHandler::OrHandler()
{
}

OrHandler::OrHandler(Handler* next)
  : Handler(next)
{
}

bool OrHandler::canHandle(const std::string& cmd) const
{
	return cmd == "OR";
}

Handler::HANDLER_STATUS_T OrHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::vector<std::string> searchTerms;
	std::string temp;

	while(instr >> temp)
	{
		searchTerms.push_back(temp);
	}

	std::vector<Tweet*> searchResults = eng->search(searchTerms, 1);
	displayHits(searchResults);

	return HANDLER_OK;
}



TweetHandler::TweetHandler()
{
}

TweetHandler::TweetHandler(Handler* next)
  : Handler(next)
{
}

bool TweetHandler::canHandle(const std::string& cmd) const
{
	return cmd == "TWEET";
}

Handler::HANDLER_STATUS_T TweetHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string name;
	instr >> name;
	std::string text;
	DateTime time;
	
	getline(instr, text);
	eng->addTweet(name, time, text);
	
	return HANDLER_OK;
}

FollowHandler::FollowHandler()
{
}

FollowHandler::FollowHandler(Handler* next)
  : Handler(next)
{
}

bool FollowHandler::canHandle(const std::string& cmd) const
{
	return cmd == "FOLLOW";
}

Handler::HANDLER_STATUS_T FollowHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string name_of_follower;
	instr >> name_of_follower;
	std::string name_to_follow;
	instr >> name_to_follow;

	eng->addFollowing(name_of_follower, name_to_follow);

	return HANDLER_OK;
}

SaveHandler::SaveHandler()
{
}

SaveHandler::SaveHandler(Handler* next)
  : Handler(next)
{
}

bool SaveHandler::canHandle(const std::string& cmd) const
{
	return cmd == "SAVE";
}

Handler::HANDLER_STATUS_T SaveHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string new_db_filename;
	instr >> new_db_filename;

	eng->create_save_db(new_db_filename);

	return HANDLER_OK;
}