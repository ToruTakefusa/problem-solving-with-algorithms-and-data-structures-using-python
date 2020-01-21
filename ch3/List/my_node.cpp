#include "my_node.h"

using namespace std;

MyNode::MyNode(int data) {
  this->data = data;
  this->next = nullptr;
}

int MyNode::getData() {
  return this->data;
}

MyNode* MyNode::getNext() {
  return this->next;
}

void MyNode::setData(int data) {
  this->data = data;
}

void MyNode::setNext(MyNode* next) {
  this->next = next;
}
