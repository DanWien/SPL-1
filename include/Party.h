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
    virtual ~Party();
    Party(const Party& other);
    Party(Party&& other);
    Party& operator=(const Party& other);
    Party& operator=(Party&& other);

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getTimer();
    void setTimer();
    JoinPolicy* getPoilcy();
    vector<int> getOffers();
    void addOffer(int coId);
    int getId();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int cdTimer;
    vector<int> offers;
};
