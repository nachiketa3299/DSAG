#pragma once

#include "DSAG/Graph/WeightedEdge.hpp"
#include "DSAG/DisjointSet/DisjointSet.hpp"

#include <vector>

namespace DSAG {

class KruskalMST {
public:
  KruskalMST(int vSize, const std::vector<WeightedEdge>& edges);

public:
  const std::vector<WeightedEdge>& GetMSTEdges() const;
  int GetTotalWeight() const;

private:
  std::vector<WeightedEdge> edges_;
  DisjointSet uf_;

  std::vector<WeightedEdge> mstEdges_;
  int w_{0};
};

}