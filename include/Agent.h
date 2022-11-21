#pragma once

#include <vector>
#include "Graph.h"
#include "SelectionPolicy.h"

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

 

    virtual ~Agent();
    Agent(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* mCoalition;
};
