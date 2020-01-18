#include "my_queue.h"

using namespace std;

MyQueue::MyQueue() {
  last = 0;
  first = 0;
}

MyQueue::~MyQueue() {
}

bool MyQueue::isEmpty() {
  if ((last - first) == 0) {
    return true;
  }
  return false;
}

void MyQueue::enqueue(int element) {
  content[last] = element;
  ++last;
}

int MyQueue::dequeue() {
  int ret = content[first];
  ++first;
  return ret;
}

int MyQueue::size() {
  return last-first;
}
