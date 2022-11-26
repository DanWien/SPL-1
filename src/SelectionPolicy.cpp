#include "SelectionPolicy.h"
#include "Simulation.h"

int MandatesSelectionPolicy::select(Simulation &sim, int partyId, Agent& agent)
{
    Graph& g = sim.getGraph();
    vector<int> neighbours = g.getNeighbours(partyId);
    vector<int> relevantParties;
    for(int i : neighbours)
    {
        bool wasOffered = false;
        Party& curr = g.getParty(i);
        if(curr.getState() != State::Joined)
        {
            vector<int> offers = curr.getOffers();
            for (int id : offers)
            {
                int coId=agent.getCoId();
                if( coId == id)
                    wasOffered = true;
            }
            if(!wasOffered)
                relevantParties.push_back(curr.getId());
        }
    }
    int maxMandates = -1;
    int max=0;
    for(int p : relevantParties)
    {
        if(g.getMandates(p) > max)
        {
            max = g.getMandates(p);
            maxMandates = p;
        }
    }
    return maxMandates;
}

SelectionPolicy* MandatesSelectionPolicy:: cloneSPolicy() 
{
    return new MandatesSelectionPolicy();
}

int EdgeWeightSelectionPolicy::select(Simulation &sim, int partyId, Agent& agent)
{
    Graph &g = sim.getGraph();
    vector<int> neighbours = g.getNeighbours(partyId);
    vector<int> relevantParties;
    for(int i : neighbours)
    {
        bool wasOffered = false;
        Party& curr = g.getParty(i);
        if(curr.getState() != State::Joined)
        {
            vector<int> offers = curr.getOffers();
            for (int id : offers)
            {
                int coId= agent.getCoId();
                if(coId == id)
                    wasOffered = true;
            }
            if(!wasOffered)
                relevantParties.push_back(curr.getId());
        }
    }
    int maxEdgeWeight = -1;
    int max=0;
    for(int p : relevantParties)
    {
        if(g.getEdgeWeight(p,partyId) > max)
        {
            max=g.getEdgeWeight(p,partyId);
            maxEdgeWeight = p;
        }
    }
    return maxEdgeWeight;
}

SelectionPolicy* EdgeWeightSelectionPolicy:: cloneSPolicy() 
{
    return new EdgeWeightSelectionPolicy();
}
