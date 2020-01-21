#include "my_ordered_list.h"

using namespace std;

MyOrderedList::MyOrderedList() {
  this->head = nullptr;
}

MyOrderedList::~MyOrderedList(){
}

bool MyOrderedList::isEmpty() {
  if (this->head == nullptr) return true;
  return false;
}

void MyOrderedList::add(int item) {
  MyNode *current = this->head;
  MyNode *previous = nullptr;

  while(current != nullptr) {
    if ((current->getData() > item) || (current->getNext() == nullptr)) break;
    previous = current;
    current = current->getNext();
  }

  MyNode *temp = new MyNode(item);
  if (previous == nullptr) {
    temp->setNext(this->head);
    this->head = temp;
  } else {
    temp->setNext(current);
    previous->setNext(temp);
  }
}

int MyOrderedList::length() {
  MyNode *current = this->head;
  int count = 0;
  while(current != nullptr) {
    count++;
    if (current->getNext() == nullptr) break;
    current = current->getNext();
  }
  return count;
}

bool MyOrderedList::search(int item) {
  MyNode *current = this->head;

  while(current != nullptr) {
    int value = current->getData();
    if (value > item) break;
    if (value == item) return true;
    if (current->getNext() == nullptr) break;
    current = current->getNext();
  }
  return false;
}

void MyOrderedList::remove(int item) {
  MyNode *current = this->head;
  MyNode *previous = nullptr;

  while(current != nullptr) {
    int value = current->getData();
    if (value > item) return;
    if (value == item) break;
    if (current -> getNext() == nullptr) break;
    previous = current;
    current = current->getNext();
  }

  if (previous == nullptr) {
    this->head = current->getNext();
  } else {
    previous->setNext(current->getNext());
  }
  delete current;
}
