#include "my_binary_heap.h"

using namespace std;

MyBinaryHeap::MyBinaryHeap() {
  this->currentSize = 0;
  this->heapList.push_back(0);
}

MyBinaryHeap::~MyBinaryHeap() {
  
}

void MyBinaryHeap::insert(int k) {
  this->heapList.push_back(k);
  this->currentSize++;
  percUp(currentSize);
}

int MyBinaryHeap::findMin(){
  return this->heapList[1];
}

void MyBinaryHeap::percUp(int i) {
  while(i / 2 > 0) {
    if (this->heapList[i / 2] > this->heapList[i]) {
      int tmp = this->heapList[i];
      this->heapList[i] = this->heapList[i / 2];
      this->heapList[i / 2] = tmp;
    }
    i = i / 2;
  }
}

int MyBinaryHeap::delMin() {
  int ret = heapList[1];
  this->heapList[1] = this->heapList[this->currentSize];
  this->currentSize--;
  percDown(1);
  return ret;
}

void MyBinaryHeap::percDown(int i) {
  while(i * 2 <= this->currentSize) {
    int mc = minChild(i);
    if (this->heapList[i] > this->heapList[mc]) {
      int tmp = this->heapList[i];
      heapList[i] = heapList[mc];
      heapList[mc] = tmp;
    }
    i = mc;
  }
}

int MyBinaryHeap::minChild(int i) {
  int left = i * 2;
  int right = i * 2 + 1;
  if (this->currentSize < right) return left;
  if (this->heapList[left] < heapList[right]) return left;
  return right;
}
