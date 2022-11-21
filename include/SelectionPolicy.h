#pragma once
#include "Graph.h"
#include "Party.h"
#include <vector>
#include "Simulation.h"
#include "Coalition.h"
#include "Agent.h"

using std::vector;

class SelectionPolicy 
{
public:
    virtual Party* select(Simulation &sim, int partyId, Agent& agent)=0;
    virtual int checkSPolicy()=0;
    virtual ~SelectionPolicy()=default;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
public:
    virtual Party* select(Simulation &sim, int partyId, Agent& agent);
    virtual int checkSPolicy();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    virtual Party* select(Simulation &sim, int partyId, Agent& agent);
    virtual int checkSPolicy();
};