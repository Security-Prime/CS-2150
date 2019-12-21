// Farid Rajabi Nia fr2md
// This program is the skeleton code for the lab 10 in-lab.  It uses
// C++ streams for the file input, and just prints out the data when
// read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "huffNode.h"
#include "treeBuilder.h"
#include <vector>

using namespace std;

// main(): we want to use parameters
int main (int argc, char **argv) {
	// verify the correct number of parameters
	if ( argc != 2 ) {
		cout << "Must supply the input file name as the only parameter" << endl;
		exit(1);
	}
	// attempt to open the supplied file; must be opened in binary
	// mode, as otherwise whitespace is discarded
	ifstream file(argv[1], ifstream::binary);
	// report any problems opening the file and then exit
	if ( !file.is_open() ) {
		cout << "Unable to open file '" << argv[1] << "'." << endl;
		exit(2);
	}
	// read in the first section of the file: the prefix codes

	huffNode* node= new huffNode(NULL,0, NULL, NULL);
	treeBuilder builder;

	while ( true ) {
            string character, prefix;
            // read in the first token on the line
            file >> character;
            if ( (character[0] == '\n') || (character[0] == '\r') )
                    continue;
            // did we hit the separator?
            if ( (character[0] == '-') && (character.length() > 1) )
                    break;
            // check for space
            /*if ( character == "space" )
                    character = " ";*/
            if(character.length()>1){
                    prefix = character;
                    character = " ";
            }
            else{
            // read in the prefix code
            file >> prefix;
            }
            // do something with the prefix code
    /*	cout << "character '" << character << "' has prefix code '"
            << prefix << "'" << endl;*/
            builder.buildTree(node,character[0],prefix);
      }



	// read in the second section of the file: the encoded message
	stringstream sstm;
	while ( true ) {
		string bits;
		// read in the next set of 1's and 0's
		file >> bits;
		// check for the separator
		if ( bits[0] == '-' )
			break;
		// add it to the stringstream
		sstm << bits;
	}

	string allbits = sstm.str();
	// at this point, all the bits are in the 'allbits' string
	cout << "All the bits: " << allbits << endl;
	//char bit;

	huffNode* temp=node;
	for (int i=0; i<allbits.length();i++){
            if(allbits[i]=='0' && (temp->left))
                temp=temp->left;
            else if(allbits[i]=='1' && (temp->right))
                temp=temp->right;
            if(!(temp->left) && !(temp->right)){
                cout<<temp->sent;
                temp=node;
            }

	}

	// close the file before exiting
	file.close();
}
