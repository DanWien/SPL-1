#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), mCoalition (nullptr)
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
    Party* selected = p->select(sim,this->getPartyId(), *this);
    if(selected!=nullptr)
        selected->addOffer(this->getCoalition());
}

SelectionPolicy* Agent::getSelectionPolicy()
{
    return mSelectionPolicy;
}

void Agent::setCoalition(Coalition& co)
{
    mCoalition = &co;
}

Coalition& Agent::getCoalition() const
{
    return *mCoalition;
}

void Agent:: setId(int id)
{
    mAgentId=id;
}

void Agent::setPartyId(int pId)
{
    mPartyId=pId;
}

Agent:: ~Agent()
{
    if(mSelectionPolicy) 
        delete mSelectionPolicy;
}

Agent::Agent(const Agent& other): mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy(nullptr), mCoalition(other.mCoalition)
{
    int checkPolicy=other.mSelectionPolicy->checkSPolicy();
    if(checkPolicy==2)
        mSelectionPolicy=new MandatesSelectionPolicy;
    else mSelectionPolicy=new EdgeWeightSelectionPolicy;
}

Agent::Agent(Agent&& other):mAgentId(other.mAgentId),mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), mCoalition(other.mCoalition)
{
    other.mSelectionPolicy=nullptr;
}

Agent& Agent::operator=(const Agent& other) 
{
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mCoalition=other.mCoalition;
    *mSelectionPolicy=(*(other.mSelectionPolicy));
    return *this;
}

Agent& Agent::operator=(Agent&& other)
{
    mAgentId=other.mAgentId;
    mPartyId=other.mPartyId;
    mCoalition=other.mCoalition;
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    mSelectionPolicy=other.mSelectionPolicy;
    other.mSelectionPolicy=nullptr;
    return *this;
}
    

