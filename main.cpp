#include <iostream>
#include <string>
#include <sstream>
#include <fstream>



#include "Tree.h"

int main ( int argc, char *argv[] ) {

    // Get fileName from user as the program is called
    std::string fileName = argv[1];

    // Make tree here
    Tree *inputFileBSTree = new Tree();

    // Data to store user input
    std::string line;
    std::string word;

    // Opens file for reading
	std::ifstream inputFile ( fileName );

    // Gets every line of data from the file
	while ( std::getline( inputFile, line ) ) {

        // Interprets each line and cuts words off by spaces
		std::istringstream ss ( line );

		// Takes each word from the string stream and puts it into std::string word
		while ( ss >> word ) {

			// Insert the word into tree here
			std::cout << word << std::endl;
            inputFileBSTree->Insert( word );

		}

	}

    // Close file
	inputFile.close();

    return 0;
}

