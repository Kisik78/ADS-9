// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <cassert>

template <typename T>
  class BST {
   public:
    struct Vertex {
      T value;
      int uni;
      Vertex* left;
      Vertex* right;
    };
 
   private:
    Vertex* root;
    Vertex* addVertex(Vertex* root, T value) {
      if (root == nullptr) {
        root = new Vertex;
        root->value = value;
        root->uni = 1;
        root->left = root->right = nullptr;
      } else if (root->value > value) {
        root->left = addVertex(root->left, value);
      } else if (root->value < value) {
        root->right = addVertex(root->right, value);
      } else {
        root->uni++;
      }
      return root;
    }
    int deepTree(Vertex* root) {
      if (root == nullptr)
        return 0;
      if (root->left == nullptr && root->right == nullptr)
        return 0;
      int but = deepTree(root->left), lut = deepTree(root->right);
      return (but > lut ? but : lut) + 1;
    }
    int searchNode(Vertex* root, T value) {
      if (root == nullptr)
        return 0;
      else if (root->value > value)
        return searchNode(root->left, value);
      else if (root->value < value)
        return searchNode(root->right, value);
      else
        return root->uni;
    }

   public:
    BST() :root(nullptr) {}
    ~BST() {}
    void add(T value) {
      root = addVertex(root, value);
    }
    int deep() {
      return deepTree(root);
    }
    int search(T value) {
      return searchVertex(root, value);
    }
  };

#endif  // INCLUDE_BST_H_
