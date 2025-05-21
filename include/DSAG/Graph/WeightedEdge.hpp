#pragma once

namespace DSAG {

struct WeightedEdge {
public:
  bool operator==(const WeightedEdge& oth) const;
  bool operator<(const WeightedEdge& oth) const;

public:
  int head{};
  int tail{};
  int weight{};
};

}