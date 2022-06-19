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

map<string, Card*> cardMap = 
{
    {"Barfight", new Barfight()},
    {"Dragon", new Dragon()},
    {"Fairy", new Fairy()},
    {"Goblin", new Goblin()},
    {"Merchant", new Merchant()},
    {"Pitfall", new Pitfall()},
    {"Treasure", new Treasure()},
    {"Vampire", new Vampire()},
    {"Gang", new Gang()}
};