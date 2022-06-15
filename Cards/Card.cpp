#include <iostream>
#include "Card.h"

using std::cout;
using std::endl;

#define WIN true
#define LOSE false

const char* DIVIDER  = "------------------------";

Card::Card(std::string name):
    m_name(name)
{}


std::string Card::getName() const 
{
    return this->m_name;
}

void Card::printCard(std::ostream &os, Card &card)
{
    printCardDetails(os, card.m_name);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, Card &card)
{
    card.printCard(os, card);
    return os;
}