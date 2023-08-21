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
    Coalition(vector<int> co, int mandates, int id);
    bool isFull();
    int getMandates() const;
    vector<int> getCoalition() const;
    void addParty(int partyID);
    void setMandates (int mandates);
    int getId();

    virtual ~Coalition();
    Coalition(const Coalition& other);
    Coalition(Coalition&& other);
    Coalition& operator=(const Coalition& other);
    Coalition& operator=(Coalition&& other);

private:
    vector<int> coVector;
    int numOfMandates;
    int coId;
};