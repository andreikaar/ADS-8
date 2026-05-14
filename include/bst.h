// Copyright 2025 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <string>
#include <vector>
#include <algorithm>

template<typename T>
class BST {
 public:
  struct Node {
    T value;
    int count;
    Node *left, *right;
    Node(T val) : value(val), count(1), left(nullptr), right(nullptr) {}
  };

 private:
  Node* root;

  Node* addNode(Node* node, T value) {
    if (!node) return new Node(value);
    if (value == node->value) {
      node->count++;
    } else if (value < node->value) {
      node->left = addNode(node->left, value);
    } else {
      node->right = addNode(node->right, value);
    }
    return node;
  }

  int getDepth(Node* node) {
    if (!node) return 0;
    return std::max(getDepth(node->left), getDepth(node->right)) + 1;
  }

  Node* searchNode(Node* node, T value) {
    if (!node || node->value == value) return node;
    if (value < node->value) return searchNode(node->left, value);
    return searchNode(node->right, value);
  }

  void collectNodes(Node* node, std::vector<Node*>& nodes) {
    if (!node) return;
    nodes.push_back(node);
    collectNodes(node->left, nodes);
    collectNodes(node->right, nodes);
  }

 public:
  BST() : root(nullptr) {}
  void add(T value) { root = addNode(root, value); }
  int depth() { return root ? getDepth(root) - 1 : 0; }
  bool search(T value) { return searchNode(root, value) != nullptr; }
  
  // Для Задания №3
  std::vector<Node*> getNodes() {
    std::vector<Node*> nodes;
    collectNodes(root, nodes);
    return nodes;
  }
};

#endif  // INCLUDE_BST_H_
