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
    void setCoalition(int co);
    SelectionPolicy* getSelectionPolicy();
    void setId(int id);
    void setPartyId(int pId);
    int getCoId();

 

    virtual ~Agent();
    Agent(const Agent& other);
    Agent(Agent&& other);
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int mCoalition;
};
