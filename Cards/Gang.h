#include "BattleCard.h"
#include "Card.h"
#include <vector>
#include <memory>

using std::vector;
using std::shared_ptr;

class Gang : public Card
{
    vector<shared_ptr<BattleCard>> m_cards;

public:
    Gang();

    void pushCard(shared_ptr<BattleCard> card);

    Gang(const Gang& other);

    Gang& operator=(const Gang& other);

    ~Gang() = default;

    void applyEncounter(Player &player) const override;

    vector<shared_ptr<BattleCard>>& getCards() const;
};