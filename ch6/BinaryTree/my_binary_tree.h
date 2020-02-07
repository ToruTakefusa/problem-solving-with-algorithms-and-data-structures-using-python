#ifndef _MY_BINARY_TREE_
#define _MY_BINARY_TREE_

#include <string>
class MyBinaryTree {
 public:
  MyBinaryTree(std::string root);
  ~MyBinaryTree();
  void insertLeft(std::string newNode);
  void insertRight(std::string newNode);
  MyBinaryTree* getRightChild();
  MyBinaryTree* getLeftChild();
  void setRootVal(std::string obj);
  std::string getRootVal();
 private:
  MyBinaryTree* leftChild;
  MyBinaryTree* rightChild;
  std::string key;
};
#endif //_MY_BINARY_TREE_
