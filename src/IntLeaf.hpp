#pragma once
#include <string>
#include "Leaf.hpp"
#include "NodeKind.hpp"


class IntLeaf : public Leaf
{
private:
    /* data */
    int _value;
    NodeKind _kind;
public:
    IntLeaf(int value);
    ~IntLeaf();
    virtual int data() const;
    NodeKind kind() const override;
    std::string print() const override;
    static NodePtr make_ptr(int value);
};

