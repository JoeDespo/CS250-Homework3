//
//  State.cpp
//  CS250 Homework3
//
//  Created by Joseph D'Esposito on 10/26/23.
//

#include "State.hpp"
#include <iostream>
#include <string>
using namespace std;

State::State()
{
    //default constructor
}
State::State(string name, double energy, long long size) //constructor
{
    m_name = name;
    m_energy = energy;
    m_size = size;
}


//Get methods to return attributes and set methods for the attributes.
void State::setName(string name)
{
    m_name = name;
}

string State::getName()
{
    return m_name;
}

void State::setEnergy(double energy)
{
    m_energy = energy;
}

double State::getEnergy()
{
    return m_energy;
}

void State::setSize(long long size)
{
    m_size = size;
}

long long State::getSize()
{
    return m_size;
}

//Calculation to find the percent of land needed for the panals with the following
//information given: "A modern 18 square foot solar panels is around 15% efficient,
//so that works out to approximately 15 watts per square foot, or 51 BTUs per panel."

double State::findPercentage()
{
    double panels = (m_energy * 1000000000000)/ 51.0;
    double sqftPanels = panels * 18.0;
    return (sqftPanels / m_size) * 100;
}
