#include "DSAG/DisjointSet/DisjointSet.hpp"

namespace DSAG {

DisjointSet::DisjointSet(std::size_t size): parent_(size) {
  for (size_t i = 0; i < parent_.size(); ++i) {
    parent_[i] = i;
  }
}

std::size_t DisjointSet::Find(std::size_t i) {
  if (i == parent_[i]) {
    return i;
  }

  // 경로 최적화
  return parent_[i] = Find(parent_[i]);
}

bool DisjointSet::IsSameSet(std::size_t l, std::size_t r) {
  return Find(l) == Find(r);
}

void DisjointSet::UniteSets(std::size_t l, std::size_t r) {
  std::size_t pl{Find(l)}, pr{Find(r)};

  if (pl == pr) {
    return;
  }

  parent_[pr] = pl;
}

}