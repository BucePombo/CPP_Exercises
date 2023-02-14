#pragma once
#include <string>
#include "Card.hpp"

enum class TrapType
{
    Normal, Continuous, Counter
};

std::string to_string(TrapType trap)
{
    std::string name{};
    switch(trap)
    {
        case TrapType::Normal : name = "Normal"; break;
        case TrapType::Continuous : name = "Continuous"; break;
        case TrapType::Counter : name = "Counter"; break;
    }
    return name;
}

class Trap : public Card
{
    public :
        Trap(std::string id, std::string name, TrapType trap)
        :Card{id, name, CardType::Trap}
        ,_trap_type{trap}
        {}

        TrapType get_trap_type()
        {
            return _trap_type;
        }

        const std::string get_symbol() const
        {
            return u8"罠";
        }

    private :
        TrapType _trap_type;
};

