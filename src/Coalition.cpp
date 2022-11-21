#include "Coalition.h"

Coalition::Coalition(Agent& agent, vector<int> co, int mandates, int id) : ogAgent(agent), coVector(co), numOfMandates(mandates), coId(id)
{

}

bool Coalition::isFull()
{
    return getMandates()>=61;
}

int Coalition::getMandates() const
{
    return numOfMandates;
} 

vector<int> Coalition::getCoalition() const
{
    return coVector;
}

void Coalition::addParty(int partyId)
{
    coVector.push_back(partyId);
}
void Coalition::setMandates (int mandates)
{
    numOfMandates = mandates;
}
Agent& Coalition:: getAgent()
{
    return ogAgent;
}

int Coalition:: getId()
{
    return coId;
}

