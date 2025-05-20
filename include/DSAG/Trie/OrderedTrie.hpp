#pragma once

#include "DSAG/Trie/ITrie.hpp"

#include <map>
#include <memory>
#include <string>

namespace DSAG {
class OrderedTrie: public ITrie {
private:
  struct Node_ {
    std::map<char, std::unique_ptr<Node_>> children;
    bool isEnd{false};
  };

public:
  OrderedTrie() = default;
  ~OrderedTrie() = default;

public:
  void Insert(const std::string& word) final;
  bool Search(const std::string& word) const final;
  bool StartsWith(const std::string& prefix) const final;
  void Print() const final;
  void PrintTree(char delim='-') const final;

private:
  void DFS(const Node_* node, std::string &current) const;
  void DFS_tree(const Node_* node, char delim, int indentLevel) const;

private:
  std::unique_ptr<Node_> root_{std::make_unique<Node_>()};
};
}