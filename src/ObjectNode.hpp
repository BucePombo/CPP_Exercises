#pragma once

#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"


class ObjectNode : public Leaf
{
private:
    /* data */
    //int _value;
    //NodeKind _kind;
public:
    ObjectNode();
    ~ObjectNode();
    //std::string data() const;
    NodeKind kind() const override;
    std::string print() const override;
    static NodePtr ObjectNode::make_ptr();
};
