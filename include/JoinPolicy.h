#pragma once



class Party;
class Simulation;

class JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s) = 0;
    virtual JoinPolicy* clonePolicy()=0;
    virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
    JoinPolicy* clonePolicy() override ;
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
    JoinPolicy* clonePolicy() override;
};