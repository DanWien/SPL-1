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
    Coalition(int id);
    bool isFull();
    int getMandates() const;
    vector<int> getCoalition() const;
    void setCoalition(int partyID);
    int getcoID();
    void setMandates (int mandates);
    Agent& getAgent();

private:
    int numOfMandates;
    vector<int> coVector;
    int coID;
    Agent& ogAgent;
};