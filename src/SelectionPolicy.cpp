#include "SelectionPolicy.h"

Party* MandatesSelectionPolicy::select(Simulation &sim, int partyId, Agent& agent)
{
    Graph g = sim.getGraph();
    vector<int> neighbours = g.getNeighbours(partyId);
    vector<int> relevantParties;
    for(int i : neighbours)
    {
        bool wasOffered = false;
        Party& curr = g.getParty(i);
        if(curr.getState() != State::Joined)
        {
            vector<Coalition> offers = curr.getOffers();
            for (Coalition& co : offers)
            {
                int coId=agent.getCoalition().getId();
                if( coId == co.getId())
                    wasOffered = true;
            }
            if(!wasOffered)
                relevantParties.push_back(curr.getId());
        }
    }
    Party* maxMandates=nullptr;
    int max=0;
    for(int p : relevantParties)
    {
        if(g.getMandates(p) > max)
        {
            max=g.getMandates(p);
            maxMandates=&g.getParty(p);
        }
    }
    return maxMandates;
}

int MandatesSelectionPolicy::checkSPolicy()
{
    return 2;
}

Party* EdgeWeightSelectionPolicy::select(Simulation &sim, int partyId, Agent& agent)
{
    Graph g = sim.getGraph();
    vector<int> neighbours = g.getNeighbours(partyId);
    vector<int> relevantParties;
    for(int i : neighbours)
    {
        bool wasOffered = false;
        Party& curr = g.getParty(i);
        if(curr.getState() != State::Joined)
        {
            vector<Coalition> offers = curr.getOffers();
            for (Coalition& co : offers)
            {
                int coId=agent.getCoalition().getId();
                if( coId == co.getId())
                    wasOffered = true;
            }
            if(!wasOffered)
                relevantParties.push_back(curr.getId());
        }
    }
    Party* maxEdgeWeight=nullptr;
    int max=0;
    for(int p : relevantParties)
    {
        if(g.getEdgeWeight(p,partyId) > max)
        {
            max=g.getEdgeWeight(p,partyId);
            maxEdgeWeight=&g.getParty(p);
        }
    }
    return maxEdgeWeight;
}

int EdgeWeightSelectionPolicy::checkSPolicy()
{
    return 3;
}
