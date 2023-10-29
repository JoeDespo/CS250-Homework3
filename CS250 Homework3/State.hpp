//
//  State.hpp
//  CS250 Homework3
//
//  Created by Joseph D'Esposito on 10/26/23.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include <string>
using namespace std;

class State
{
public:
    State();
    State(string, double, long long);
    double findPercentage();
    void setName(string);
    string getName();
    void setEnergy(double);
    double getEnergy();
    void setSize(long long);
    long long getSize();
    
protected:
private:
    string m_name; //state name
    double m_energy; //energy consumption in trillions of BTUs
    long long int m_size; //size of state in square feet
    double m_percentage; //percent of land needed for the panals
};

#endif /* State_hpp */
