#include "Simulation.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), numOfCoalitions(0), mCoalitions{}, numOfAgents(0)
{
    for(Agent& agent: mAgents) 
    {
        std::vector<int> co;
        int id=agent.getPartyId();
        co.push_back(id);
        Coalition curr(co, mGraph.getParty(id).getMandates(), agent.getId() );    
        agent.setCoalition(agent.getId());
        mCoalitions.push_back(curr);
        numOfCoalitions++;
        numOfAgents++;
    }
}

void Simulation::step()
{
    if(!shouldTerminate()) 
    {
        for(int i=0; i<mGraph.getNumVertices(); i++)
        {
            Party& curr = mGraph.getParty(i);
            if(curr.getState()!=Joined)
                curr.step(*this);
        }
        for(Agent& agent: mAgents)
            agent.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    for(const Coalition& co : mCoalitions)
    {
        if(co.getMandates() >= 61)
            return true;
    }
    for(int i=0 ; i<mGraph.getNumVertices() ; i++)
    {
        Party curr = getParty(i);
        if(curr.getState() != Joined)
            return false;
    }
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph& Simulation::getGraph()
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

 Party &Simulation::getParty(int partyId) 
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> output;
    for(const Coalition& co : mCoalitions)
    {
        output.push_back(co.getCoalition());        
    }
    return output;
}

int Simulation::getNumOfCoalitions() 
{
    return numOfCoalitions;
}

vector<Agent> &Simulation:: getAgents()
{
    return mAgents;
}

int Simulation::getNumOfAgents()
{
    return numOfAgents;
}

void Simulation::addAgent()
{
    numOfAgents++;
}

Coalition& Simulation:: getCoalition(int id) 
{
    return this->mCoalitions[id];
}
Agent& Simulation::getAgent(int id)
{
    return mAgents[id];
}