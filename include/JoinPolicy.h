#pragma once
#include "Party.h"
#include "Coalition.h"
#include "Simulation.h"

class JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s) = 0;
};

class MandatesJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
};

class LastOfferJoinPolicy : public JoinPolicy 
{
public:
    virtual void join(Party& p, Simulation& s);
};