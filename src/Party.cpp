#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    cdTimer = 3;
    offers;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(getState() == CollectingOffers)
    {
        setTimer();
        if(getTimer()==0)
            getPoilcy()->join(this,s);        
    }
}

int Party::getTimer()
{
    return cdTimer;
}

void Party::setTimer()
{
   cdTimer--;
}

JoinPolicy* Party::getPoilcy()
{
    return mJoinPolicy;
}

vector<Coalition> Party::getOffers()
{
    return offers;
}

void Party::setOffers(Coalition& co)
{
    offers.push_back(co);
}
