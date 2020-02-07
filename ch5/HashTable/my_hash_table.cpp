#include "my_hash_table.h"

using namespace std;

MyHashTable::MyHashTable() {
  for (int i = 0; i < SIZE; ++i) {
    slots[i] = -1;
    datum[i] = "";
  }
}

void MyHashTable::insert(int key, std::string data) {
  if (key == -1) return;
  int hash = hashFunction(key, SIZE);
  if ((slots[hash] == -1) || (slots[hash] == key)) {
    slots[hash] = key;
    datum[hash] = data;
    return;
  }

  int rehash = rehashFunction(hash, SIZE);
  while((slots[rehash] != -1) && (slots[rehash] != key)) {
    rehash = rehashFunction(rehash, SIZE);
    if (hash == rehash) exit(-1);
  }

  slots[hash] = key;
  datum[hash] = data;
  return;
}

std::string MyHashTable::find(int key) {
  int hash = hashFunction(key, SIZE);
  if (slots[hash] == key) return datum[hash];
  int rehash = rehashFunction(hash, SIZE);
  while(slots[rehash] != key) {
    rehash = rehashFunction(rehash, SIZE);
    if (hash == rehash) exit(-1);
  }
  return datum[rehash];
}

int MyHashTable::hashFunction(int key, int size) {
  return key % size;
}

int MyHashTable::rehashFunction(int oldHash, int size) {
  return (oldHash + 1) % size;
}
