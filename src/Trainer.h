#pragma once

#include "PC.h"
#include "Pokeball.h"
#include "Pokedex.h"

#include <array>
#include <memory>
#include <string>
#include <utility>

// A person that captures Pokemons and makes them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc);

    const std::string& name() const;

    const std::array<Pokeball, 6>& pokeballs() const;

    void capture(PokemonPtr pokemon);

    void store_in_pc(size_t index);

    void fetch_from_pc(const std::string& name);

    const Pokedex& pokedex() const;

private:
    std::string _name;
    PC&         _pc;
    Pokedex     _pokedex;

    std::array<Pokeball, 6> _pokeballs;
};