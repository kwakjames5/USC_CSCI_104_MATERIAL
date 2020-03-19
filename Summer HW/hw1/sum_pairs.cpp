#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	char* filename = argv[1]; 
	char* outFile = argv[2];

	// initialize infile 
	std::ifstream myfile (filename); 

	// only run if infile exists
	if(myfile.is_open()) 
	{
		// initialize outfile
		std::ofstream out (outFile); 
		int size;
		myfile >> size;

		// fail case
		if(myfile.fail() || size == 0) 
		{
			out << 0 << std::endl;
			return 0;
		}

		// dynamically allocate new array
		int* array = new int[size];

		// set the array
		for(int i = 0; i < size; i++) 
		{
			int temp;
			myfile >> temp;
			array[i] = temp;
		}

		// use the array and put into outfile
		for(int i = 0; i < ((size + 1)/2); i++) 
		{
			out << (array[i] + array[size - 1 - i]) << std::endl;
		}

		myfile.close();
		delete [] array;
	}

	return 0;
}