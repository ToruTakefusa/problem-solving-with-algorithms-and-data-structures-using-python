#include "my_stack.h"

using namespace std;
const static int SIZE = 10;

MyStack::MyStack() {
}
MyStack::~MyStack() {
}

bool MyStack::isEmpty() {
  if (content.size() == 0) return true;
  return false;
}

void MyStack::push(int element) {
  content.push_front(element);
}

int MyStack::pop() {
  int value = peek();
  content.pop_front();
  return value;
}

int MyStack::peek() {
  return content.front();
}

int MyStack::size() {
  return content.size();
}
