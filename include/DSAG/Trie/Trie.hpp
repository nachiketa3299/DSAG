#pragma once 

#include "dsag/Trie/ITrie.hpp"

#include <string>
#include <unordered_map>
#include <map>
#include <memory>

namespace dsag {

struct TrieNode {
  std::unordered_map<char, std::unique_ptr<TrieNode>> children;
  bool isEnd{false};
};

struct OrderedTrieNode {
  std::map<char, std::unique_ptr<TrieNode>> children;
  bool isEnd{false};
};

template <class T>
class Trie: public ITrie {
public:
  Trie() = default;
  ~Trie() final = default;
public:
  void Insert(const std::string& word) final;
  bool Search(const std::string& word) const final;
  bool StartsWith(const std::string& prefix) const final;
  void PrintAll() const final;
  void PrintAllInTree(char delim='-') const final;

private:
  void DFS_string(const TrieNode* node, std::string& current) const;
  void DFS_delim(const TrieNode* node, char delim,  int indent) const;

private:
  std::unique_ptr<T> root_{std::make_unique<T>()};
};

}