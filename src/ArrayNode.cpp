#include "ArrayNode.hpp"

ArrayNode::ArrayNode()
    {}

ArrayNode::~ArrayNode()
{}

NodeKind ArrayNode::kind() const
{
    return NodeKind::ARRAY;
}
std::string ArrayNode::print() const {return "[]";}
NodePtr ArrayNode::make_ptr()
{
    return std::make_unique<ArrayNode>();
}
//std::string ArrayNode::data() const {return "[]";}