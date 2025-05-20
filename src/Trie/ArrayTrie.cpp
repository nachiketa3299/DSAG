#include "DSAG/Trie/ArrayTrie.hpp" 

namespace DSAG {

void ArrayTrie::Insert(const std::string& word) {
  Node_* node{root_.get()};

  for (char c: word) {
    if (!node->children[c - 'A']) {
      node->children[c - 'A'] = std::make_unique<Node_>();
    }

    node = node->children[c - 'A'].get();
  }

  node->isEnd = true;
}

bool ArrayTrie::Search(const std::string& word) const {
  Node_* node{root_.get()};

  for (char c: word) {
    if (!node->children[c - 'A']) {
      return false;
    }

    node = node->children[c - 'A'].get();
  }

  return node->isEnd;
}

bool ArrayTrie::StartsWith(const std::string& prefix) const {
  Node_* node{root_.get()};

  for (char c: prefix) {
    if (!node->children[c - 'A']) {
      return false;
    }
    node = node->children[c - 'A'].get();
  }

  return true;
}

void ArrayTrie::Print() const {
  std::string current{};
  DFS(root_.get(), current);
}

void ArrayTrie::PrintTree(char delim) const {
  DFS_tree(root_.get(), delim, 0);
}

void ArrayTrie::DFS(const Node_* node, std::string& current) const {
  if (node->isEnd) {
    std::cout << current << '\n';
  }

  for (size_t i = 0; i < node->children.size(); ++i) {
    if (!node->children[i]) {
      continue;
    }
    
    current.push_back(static_cast<char>(i + 'A'));
    DFS(node->children[i].get(), current);
    current.pop_back();
  }
}

void ArrayTrie::DFS_tree(const Node_* node, char delim, int indentLevel) const {
  for (size_t i = 0; i < node->children.size(); ++i) {
    if (!node->children[i]) {
      continue;
    }

    for (size_t j = 0; j < indentLevel; ++j) {
      std::cout << delim;
    }
    std::cout << static_cast<char>(i + 'A') << '\n';
    DFS_tree(node->children[i].get(), delim, indentLevel + 1);
  }
}

}