#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void readWords(char* filename, vector<vector<string> >& words);

// client interface
void generateSentences(vector<vector<string> >& words, ofstream& ofile);

// recursive helper function
void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences);

void readWords(char* filename,vector<vector<string> >& words)
{
	ifstream ifile(filename);
	string tempSentence;

	if(!ifile.is_open())
	{
		cout << "No input file." << endl;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		getline(ifile, tempSentence);
		stringstream ss(tempSentence);
		vector<string> tempVector;

		// conditional to run ss all the way
		while(ss.peek() != EOF)
		{
			// takes the stringstream and pushes into tempWord
			string tempWord;
			ss >> tempWord;
			// push all tempWords into tempVector
			tempVector.push_back(tempWord);
		}
		// after getting all of the words, push back into main input vector
		words.push_back(tempVector);
	}
}

void generateSentences(vector<vector<string> >& words, ofstream& ofile)
{
	// for when there is no adj/adv
	words[0].insert(words[0].begin(), "");
    words[3].insert(words[3].begin(), "");

    // generate sentence outfile
	int numSentences = 0;
    genHelper(words, ofile, 0, "",  numSentences);
    ofile << numSentences << " sentences.";

    // reset the vector
    words[0].erase(words[0].begin());
    words[3].erase(words[3].begin());
}

void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences)
{
	// for when sentence is fully formed
	if(currentOption == 4)
	{
		ofile << "The " << sentence.substr(0, sentence.length() - 1) << "." << endl;
        numSentences++;
	}
	else
	{
		// run through each vector for each currentOption
		for(int i = 0; i < words[currentOption].size(); i++)
		{
			sentence = sentence + words[currentOption].at(i);
			int size = words[currentOption].at(i).length();

			// when a word is just a space / empty
			if(!words[currentOption].at(i).empty())
			{
				sentence += " ";
				size++;
			}

			// recursize call
			genHelper(words, ofile, currentOption + 1, sentence, numSentences);
            sentence = sentence.substr(0, sentence.length() - size);
		}
	}
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./sentences input_file output_file" << endl;
  }
  vector<vector<string> > words;

  // Parse the file
  readWords(argv[1], words);

  // Check the status of parsing
  if(words.size() < 4){
    cerr << "Input file requires 4 lines of words" << endl;
    return 1;
  }

  // Open the output file
  ofstream ofile(argv[2]);
 
  // generate all the sentence options writing them to ofile
  generateSentences(words, ofile);

  ofile.close();

  return 0;
}
