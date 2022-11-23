#pragma once

#include <vector>
#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Coalition;
class Agent;
class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    Graph &getGraph();
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    const vector<vector<int>> getPartiesByCoalitions() const;
    int getNumOfCoalitions();
    vector<Agent> &getAgents();
    int getNumOfAgents();
    void addAgent();
    Coalition& getCoalition(int id);
    Agent& getAgent(int id);

private:
    Graph mGraph;
    vector<Agent> mAgents;
    int numOfCoalitions;
    vector<Coalition> mCoalitions;
    int numOfAgents;
};
