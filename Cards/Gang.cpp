#include <memory>
#include "Gang.h"
#include "../utilities.h"

using std::shared_ptr;

Gang::Gang():
    Card("Gang"),
    m_cards()
{}

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
                printWinBattle(player.getName(), this->m_cards[i]->getName());
            }
            else {
                win = false;
                player.damage(this->m_cards[i]->getDamage());
                player.buff(-(this->m_cards[i]->getDebuff()));
                printLossBattle(player.getName(), this->m_cards[i]->getName());
            }
        }
        else {
            if(!player.isKnockedOut()) {
                player.damage(this->m_cards[i]->getDamage());
                player.buff(-(this->m_cards[i]->getDebuff()));
            }
            break;
        }
    }
    if(win) {
        player.levelUp();
    }
}