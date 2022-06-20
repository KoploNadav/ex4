#include <memory>
#include "Gang.h"
#include "../utilities.h"

using std::shared_ptr;

Gang::Gang():
    Card("Gang"),
    m_cards()
{}

Gang::Gang(const Gang &other):
    Card("Gang"),
    m_cards(other.getCards())
{}

Gang& Gang::operator=(const Gang &other)
{
    this->m_cards = other.getCards();
}

void Gang::pushCard(shared_ptr<BattleCard> card)
{
    this->m_cards.push_back(card);
}

void Gang::applyEncounter(Player &player) const
{
    bool win = true;
    for(unsigned int i = 0; i < this->m_cards.size(); i++) {
        if(win) {
            if(player.getAttackStrength() >= this->m_cards[i]->getForce()){
                player.addCoins(this->m_cards[i]->getCoins());
            }
            else {
                win = false;
                player.damage(this->m_cards[i]->getDamage());
                player.buff(-(this->m_cards[i]->getDebuff()));
                printLossBattle(player.getName(), this->m_cards[i]->getName());
            }
        }
        else {
            printLossBattle(player.getName(), this->m_cards[i]->getName());
            player.damage(this->m_cards[i]->getDamage());
            player.buff(-(this->m_cards[i]->getDebuff()));
        }
    }
    if(win) {
        printWinBattle(player.getName(), this->getName());
        player.levelUp();
    }
}

vector<shared_ptr<BattleCard>> Gang::getCards() const
{
    return this->m_cards;
}