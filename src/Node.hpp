#pragma once
#include <memory>
#include "NodeKind.hpp"

#include "InstanceCounter.hpp"

class Node : public InstanceCounter
{
    public :
        virtual NodeKind kind() const = 0;
        virtual std::string print() const = 0;
};

using NodePtr = std::unique_ptr<Node>;