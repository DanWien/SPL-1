#include "JoinPolicy.h"
#include "Coalition.h"
#include "Simulation.h"

void MandatesJoinPolicy::join(Party& p, Simulation& s) 
{
    p.setState(State::Joined);
    vector<int> offers = p.getOffers();
    int max = 0;
    int coFinalId = -1;
    for(int coId: offers)
    {
        Coalition& currCo = s.getCoalition(coId);
        if(currCo.getMandates() > max)
        {
            max = currCo.getMandates();
            coFinalId = currCo.getId();
        }
    }
    Coalition& maxMandates = s.getCoalition(coFinalId);
    maxMandates.setMandates(maxMandates.getMandates()+p.getMandates());
    maxMandates.addParty(p.getId());
    Agent clone=Agent(s.getAgent(maxMandates.getId()));
    clone.setPartyId(p.getId());
    int x=s.getNumOfAgents();
    clone.setId(x);
    s.addAgent();
    s.getAgents().push_back(clone);

}

JoinPolicy* MandatesJoinPolicy:: clonePolicy() 
{
    return new MandatesJoinPolicy;
}

void LastOfferJoinPolicy::join(Party& p, Simulation& s) 
{
    p.setState(State::Joined);
    vector <int> offers = p.getOffers();
    Coalition& toJoin = s.getCoalition(offers.back());
    toJoin.setMandates(toJoin.getMandates()+p.getMandates());
    toJoin.addParty(p.getId());
    Agent clone=Agent(s.getAgent(toJoin.getId()));
    clone.setPartyId(p.getId());
    int x=s.getNumOfAgents();
    clone.setId(x);
    s.addAgent();
    s.getAgents().push_back(clone);
}

JoinPolicy* LastOfferJoinPolicy:: clonePolicy() 
{
    return new LastOfferJoinPolicy;
}