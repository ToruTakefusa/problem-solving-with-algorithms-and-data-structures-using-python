#include "my_queue.h"

using namespace std;

MyQueue::MyQueue() {
}

MyQueue::~MyQueue() {
}

bool MyQueue::isEmpty() {
  if (content.size() == 0) return true;
  return false;
}

void MyQueue::enqueue(int element) {
  content.push_back(element);
}

int MyQueue::dequeue() {
  int ret = content.front();
  content.pop_front();
  return ret;
}

int MyQueue::size() {
  return content.size();
}
