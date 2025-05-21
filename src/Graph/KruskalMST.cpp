#include "DSAG/Graph/KruskalMST.hpp"
#include "DSAG/DisjointSet/DisjointSet.hpp"

namespace DSAG {

KruskalMST::KruskalMST(int vSize, const std::vector<WeightedEdge>& edges): uf_{vSize}, edges_(edges) {
  std::sort(edges_.begin(), edges_.end());

  for (const auto& [h, t, w]: edges_) {
    if (!uf_.IsSameSet(h, t)) {
      uf_.UniteSets(h, t);
      w_ += w;

      mstEdges_.push_back({h, t, w});
    }
  }
}

const std::vector<WeightedEdge>& KruskalMST::GetMSTEdges() const {
  return mstEdges_;
}

int KruskalMST::GetTotalWeight() const {
  return w_;
}

}
