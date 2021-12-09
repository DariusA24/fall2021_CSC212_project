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
void populateTree ( std::string fileName, Tree* tree, int populationMethod );
int getUserChoice ();
bool handleUserChoice ( Tree* tree, int userChoice );

// Main function
int main ( int argc, char *argv[] ) {

    // Get fileName from user as the program is called
    std::string fileName = argv[1];

    // Make tree here
    Tree *inputFileBSTree = new Tree();

    // Get method of population
    int populationMethod;
    std::cout << "Please choose tree population method:\n(1.) Allow Duplicate nodes\n(2.) Unique nodes only\nAllowing duplicate nodes makes for a disfunction .dot visualization of the tree" << std::endl;
    std::cin >> populationMethod;

    // handle input to make sure legal input is entered;
    bool satisfied = false;
    while ( !( satisfied ) ) {

        // if the method is a legal method allow the user input
        if ( populationMethod == 1 || populationMethod == 2 ) {

            satisfied = true;

        } else {

            // If they enter a illegal input then force them to retry
            std::cout << "Please input a legal number, 1 or 2 for your chosen population method respectively" << std::endl;
            std::cin >> populationMethod;

        }

    }

    // Clock used to see how long it took to populate the tree from the users file
    clock_t t;

    // Populate tree based off of method
    t = clock();
    populateTree ( fileName, inputFileBSTree, populationMethod );
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

// ---------------------------------------
// Function to get the choice of the user
// ---------------------------------------
int getUserChoice () {

    int userChoice = 0;
    std::cout << "(1.): Search if a word is in the tree" << std::endl;
    std::cout << "(2.): Find height of tree" << std::endl;
    std::cout << "(3.): Generate DOT file" << std::endl;
    std::cout << "(4.): Exit program" << std::endl;
    std::cin >> userChoice;

    return userChoice;

}

// ------------------------------------------
// Function to handle the choice of the user
// ------------------------------------------
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

    }

    // Finding the height of the tree
    else if ( userChoice == 2 ) {

        // Returns the height of the tree
        std::cout << "Height of tree: " << tree->height() << std::endl;

    }

    // Generating a .dot file from the tree
    else if ( userChoice == 3 ) {

        // Generate DOT file
        std::string fileName;
        std::cout << "What would you like to name the file? ( excluding file extension )" << std::endl;
        std::cin >> fileName;
        tree->generateDigraph ( fileName + ".dot" );
        std::cout << fileName << ".dot successfuly generated" << std::endl;

    }

    // Quitting the program
    else if ( userChoice == 4 ) {
        return false;
    }

    // Choice from the user is not a legal input
    else {
        std::cout << "Input not understood" << std::endl;
    }

    return true;
}

// -------------------------------------------------------------------------------------
// Function to populate the BST with words from a text file based off the chosen method
// -------------------------------------------------------------------------------------
void populateTree ( std::string fileName, Tree* tree, int method ) {

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

            // Insert the word into tree here based off of method
            // Allow duplicate node method
            if ( method == 1 ) {

                tree->Insert( word );

            }
            // Unique node values only allowed in tree
            else if ( method == 2 ) {

                if ( !( tree->Search( word ) ) ) {

                    tree->Insert( word );

			    }

            }

        }

	}

}
