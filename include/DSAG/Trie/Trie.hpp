#pragma once 

#include "DSAG/Trie/ITrie.hpp"

#include <unordered_map>
#include <string>
#include <memory>

namespace DSAG {

class Trie: public ITrie {
private:
  struct Node_ {
    std::unordered_map<char, std::unique_ptr<Node_>> children;
    bool isEnd{false};
  };

public:
  Trie() = default;
  ~Trie() = default;

public:
  void Insert(const std::string& word) final;
  bool Search(const std::string& word) const final;
  bool StartsWith(const std::string& prefix) const final;
  void Print() const final;
  void PrintTree(char delim='-') const final;
  
private:
  void DFS(const Node_* node, std::string& current) const;
  void DFS_tree(const Node_* node, char delim, int indentLevel) const;

private:
  std::unique_ptr<Node_> root_{std::make_unique<Node_>()};
};

}
