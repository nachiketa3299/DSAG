#include <gtest/gtest.h>

#include <DSAG/Trie/OrderedTrie.hpp>

using namespace DSAG;

TEST(OrderedTrieTest, InsertAndSearch) {
  OrderedTrie trie;

  trie.Insert("apple");
  EXPECT_TRUE(trie.Search("apple"));
  EXPECT_FALSE(trie.Search("app"));

  trie.Insert("app");
  EXPECT_TRUE(trie.Search("app"));
  EXPECT_TRUE(trie.Search("apple"));
  EXPECT_FALSE(trie.Search("banana"));
}

TEST(OrderedTrieTest, StartsWith) {
  OrderedTrie trie;

  trie.Insert("hello");
  trie.Insert("hell");
  trie.Insert("helicopter");

  EXPECT_TRUE(trie.StartsWith("he"));
  EXPECT_TRUE(trie.StartsWith("hell"));
  EXPECT_FALSE(trie.StartsWith("hex"));
  EXPECT_FALSE(trie.StartsWith("hero"));
}

TEST(OrderedTrieTest, EmptyOrderedTrie) {
  OrderedTrie trie;

  EXPECT_FALSE(trie.Search("anything"));
  EXPECT_FALSE(trie.StartsWith("a"));
}

TEST(OrderedTrieTest, PrefixVsWord) {
  OrderedTrie trie;
  trie.Insert("abc");

  EXPECT_TRUE(trie.StartsWith("ab"));
  EXPECT_TRUE(trie.Search("abc"));
  EXPECT_FALSE(trie.Search("ab"));
}

TEST(OrderedTrieTest, Print) {
  OrderedTrie trie;
  trie.Insert("ABC");
  trie.Insert("AB");
  trie.Insert("CAB");
  trie.Insert("ZAB");
  trie.Insert("CAA");
  trie.Print();
}

TEST(OrderedTrieTest, PrintTree) {
  OrderedTrie trie;
  trie.Insert("ABC");
  trie.Insert("AB");
  trie.Insert("CAB");
  trie.Insert("ZAB");
  trie.Insert("CAA");
  trie.PrintTree();
}
