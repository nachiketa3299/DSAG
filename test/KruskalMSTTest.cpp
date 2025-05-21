#include <gtest/gtest.h>
#include "DSAG/Graph/KruskalMST.hpp"

using namespace DSAG;

TEST(KruskalMSTTest, BasicMSTComputation) {
  std::vector<WeightedEdge> edges {
    {0, 1, 1},
    {1, 2, 2},
    {0, 2, 3}
  };

  KruskalMST mst{3, edges};

  EXPECT_EQ(mst.GetTotalWeight(), 3);

  std::vector<WeightedEdge> expected {
    {0, 1, 1},
    {1, 2, 2}
  };

  auto mstEdges = mst.GetMSTEdges();
  ASSERT_EQ(mstEdges.size(), expected.size());

  for (const auto& edge : expected) {
    EXPECT_NE(std::find(mstEdges.begin(), mstEdges.end(), edge), mstEdges.end());
  }
}

TEST(KruskalMSTTest, DisconnectedGraph) {
  std::vector<WeightedEdge> edges {
    {0, 1, 1},
    {2, 3, 1}
  };

  KruskalMST mst{4, edges};

  EXPECT_EQ(mst.GetTotalWeight(), 2);

  std::vector<WeightedEdge> expected {
    {0, 1, 1},
    {2, 3, 1}
  };

  auto mstEdges = mst.GetMSTEdges();
  ASSERT_EQ(mstEdges.size(), expected.size());

  for (const auto& edge : expected) {
    EXPECT_NE(std::find(mstEdges.begin(), mstEdges.end(), edge), mstEdges.end());
  }
}

TEST(KruskalMSTTest, SingleNodeGraph) {
  std::vector<WeightedEdge> edges;  // 간선 없음

  KruskalMST mst{1, edges};

  EXPECT_EQ(mst.GetTotalWeight(), 0);
  EXPECT_TRUE(mst.GetMSTEdges().empty());
}
