#include "BattleCard.h"
#include "Card.h"
#include <vector>

using std::vector;

class Gang : public Card
{
    vector<shared_ptr<BattleCard>> m_cards;

public:
    Gang();

    void pushCard(shared_ptr<BattleCard> card);

    void Gang::applyEncounter(Player &player) const override;
};