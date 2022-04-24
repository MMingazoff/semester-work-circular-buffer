#include "node.hpp"

namespace itis {

  Node::Node(int value, Node *next) : value{value}, next{next} {}

}  // namespace itis