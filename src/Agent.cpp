#include "Agent.h"
#include "SelectionPolicy.h"
#include "Coalition.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition(agentId)
{
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    SelectionPolicy* p = getSelectionPolicy();
    int selectedPartyId = p->select(sim,this->getPartyId(), *this);
    if(selectedPartyId!=-1)
    {
        Party& selected = sim.getParty(selectedPartyId);
        selected.addOffer(this->getCoId());
        if(selected.getState() == Waiting)
            selected.setState(CollectingOffers);
    }
}

SelectionPolicy* Agent::getSelectionPolicy()
{
    return mSelectionPolicy;
}

void Agent::setCoalition(int co)
{
    mCoalition = co;
}

void Agent:: setId(int id)
{
    mAgentId=id;
}

void Agent::setPartyId(int pId)
{
    mPartyId=pId;
}

int Agent:: getCoId()
{
    return mCoalition;
}

Agent:: ~Agent()
{
    delete mSelectionPolicy; mSelectionPolicy=nullptr;
}

Agent::Agent(const Agent& other): mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(other.mSelectionPolicy->cloneSPolicy()), mCoalition(other.mCoalition)
{
}

Agent::Agent(Agent&& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalition(other.mCoalition)
{
    other.mSelectionPolicy=nullptr;
}

Agent& Agent::operator=(const Agent& other) 
{
    if(this!=&other)
    {
        mAgentId=other.mAgentId;
        mPartyId=other.mPartyId;
        mCoalition=other.mCoalition;
        *mSelectionPolicy=(*(other.mSelectionPolicy));
    }
    return *this;
}

Agent& Agent::operator=(Agent&& other)
{
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mCoalition=other.mCoalition;
    delete mSelectionPolicy;
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy=nullptr;
    return *this;
}

    

