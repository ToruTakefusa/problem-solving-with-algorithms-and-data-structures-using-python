#include "my_stack.h"
#include <iostream>
using namespace std;

int main() {
  MyStack myStack;
  cout << myStack.isEmpty() << endl;
  myStack.push(4);
  myStack.push(5);
  cout << myStack.peek() << endl;
  myStack.push(6);
  cout << myStack.size() << endl;
  cout << myStack.isEmpty() << endl;
  myStack.push(7);
  cout << myStack.pop() << endl;
  cout << myStack.pop() << endl;
  cout << myStack.size() << endl;
  myStack.push(8);
  myStack.push(9);
  myStack.push(10);
  myStack.push(11);
  myStack.push(12);
  myStack.push(13);
  myStack.push(14);
  myStack.push(15);
  myStack.push(16);
  myStack.push(17);
  myStack.push(18);
  myStack.push(19);
  myStack.push(20);
  cout << myStack.size() << endl;
  cout << myStack.peek() << endl;
}
