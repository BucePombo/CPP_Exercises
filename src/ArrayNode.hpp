#pragma once

#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"


class ArrayNode : public Leaf
{
private:
    /* data */
    //int _value;
    //NodeKind _kind;
public:
    ArrayNode();
    ~ArrayNode();
    //std::string data() const;
    NodeKind kind() const override;
    std::string print() const override;
    static NodePtr ArrayNode::make_ptr();
};


