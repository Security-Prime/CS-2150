// fr2md, Farid Rajabi Nia
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"


/**
 *  @brief compute the distance between a city and a list of cities
 *
 * 	@param	me of the Middle-Earth passed by reference
 * 	@param	start of the starting city
 * 	@param	dests of cities
 *
 * 	@return the float of the total distance
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);

/**
 *  @brief print out the route from a staring city back to itself, covering all cities in the list
 *
 * 	@param	start of the starting city
 * 	@param	dests of destination cities
 *
 * 	@return the float of the total distance
 */

void printRoute (string start, vector<string> dests);


/**
 *  @brief Brute-force implementation of traveling salesman
 *  Using Middle-Earth object to find the shortest path through all cities
 *
 * 	@param	argc the num of the 5 parameters
 * 	@param	argv width, height of the Middle-Earth, number of cities and the number of citiies to be visited, a seed for random number generation
 * 	
 * 	@return the float of the the shortest path and prints the route
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
            << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // YOUR CODE HERE

    string first=dests[0];
    float min=999999999;
    vector<string> newPath;
    sort (dests.begin()+1,dests.end());
    while(next_permutation(dests.begin()+1,dests.end())){ 
        float temp=computeDistance(me, first, dests);
        if(temp<min){
            min=temp;
            newPath=dests;
        }
    }

    printRoute(newPath[0],newPath);
    cout<<"and will have length "<<min<<endl;

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    // YOUR CODE HERE
    float dist=0;
    for(int i=0;i<dests.size();i++){
        dist= dist + me.getDistance(start, dests[i]);
            //goes to each of the cities in the dests
            start=dests[i];            
        }
    //ends back at the 'start' parameter.
    dist= dist + me.getDistance(dests[0],dests[dests.size()-1]);
    return dist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
    // YOUR CODE HERE
    cout<<"Your journey will take you along the path ";
    for (int i=0; i<dests.size();i++){
        cout<<dests[i]<<" -> ";
    }
    cout<<start<<endl;
}
