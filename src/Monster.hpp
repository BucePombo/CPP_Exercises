#pragma once
#include <string>
#include "Card.hpp"

enum class Attribute
{
    Dark, Divine, Earth, Fire, Light, Water, Wind
};

std::string to_symbol(Attribute attribute)
{
    std::string name{};
    switch(attribute)
    {
        case Attribute::Dark : name = u8"闇"; break;
        case Attribute::Divine : name = u8"神"; break;
        case Attribute::Earth : name = u8"地"; break;
        case Attribute::Fire : name = u8"炎"; break;
        case Attribute::Light : name = u8"光"; break;
        case Attribute::Water : name = u8"水"; break;
        case Attribute::Wind : name = u8"風"; break;
    }
    return name;
}

class Monster : public Card
{
    public :
        Monster(std::string id, std::string name, Attribute attr, std::string desc, int atk, int def)
        :Card{id, name, CardType::Monster}
        ,_desc{desc}
        ,_attr{attr}
        ,_atk{atk}
        ,_def{def}
        {}

        std::string get_description() const
        {
            return "[" + _desc + "]\n" +
               Card::get_description() + "\n"
               "ATK/" + std::to_string(_atk) + " DEF/" + std::to_string(_def);
        }

        Attribute get_attribute() const
        {return _attr;}

        int get_atk() const
        {return _atk;}

        int get_def() const
        {return _def;}

        const std::string get_symbol() const
        {
            std::string name{};
            switch(_attr)
            {
                case Attribute::Dark : name = u8"闇"; break;
                case Attribute::Divine : name = u8"神"; break;
                case Attribute::Earth : name = u8"地"; break;
                case Attribute::Fire : name = u8"炎"; break;
                case Attribute::Light : name = u8"光"; break;
                case Attribute::Water : name = u8"水"; break;
                case Attribute::Wind : name = u8"風"; break;
            }
            return name;
        }


    private :
        std::string _desc;
        Attribute _attr;
        int _atk;
        int _def;
};
