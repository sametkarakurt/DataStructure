#include "AVLNode.hpp"

AVLNode::AVLNode(int queueLength)
{
    this->queueLength = queueLength;
    left=right=0;
}