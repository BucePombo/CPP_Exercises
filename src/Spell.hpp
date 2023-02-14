#pragma once
#include <string>
#include "Card.hpp"

enum class SpellType
{
    Normal, Equip, Continuous, QuickPlay, Field
};

std::string to_string(SpellType spell)
{
    std::string name{};
    switch(spell)
    {
        case SpellType::Normal : name = "Normal"; break;
        case SpellType::Equip : name = "Equip"; break;
        case SpellType::Continuous : name = "Continuous"; break;
        case SpellType::QuickPlay : name = "Quick-Play"; break;
        case SpellType::Field : name = "Field"; break;
    }
    return name;
}

class Spell : public Card
{
    public :
        Spell(std::string id, std::string name, SpellType spell)
        :Card{id, name, CardType::Spell}
        ,_spell_type{spell}
        {}

        SpellType get_spell_type()
        {
            return _spell_type;
        }

        const std::string get_symbol() const
        {
            return u8"魔";
        }

    private :
        SpellType _spell_type;
};

