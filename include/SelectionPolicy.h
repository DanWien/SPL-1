#pragma once
#include <vector>


using std::vector;

class Party; 
class Simulation;
class Agent;

class SelectionPolicy 
{
public:
    virtual int select(Simulation &sim, int partyId, Agent& agent)=0;
    virtual ~SelectionPolicy()=default;
    virtual SelectionPolicy* cloneSPolicy()=0;
};

class MandatesSelectionPolicy: public SelectionPolicy
{
public:
    virtual int select(Simulation &sim, int partyId, Agent& agent);
    SelectionPolicy* cloneSPolicy() override;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy
{
public:
    virtual int select(Simulation &sim, int partyId, Agent& agent);
    SelectionPolicy* cloneSPolicy() override;
};