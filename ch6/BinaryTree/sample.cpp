#include "my_binary_tree.h"
#include "my_binary_heap.h"
#include <iostream>

using namespace std;

int main() {
  cout << "MyBinaryTree" << endl;
  MyBinaryTree r = MyBinaryTree("a");
  cout << r.getRootVal() << endl;
  cout << boolalpha << (r.getLeftChild() == nullptr) << endl;
  r.insertLeft("b");
  cout << r.getLeftChild()->getRootVal() << endl;
  r.insertRight("C");
  cout << r.getRightChild()->getRootVal() << endl;
  r.getRightChild()->setRootVal("hello");
  cout << r.getRightChild()->getRootVal() << endl;

  cout << 1/2 << endl;
  cout << "MyBinaryHeap" << endl;
  MyBinaryHeap h = MyBinaryHeap();
  h.insert(7);
  h.insert(10);
  h.insert(5);
  h.insert(-10);
  cout << h.findMin() << endl;
  cout << h.delMin() << endl;
  cout << h.findMin() << endl;
}
