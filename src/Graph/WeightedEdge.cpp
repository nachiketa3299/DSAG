#include "DSAG/Graph/WeightedEdge.hpp"

namespace DSAG {

bool WeightedEdge::operator==(const WeightedEdge &oth) const {
  return head == oth.head && tail == oth.tail && weight == oth.weight;
}

bool WeightedEdge::operator<(const WeightedEdge &oth) const {
  return weight < oth.weight;
}

}