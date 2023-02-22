#include "ObjectNode.hpp"

ObjectNode::ObjectNode()
    {}

ObjectNode::~ObjectNode()
{}

NodeKind ObjectNode::kind() const
{
    return NodeKind::OBJECT;
}
std::string ObjectNode::print() const {return "{}";}

NodePtr ObjectNode::make_ptr()
{
    return std::make_unique<ObjectNode>();
}