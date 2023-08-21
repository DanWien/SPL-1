#include "Party.h"
#include "JoinPolicy.h"
#include "Coalition.h"
#include "Simulation.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) , cdTimer(3),offers{}
{
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
            getPoilcy()->join(*this,s);        
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

vector<int> Party::getOffers()
{
    return offers;
}

void Party::addOffer(int coId)
{
    offers.push_back(coId);
}

int Party::getId()
{
    return mId;
}

Party::~Party()
{
    delete mJoinPolicy; mJoinPolicy = nullptr;
}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clonePolicy()), mState(other.mState),cdTimer(other.cdTimer),offers(other.offers)
{   
}

Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), cdTimer(other.cdTimer),offers(other.offers)
{
    other.mJoinPolicy=nullptr;
}

Party& Party:: operator=(const Party& other)
{
    if(this!=&other)
    {
        mId=other.mId;
        mName=other.mMandates;
        mMandates=other.mMandates;
        mState=other.mState;
        cdTimer=other.cdTimer;
        offers=other.offers;
        *mJoinPolicy=(*(other.mJoinPolicy));
    }
    return *this;
}

Party& Party:: operator=(Party&& other)
{
    mId=other.mId;
    mName=other.mMandates;
    mMandates=other.mMandates;
    mState=other.mState;
    cdTimer=other.cdTimer;
    offers=std::move(other.offers);
    if(mJoinPolicy) delete mJoinPolicy;
    mJoinPolicy=other.mJoinPolicy;
    other.mJoinPolicy=nullptr;
    return *this;
}



