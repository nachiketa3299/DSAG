#pragma once

#include "DSAG/Trie/ITrie.hpp"

#include <array>
#include <memory>

namespace DSAG {

class ArrayTrie: public ITrie {
private:
  struct Node_ {
    std::array<std::unique_ptr<Node_>, 128> children;
    bool isEnd{false};
  };

public:
  ArrayTrie() = default;
  ~ArrayTrie() = default;

public:
  void Insert(const std::string& word) final;
  bool Search(const std::string& word) const final;
  bool StartsWith(const std::string& prefix) const final;

public:
  void Print() const final;
  void PrintTree(char delim='-') const final;

private:
  void DFS(const Node_ *node, std::string& current) const;
  void DFS_tree(const Node_ *node, char delim, int indentLevel) const;

private:
  std::unique_ptr<Node_> root_{std::make_unique<Node_>()};
};

}
