#include <map>
#include <memory>

#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Gang.h"

using std::map;
using std::shared_ptr;

map<string, shared_ptr<Card>> cardMap = 
{
    {"Barfight", shared_ptr<Card>(new Barfight())},
    {"Dragon", shared_ptr<Card>(new Dragon())},
    {"Fairy", shared_ptr<Card>(new Fairy())},
    //{"Gang", shared_ptr<Card>(new Gang())},
    {"Goblin", shared_ptr<Card>(new Goblin())},
    {"Merchant", shared_ptr<Card>(new Merchant())},
    {"Pitfall", shared_ptr<Card>(new Pitfall())},
    {"Treasure", shared_ptr<Card>(new Treasure())},
    {"Vampire", shared_ptr<Card>(new Vampire())}
};