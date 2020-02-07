#include "my_binary_tree.h"

using namespace std;

MyBinaryTree::MyBinaryTree(string root) {
  this->key = root;
  this->leftChild = nullptr;
  this->rightChild = nullptr;
}

MyBinaryTree::~MyBinaryTree(){
}

void MyBinaryTree::insertLeft(string newNode) {
  if (this->leftChild == nullptr) {
    this->leftChild = new MyBinaryTree(newNode);
  } else {
    MyBinaryTree *t = new MyBinaryTree(newNode);
    t->leftChild = this->leftChild;
    this->leftChild = t;
  }
}

void MyBinaryTree::insertRight(string newNode){
  if (this->rightChild == nullptr) {
    this->rightChild = new MyBinaryTree(newNode);
  } else {
    MyBinaryTree *t = new MyBinaryTree(newNode);
    t->rightChild = this->rightChild;
    this->rightChild = t;
  }
}

MyBinaryTree* MyBinaryTree::getRightChild() {
  return this->rightChild;
}

MyBinaryTree* MyBinaryTree::getLeftChild() {
  return this->leftChild;
}

void MyBinaryTree::setRootVal(string obj) {
  this->key = obj;
}

string MyBinaryTree:: getRootVal() {
  return this->key;
}
