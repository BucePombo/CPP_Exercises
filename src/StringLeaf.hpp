#pragma once

#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"


class StringLeaf : public Leaf
{
private:
    /* data */
    std::string _value;
    NodeKind _kind;
public:
    StringLeaf(std::string value);
    ~StringLeaf();
    virtual std::string data() const;
    NodeKind kind() const override;
    std::string print() const override;
    static NodePtr make_ptr(std::string value);
};


