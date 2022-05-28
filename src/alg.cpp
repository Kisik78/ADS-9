// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
BST<std::string> makeTree(const char* filename) {
  BST<std::string>tree;
  std::string word = "";
  char lc = 'a' - 'A';
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error!" << std::endl;
    return tr;
  }
  while (!file.eof()) {
    char mr = file.get();
    if ((mr >= 'a' && mr <= 'z') || (mr >= 'A' && mr <= 'Z')) {
      if (mr >= 'A' && mr <= 'Z')
        mr += lc;
      word += mr;
    } else if (word != "") {
      tr.add(word);
      word = "";
    }
  }
  file.close();
  return tr;
}
