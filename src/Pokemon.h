#pragma once

#include <memory>
#include <string>

class Trainer;

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string& name);

    Pokemon(const Pokemon& other);

    Pokemon& operator=(const Pokemon& other);

    const std::string& name() const;
    int id() const;

    const Trainer* trainer() const;

    void set_trainer(const Trainer& trainer);

private:
    static inline int next_id = 0;

    std::string    _name;
    int            _id      = 0;
    const Trainer* _trainer = nullptr;
};

using PokemonPtr = std::unique_ptr<Pokemon>;
