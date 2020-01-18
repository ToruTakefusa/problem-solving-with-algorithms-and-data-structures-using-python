#include "my_stack.h"

using namespace std;
const static int SIZE = 10;

MyStack::MyStack() {
  content = new int[SIZE];
  actualSize = 0;
  maxSize = SIZE;
}
MyStack::~MyStack() {
  delete content;
}

bool MyStack::isEmpty() {
  if (actualSize == 0) {
    return true;
  }
  return false;
}

void MyStack::push(int element) {
  if (actualSize == maxSize) {
    int tmp[maxSize];
    for (int i = 0; i < maxSize; ++i) {
      tmp[i] = content[i];
    }
    maxSize = maxSize + SIZE;
    delete [] content;
    content = new int[maxSize];

    for (int i = 0; i < maxSize - SIZE; ++i) {
      content[i] = tmp[i];
    }
  }
    content[actualSize] = element;
    actualSize++;
}

int MyStack::pop() {
  int ret = content[actualSize - 1];
  actualSize--;
  return ret;
}

int MyStack::peek() {
  return content[actualSize - 1];
}

int MyStack::size() {
  return actualSize;
}
