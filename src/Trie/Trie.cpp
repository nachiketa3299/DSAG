#include "dsag/Trie/Trie.hpp"

#include <string>
#include <memory>
#include <iostream>

namespace dsag {

void Trie::Insert(const std::string &word) {
  TrieNode* node{root_.get()};

  for (char c: word) {
    // 없으면 추가
    if (node->children.find(c) == node->children.cend()) {
      node->children[c] = std::make_unique<TrieNode>();
    }

    // 노드 갱신
    node = node->children[c].get();
  }

  node->isEnd = true;
}

bool Trie::Search(const std::string &word) const {
  TrieNode* node{root_.get()};

  for (char c: word) {
    auto it{node->children.find(c)};

    if (it == node->children.cend()) {
      return false;
    }

    node = it->second.get();
  }

  return node->isEnd;
}

bool Trie::StartsWith(const std::string &prefix) const {
  TrieNode* node{root_.get()};

  for (char c: prefix) {
    auto it{node->children.find(c)};

    if (it == node->children.cend()) {
      return false;
    }

    node = it->second.get();
  }

  return true;
}

void Trie::PrintAll() const {
  std::string current;
  DFS_string(root_.get(), current);
}

void Trie::PrintAllInTree(char delim) const {
  DFS_delim(root_.get(), delim, 0);
}

void Trie::DFS_string(const TrieNode* node, std::string& current) const {
  if (node->isEnd) {
    std::cout << current << '\n';
  }

  for (const auto& [ch, child]: node->children) {
    current.push_back(ch);
    DFS_string(child.get(), current);
    current.pop_back();
  }
}

void Trie::DFS_delim(const TrieNode* node, char delim, int indent) const {

  for (const auto& [ch, child]: node->children) {
    for (int i = 0; i < indent; ++i) {
      std::cout << delim;
    }
    std::cout << delim << '\n';
    DFS_delim(child.get(), delim, indent + 1);
  }
}

}
