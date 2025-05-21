#include <gtest/gtest.h>
#include <DSAG/DisjointSet/DisjointSet.hpp>

using namespace DSAG;

TEST(DisjointSetTest, Initialization) {
    DisjointSet ds(5);
    for (std::size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(ds.Find(i), i);
    }
}

TEST(DisjointSetTest, UniteAndFind) {
    DisjointSet ds(5);

    ds.UniteSets(0, 1);
    EXPECT_EQ(ds.Find(0), ds.Find(1));

    ds.UniteSets(2, 3);
    ds.UniteSets(3, 4);
    EXPECT_EQ(ds.Find(2), ds.Find(4));
    EXPECT_NE(ds.Find(0), ds.Find(2));
}

TEST(DisjointSetTest, IsSameSet) {
    DisjointSet ds(6);

    EXPECT_FALSE(ds.IsSameSet(0, 5));
    ds.UniteSets(0, 5);
    EXPECT_TRUE(ds.IsSameSet(0, 5));

    ds.UniteSets(1, 2);
    ds.UniteSets(2, 3);
    EXPECT_TRUE(ds.IsSameSet(1, 3));
    EXPECT_FALSE(ds.IsSameSet(0, 3));
}

TEST(DisjointSetTest, TransitiveUnions) {
    DisjointSet ds(4);

    ds.UniteSets(0, 1);
    ds.UniteSets(1, 2);
    EXPECT_TRUE(ds.IsSameSet(0, 2));
    EXPECT_EQ(ds.Find(0), ds.Find(2));

    ds.UniteSets(2, 3);
    EXPECT_TRUE(ds.IsSameSet(0, 3));
}

