#include "IntLeaf.hpp"

IntLeaf::IntLeaf(int value)
    :_value{value}
{}

IntLeaf::~IntLeaf()
{}

NodeKind IntLeaf::kind() const
{
    return NodeKind::INT;
}
std::string IntLeaf::print() const {return std::to_string(_value);}
int IntLeaf::data() const {return _value;}

NodePtr IntLeaf::make_ptr(int value)
{
    return std::make_unique<IntLeaf>(value);
}

