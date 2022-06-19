
#include <functional>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/Vampire.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Exception.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <cstdio>
#include <fstream>
#include <cstring>
#include <map>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::fstream;
using std::istringstream;
using std::vector;
using namespace std;


/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       General Helper Functions          ------------------------------


/* ---------------------------------------------------------------------------------------------- */
// --------------------------------       Main function          ------------------------------

int main(){
    
    std::map<string, std::shared_ptr<Card>>myMap;

    myMap["Goblin"] = std::shared_ptr<Card>(new Goblin());

    std::shared_ptr<Card> ptr(myMap["Goblin"]);
    std::shared_ptr<Card> ptr2(new Goblin());
    std::shared_ptr<Card> ptr3(myMap["a"]);
    

    cout << *ptr << endl;
    cout << *ptr2 << endl;

    Rogue p1("Mike");

    ptr->applyEncounter(p1);

    cout << p1 << endl;

    return 0;
}
