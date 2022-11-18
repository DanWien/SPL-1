#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;
class Coalition;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
 
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Coalition &getCoalition() const;
    void setCoalition(Coalition& co);
    SelectionPolicy* getSelectionPolicy();
    void setId(int id);
    void setPartyId(int pId);



private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* mCoalition;
};
