#include "JoinPolicy.h"

void MandatesJoinPolicy::join(Party& p, Simulation& s) 
{
    p.setState(State::Joined);
    vector<Coalition> offers = p.getOffers();
    Coalition* maxMandates = &offers.front();
    for(Coalition& co: offers)
    {
        if(co.getMandates() > maxMandates->getMandates())
            maxMandates = &co;
    }
    maxMandates->setMandates(maxMandates->getMandates()+p.getMandates());
    maxMandates->addParty(p.getId());
    Agent clone=Agent(maxMandates->getAgent());
    clone.setPartyId(p.getId());
    int x=s.getNumOfAgents();
    clone.setId(x-1);
    s.addAgent();
    s.getAgents().push_back(clone);

}

int MandatesJoinPolicy::checkJPolicy()
{
    return 2;
}

void LastOfferJoinPolicy::join(Party& p, Simulation& s) 
{
    p.setState(State::Joined);
    vector<Coalition> offers = p.getOffers();
    Coalition* toJoin=&offers.back();
    toJoin->setMandates(toJoin->getMandates()+p.getMandates());
    toJoin->addParty(p.getId());
    Agent clone=Agent(toJoin->getAgent());
    clone.setPartyId(p.getId());
    int x=s.getNumOfAgents();
    clone.setId(x-1);
    s.addAgent();
    s.getAgents().push_back(clone);
}

int LastOfferJoinPolicy::checkJPolicy()
{
    return 3;
}