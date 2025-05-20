#include <gtest/gtest.h>

#include <DSAG/Trie/Trie.hpp>

using namespace DSAG;

TEST(TrieTest, InsertAndSearch) {
  Trie trie;

  trie.Insert("apple");
  EXPECT_TRUE(trie.Search("apple"));
  EXPECT_FALSE(trie.Search("app"));

  trie.Insert("app");
  EXPECT_TRUE(trie.Search("app"));
  EXPECT_TRUE(trie.Search("apple"));
  EXPECT_FALSE(trie.Search("banana"));
}

TEST(TrieTest, StartsWith) {
  Trie trie;

  trie.Insert("hello");
  trie.Insert("hell");
  trie.Insert("helicopter");

  EXPECT_TRUE(trie.StartsWith("he"));
  EXPECT_TRUE(trie.StartsWith("hell"));
  EXPECT_FALSE(trie.StartsWith("hex"));
  EXPECT_FALSE(trie.StartsWith("hero"));
}

TEST(TrieTest, EmptyTrie) {
  Trie trie;

  EXPECT_FALSE(trie.Search("anything"));
  EXPECT_FALSE(trie.StartsWith("a"));
}

TEST(TrieTest, PrefixVsWord) {
  Trie trie;
  trie.Insert("abc");

  EXPECT_TRUE(trie.StartsWith("ab"));
  EXPECT_TRUE(trie.Search("abc"));
  EXPECT_FALSE(trie.Search("ab"));
}

TEST(TrieTest, Print) {
  Trie trie;
  trie.Insert("ABC");
  trie.Insert("AB");
  trie.Insert("CAB");
  trie.Insert("ZAB");
  trie.Insert("CAA");
  trie.Print();
}

TEST(TrieTest, PrintTree) {
  Trie trie;
  trie.Insert("ABC");
  trie.Insert("AB");
  trie.Insert("CAB");
  trie.Insert("ZAB");
  trie.Insert("CAA");
  trie.PrintTree();
}
