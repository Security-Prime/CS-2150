// fr2md Farid Rajabi Nia
// This program shows how C-based file I/O works.  It will open a
// file, read in the first two strings, and print them to the screen.

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

/**
 * @brief a struct that holds the name of the course, a vector of its relations and its numbers
 */

struct vertex {
    vector<vertex*> adjacent;
    string name;
    int indegree = 0;
};

map<string, vertex*> verMap;

/**
 * @brief no return ftn that topologically sort the name of courses based on the given dependencies.
 * @see queue and map
 *
 */
void topoSort(){
    queue<vertex*> q;
    vertex *v;

    map<string, vertex*>::iterator it;

    for ( it = verMap.begin(); it != verMap.end(); it++ ){
        if(it->second->indegree==0)
            q.push(it->second);
    }

    while(!q.empty()){
        v= q.front();
        cout<<v->name<<" ";
        q.pop();
        for(int j=0;j<v->adjacent.size();j++){
            v->adjacent[j]->indegree--;
            if(v->adjacent[j]->indegree==0)
                q.push(v->adjacent[j]);
            }
    }

}

/**
 * @brief read a file from the console and get the names of the courses line ny line to create dependencies
 * later used to perfom topological sort
 *
 * @return 0
 * @param a text file *.txt holding the names of the courses
 *
 */
// we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    // read in two strings

    string s1, s2;
    while (file.good()){
        file >> s1;
        file >> s2;
        if(s1=="0")
            break;

        vertex* temp = verMap.find(s1)->second;
        if (temp == NULL){
            temp=new vertex();
            temp->name = s1;
            verMap[s1] = temp;
        }
        vertex* temp2 = verMap.find(s2)->second;;
        if (temp2 == NULL){
            temp2=new vertex();
            temp2->name = s2;
            verMap[s2] = temp2;
        }

        temp2->indegree++;
        temp->adjacent.push_back(temp2);
    }

    topoSort();


    // close the file before exiting
    file.close();


    return 0;
}
