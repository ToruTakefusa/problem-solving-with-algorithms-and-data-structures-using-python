#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

class MyQueue {
 public:
  MyQueue();
  ~MyQueue();
  bool isEmpty();
  void enqueue(int element);
  int dequeue();
  int size();
 private:
  int content[100];
  int last;
  int first;
};
#endif // _MY_QUEUE_H_
