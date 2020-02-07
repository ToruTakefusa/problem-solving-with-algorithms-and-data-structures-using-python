#ifndef _MY_BINARY_HEAP_
#define _MY_BINARY_HEAP_
#include <vector>

class MyBinaryHeap {
 public:
  MyBinaryHeap();
  ~MyBinaryHeap();
  void insert(int k);
  int findMin();
  int delMin();
 private:
  std::vector<int> heapList;
  int currentSize;
  void percUp(int i);
  void percDown(int i);
  int minChild(int i);
};
#endif //_MY_BINARY_HEAP
