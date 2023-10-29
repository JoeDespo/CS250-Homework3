//  Ordered Lists (CS 250: HW3)
//  Created by: Joseph D'Esposito
//  Last updated: 10/29/23
//  This program finds the percentage of land needed for solar panals based on the states
//  represented by objects of the State class. It is stored in an ordered linked list based on
//  this percentage and the output displays the list in the correct order.
//

#include <iostream>
#include <list>
#include "State.hpp"

using namespace std;

//Function prototypes
void add(list<State> &l, State &s);
void outputs(list<State> &l);


int main()
{
    //Add the state objects into the list of states
    list<State> states;
    State tx ("Texas", 13480.8, 7487580672000);
    add(states,tx);
    
    State ca ("California", 6922.8, 4563554688000);
    add(states,ca);
    
    State la ("Louisiana", 4200.4, 1445216256000);
    add(states,la);
    
    State fl ("Florida", 4003.1, 1805265792000);
    add(states,fl);
    
    State il ("Illinois", 3612.9, 1614549657600);
    add(states,il);
    
    State pa ("Pennsylvania", 3413.0, 1283967590400);
    add(states,pa);
    
    State oh ("Ohio", 3404.5, 1249649280000);
    add(states,oh);
    
    State ny ("New York", 3354.2, 1520933990400);
    add(states,ny);
    
    State ga ("Georgia", 2727.6, 1656673920000);
    add(states,ga);
    
    State mi ("Michigan", 2610.6, 2696287334400);
    add(states,mi);
    
    outputs(states);
    
    return 0;
}

void add(list<State> &l, State &s)
{
    //Create an iterator for the current location in the list and one for the previous
    list<State>::iterator it;
    list<State>::iterator previous;
    //Use the findPercentage method to determine the ascending state order of the list
    //based on the percentage of the the state area would be needed for only solar panal energy.
    //If the list is empty or findPercentage returns a float smaller than the first object
    //in the list, put the state object to the front of the list.
    if (l.empty() || l.front().findPercentage() > s.findPercentage())
    {
        l.push_front(s);
    }
    //Otherwise we have to iterate through the list until the iterator is at a state object
    //in the list whose findPercentage method returns a larger float than the state object
    //currently being added. Once this is found, add the state object to the previous location
    //iterated in the list (previous iterator).
    else
    {
        previous = l.begin();
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            if (it -> findPercentage() > s.findPercentage())
                break;
            else
                previous = it;
        }
        l.insert(++previous, s);
    }
}

void outputs(list<State> &l)
{
    //This function will handle the output of every state object in the list.
    //The output will be each state's returned value from the findPercentage method.
    list<State>::iterator it;
    for (auto it = l.begin(); it != l.end(); ++it)
    {
        cout << it -> getName() << " would use " <<
        it -> findPercentage() << "% of its area." << endl;
    }
    
}
