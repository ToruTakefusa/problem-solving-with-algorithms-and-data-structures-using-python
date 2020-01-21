#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_
#include <list>

class MyQueue {
 public:
  MyQueue();
  ~MyQueue();
  bool isEmpty();
  void enqueue(int element);
  int dequeue();
  int size();
 private:
  std::list<int> content;
};
#endif // _MY_QUEUE_H_
