#pragma once

#include <vector>
#include "Graph.h"
#include "Party.h"
#include "Agent.h"

class Agent;
class Party;

class Coalition
{

public:
    Coalition(Agent& a, vector<int> co, int mandates, int id);
    bool isFull();
    int getMandates() const;
    vector<int> getCoalition() const;
    void addParty(int partyID);
    void setMandates (int mandates);
    Agent& getAgent();
    int getId();

private:
    Agent& ogAgent;
    vector<int> coVector;
    int numOfMandates;
    int coId;
};