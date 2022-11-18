#include "Agent.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    mCoalition = nullptr;
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
    Party selected = p->select();
    selected.setOffers(this->getCoalition());
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
