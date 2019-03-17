// This code is based on Sabberstone project.
// Copyright (c) 2017-2018 SabberStone Team, darkfriend77 & rnilva
// Hearthstone++ is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2018 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#include <hspp/Actions/Generic.hpp>
#include <hspp/Commons/Constants.hpp>

namespace Hearthstonepp::Generic
{
void AddCardToHand(Player& player, Entity* entity)
{
    // Add card to graveyard if hand is full
    if (player.GetHand().IsFull())
    {
        player.GetGraveyard().AddCard(*entity);
        return;
    }

    // Add card to hand
    player.GetHand().AddCard(*entity);
}

void RemoveCardFromHand(Player& player, Entity* entity)
{
	// Remove card from hand
    player.GetHand().RemoveCard(*entity);
}

void ChangeManaCrystal(Player& player, int amount, bool fill)
{
    // Available and maximum mana are up to a maximum of 10
    if (player.maximumMana + amount > MANA_UPPER_LIMIT)
    {
        if (fill)
        {
            player.currentMana += (MANA_UPPER_LIMIT - player.maximumMana);
        }

        player.maximumMana = MANA_UPPER_LIMIT;
    }
    // Maximum mana are up to a minimum of 0
    else if (player.maximumMana + amount < 0)
    {
        player.maximumMana = 0;
    }
    else
    {
        if (fill)
        {
            player.currentMana += amount;
        }

        player.maximumMana += amount;
    }
}
}  // namespace Hearthstonepp::Generic