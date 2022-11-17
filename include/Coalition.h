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
    void addParty();
    vector<int> getCoalition() const;
    vector<int> setCoalition(int partyID);
    int getcoID();

private:
    int numOfMandates;
    vector<int> coVector;
    int coID;
};