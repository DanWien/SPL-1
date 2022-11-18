#pragma once
#include "Graph.h"
#include "Party.h"
#include <vector>

using std::vector;

class SelectionPolicy 
{ 
    virtual Party& select()=0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{

};

class EdgeWeightSelectionPolicy: public SelectionPolicy{ };