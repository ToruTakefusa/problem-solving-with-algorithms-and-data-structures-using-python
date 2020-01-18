#include "my_queue.h"
#include <iostream>

using namespace std;

int main() {
  MyQueue q;
  cout << boolalpha << q.isEmpty() << endl;
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  cout << q.size() << endl;
  cout << boolalpha << q.isEmpty() << endl;
  q.enqueue(7);
  cout << q.dequeue() << endl;
  cout << q.dequeue() << endl;
  cout << q.size() << endl;
  q.enqueue(8);
  q.enqueue(9);
  q.enqueue(10);
  q.enqueue(11);
  q.enqueue(12);
  q.enqueue(13);
  q.enqueue(14);
  q.enqueue(15);
  q.enqueue(16);
  q.enqueue(17);
  q.enqueue(18);
  q.enqueue(19);
  q.enqueue(20);
  cout << q.size() << endl;
}
