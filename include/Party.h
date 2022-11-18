#pragma once
#include <string>
#include <vector>

using std::vector;
using std::string;

class Coalition;
class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getTimer();
    void setTimer();
    JoinPolicy* getPoilcy();
    vector<Coalition> getOffers();
    void setOffers(Coalition& co);
    int getId();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int cdTimer;
    vector<Coalition> offers;
};
