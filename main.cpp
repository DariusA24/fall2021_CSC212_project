#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

#include "Tree.h"

//                     _,,......_
//                  ,-'          `'--.
//               ,-'  _              '-.
//      (`.    ,'   ,  `-.              `.                      ____________________
//       \ \  -    / )    \               \                     |   Leon Hartley   |
//       `\`-^^^, )/      |     /         :                     |  Darius Argueta  |
//          )^ ^ ^V/            /          '.                   | Armani Fernandez |
//          |      )            |           `.                  | December 6, 2021 |
//          9   9 /,--,\    |._:`         .._`.                 -------\   /--------
//          |    /   /  `.  \    `.      (   `.`.                       | |
//          |   / \  \    \  \     `--\   )    `.`.___                  | |
//         .;;./  '   )   '   )       ///'       `-"'                   | |
//         `--'   7//\    ///\                                          | |

// Function declarations
void populateTree ( std::string fileName, Tree* tree );
int getUserChoice ();
bool handleUserChoice ( Tree* tree, int userChoice );

// Main function
int main ( int argc, char *argv[] ) {

    // Get fileName from user as the program is called
    std::string fileName = argv[1];

    // Make tree here
    Tree *inputFileBSTree = new Tree();

    // Clock used to see how long it took to populate the tree from the users file
    clock_t t;

    t = clock();
    populateTree( fileName, inputFileBSTree );
    t = clock() - t;
    std::cout << "Tree successfully populated, took " << ( ( float ) t ) / CLOCKS_PER_SEC << " seconds" << std::endl;

    // User simple GUI
    bool running = true;
    while ( running ) {

        running = handleUserChoice ( inputFileBSTree, getUserChoice() );

    }

    return 0;
}

// Functions Definitions

int getUserChoice () {

    int userChoice = 0;
    std::cout << "(1.): Search if a word is in the tree" << std::endl;
    std::cout << "(2.): Find height of tree" << std::endl;
    std::cout << "(3.): Generate DOT file" << std::endl;
    std::cout << "(4.): Exit program" << std::endl;
    std::cin >> userChoice;

    return userChoice;

}

bool handleUserChoice ( Tree* tree, int userChoice ) {

    // Searching for a word in the Tree
    if ( userChoice == 1 ) {

        // Get user input for the word to search for
        std::string userWord;
        std::cout << "Please input word to search for\nWarning: Case sensitive" << std::endl;
        std::cin >> userWord;

        // Search for the word
        if ( tree->Search ( userWord ) ) {

            int count = tree->Count ( userWord );

            if ( count == 1 ) {
                std::cout << "This word exists 1 time in the tree" << std::endl;
            } else {
                std::cout << "This word exists " << count << " times in the tree" << std::endl;
            }

        } else {
            std::cout << "This word does not exist in the tree" << std::endl;
        }

        return true;

    } else if ( userChoice == 2 ) {

        // Returns the height of the tree
        std::cout << "Height of tree: " << tree->height() << std::endl;
        return true;

    } else if ( userChoice == 3 ) {

        // Generate DOT file
        std::string fileName;
        std::cout << "What would you like to name the file? ( excluding file extension )" << std::endl;
        std::cin >> fileName;
        tree->generateDigraph ( fileName + ".dot" );
        std::cout << fileName << ".dot successfuly generated" << std::endl;
        return true;

    } else if ( userChoice == 4 ) {
        return false;
    }


}


void populateTree ( std::string fileName, Tree* tree ) {

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
			//std::cout << word << std::endl;
            tree->Insert( word );

        }

	}

    // Close file
	inputFile.close();

}

