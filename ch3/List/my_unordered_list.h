#ifndef _MY_UNORDERED_LIST
#define _MY_UNORDERED_LIST
#include "my_node.h"
class MyUnorderedList {
 public:
  MyUnorderedList();
  ~MyUnorderedList();
  bool isEmpty();
  void add(int item);
  int length();
  bool search(int item);
  void remove(int item);
 private:
  MyNode *head;
};
#endif // _MY_UNORDERED_LIST
