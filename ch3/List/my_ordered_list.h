#ifndef _MY_ORDERED_LIST
#define _MY_ORDERED_LIST
#include "my_node.h"
class MyOrderedList {
 public:
  MyOrderedList();
  ~MyOrderedList();
  bool isEmpty();
  void add(int item);
  int length();
  bool search(int item);
  void remove(int item);
 private:
  MyNode *head;
};
#endif // _MY_ORDERED_LIST
