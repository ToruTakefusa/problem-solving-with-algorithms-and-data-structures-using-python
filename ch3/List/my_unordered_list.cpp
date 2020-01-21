#include "my_unordered_list.h"

using namespace std;

MyUnorderedList::MyUnorderedList() {
  this->head = nullptr;
}

MyUnorderedList::~MyUnorderedList() {
}

bool MyUnorderedList::isEmpty() {
  if (head == nullptr) return true;
  return false;
}

void MyUnorderedList::add(int item) {
  MyNode *temp = new MyNode(item);
  temp->setNext(this->head);
  this->head = temp;
}

int MyUnorderedList::length() {
  MyNode *current = this->head;
  int count = 0;
  while(current != nullptr) {
    count++;
    if (nullptr == (current->getNext())) break;
    current = current->getNext();
  }
  return count;
}

bool MyUnorderedList::search(int item) {
  MyNode *current = this->head;

  while(current != nullptr) {
    if (current->getData() == item) return true;
    if (nullptr == (current->getNext())) break;
    current = current->getNext();
  }
  return false;
}

void MyUnorderedList::remove(int item) {
  MyNode *current = this->head;
  MyNode *previous = nullptr;
  bool found = false;
  while(!found) {
    if(current->getData() == item) {
      found = true;
    } else {
      previous = current;
      if (current->getNext() == nullptr) return;
      current = current->getNext();
    }
  }

  if (!found) return;
  if (previous == nullptr) {
    this->head = current->getNext();
  } else {
    previous->setNext(current->getNext());
  }
  delete current;
}
