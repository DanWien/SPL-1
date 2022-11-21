#pragma once
#include "Party.h"
#include "Coalition.h"
#include "Simulation.h"

class JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s) = 0;
    virtual int checkJPolicy()=0;
    virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
    virtual int checkJPolicy();
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
    virtual int checkJPolicy();
};