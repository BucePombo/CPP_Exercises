#include "Pokeball.h"
    bool Pokeball::empty() const
    {
        return _pokemon == nullptr;
    }

    const Pokemon& Pokeball::pokemon() const
    {
        return *_pokemon;
    }

    void Pokeball::store(PokemonPtr pokemon)
    {
        _pokemon = std::move(pokemon);
    }

    PokemonPtr Pokeball::steal()
    {
        return std::move(_pokemon);
    }