// Copyright 2025 NNTU-CS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename) {
  std::ifstream file(filename);
  if (!file) return;
  std::string word = "";
  char ch;
  while (file.get(ch)) {
    if (isalpha(static_cast<unsigned char>(ch))) {
      word += tolower(static_cast<unsigned char>(ch));
    } else if (!word.empty()) {
      tree.add(word);
      word = "";
    }
  }
  if (!word.empty()) tree.add(word);
  file.close();
}

void printFreq(BST<std::string>& tree) {
  auto nodes = tree.getNodes();
  std::sort(nodes.begin(), nodes.end(),
    [](BST<std::string>::Node* a, BST<std::string>::Node* b) {
    return a->count > b->count;
  });
  std::ofstream out("result/freq.txt");
  for (auto node : nodes) {
    if (out.is_open()) {
      out << node->value << " " << node->count << "\n";
    }
  }
}
