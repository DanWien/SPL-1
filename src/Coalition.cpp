#include "Coalition.h"

Coalition::Coalition(vector<int> co, int mandates, int id) : coVector(co), numOfMandates(mandates), coId(id)
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

int Coalition:: getId()
{
    return coId;
}

Coalition:: ~Coalition() = default;


Coalition::Coalition(const Coalition& other): coVector(other.coVector), numOfMandates(other.numOfMandates), coId(other.coId)
{
    
}
Coalition::Coalition(Coalition&& other): coVector(other.coVector), numOfMandates(other.numOfMandates), coId(other.coId)
{

}
Coalition& Coalition::operator=(const Coalition& other)
{
    coVector=other.coVector;
    numOfMandates=other.numOfMandates;
    coId=other.coId;
    return *this;
}
Coalition& Coalition::operator=(Coalition&& other)
{
    coVector=std::move(other.coVector);
    numOfMandates=other.numOfMandates;
    coId=other.coId;
    return *this;
}

