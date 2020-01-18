#ifndef _MYSTACK_H_
#define _MYSTACK_H_

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
  int *content;
  int actualSize;
  int maxSize;
};
#endif //_MYSTACK_H_
