#pragma once
#include <string>

enum class CardType
{
    Monster,
    Spell,
    Trap
};

std::string to_string(CardType type)
{
    std::string name{};
    switch(type)
    {
        case CardType::Monster : name = "Monster"; break;
        case CardType::Spell : name = "Spell"; break;
        case CardType::Trap : name = "Trap"; break;
    }   
    return name;
}

class Card 
{
    public :
        Card(std::string id, CardType cardType)
            :_id{id}
            ,_cardType{cardType}
        {}

        Card(std::string id, std::string name, CardType cardType)
            :_id{id}
            ,_name{name}
            ,_cardType{cardType}
        {}

        std::string get_id() const
        {return _id;}

        std::string get_name() const
        {return _name;}

        CardType get_type() const
        {return _cardType;}

        std::string get_description() const
        {return _description;}

        void set_name(std::string name)
        {(*this)._name = name;}

        void set_description(std::string desc)
        {
            (*this)._old_desc = _description;
            (*this)._description = desc;
        }

        const std::string& get_symbol() const
        {return _symbol;}
    
    private :
        std::string _id;
        std::string _name;
        std::string _description;
        CardType _cardType;
        std::string _old_desc;

    protected :
        std::string _symbol;
};