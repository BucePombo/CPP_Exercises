#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class Board
{
    public :
        Board()
        {}
        bool put(std::unique_ptr<Card> ptr)
        {
            if(_board.capacity() <= 5)
            {
                _board.emplace_back(std::move(ptr));
                 return true;
            }
            return false;
        }

    private :
        std::vector<std::unique_ptr<Card>> _board;
};