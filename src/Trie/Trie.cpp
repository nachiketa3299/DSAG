#include "DSAG/Trie/Trie.hpp"

namespace DSAG {

void Trie::Insert(const std::string& word) {
  Node_* node{root_.get()};

  for (char c: word) {
    if (node->children.find(c) == node->children.cend()) {
      node->children[c] = std::make_unique<Node_>();
    }

    node = node->children[c].get();
  }

  node->isEnd = true;
}

bool Trie::Search(const std::string& word) const {
  Node_* node{root_.get()};

  for (char c: word) {
    if (node->children.find(c) == node->children.cend()) {
      return false;
    }

    node = node->children[c].get();
  }

  return node->isEnd;
}

bool Trie::StartsWith(const std::string& prefix) const {
  Node_* node{root_.get()};

  for (char c: prefix) {
    if (node->children.find(c) == node->children.cend()) {
      return false;
    }
    node = node->children[c].get();
  }

  return true;
}

void Trie::Print() const {
  std::string current{};
  DFS(root_.get(), current);
}

void Trie::PrintTree(char delim) const {
  DFS_tree(root_.get(), delim, 0);
}

void Trie::DFS(const Node_ *node, std::string& current) const {
  if (node->isEnd) {
    std::cout << current << '\n';
  }

  for (const auto& [ch, child]: node->children) {
    current.push_back(ch);
    DFS(child.get(), current);
    current.pop_back();
  }
}

void Trie::DFS_tree(const Node_ *node, char delim, int indentLevel) const {
  for (const auto& [ch, child]: node->children) {
    for (int i = 0; i < indentLevel; ++i) {
      std::cout << delim;
    }
    std::cout << ch << '\n';
    DFS_tree(child.get(), delim, indentLevel + 1);
  }
}

}