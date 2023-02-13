#pragma once

#include "Pokemon.h"

#include <memory>

// A ball where a Pokemon sleeps.
class Pokeball
{
public:
    bool empty() const;

    const Pokemon& pokemon() const;

    void store(PokemonPtr pokemon);

    PokemonPtr steal();

private:
    PokemonPtr _pokemon;
};

