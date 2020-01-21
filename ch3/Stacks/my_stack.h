#ifndef _MYSTACK_H_
#define _MYSTACK_H_
#include <list>

class MyStack {
 public:
  MyStack();
  ~MyStack();
  bool isEmpty();
  void push(int element);
  int pop();
  int peek();
  int size();
 private:
  std::list<int> content;
};
#endif //_MYSTACK_H_
