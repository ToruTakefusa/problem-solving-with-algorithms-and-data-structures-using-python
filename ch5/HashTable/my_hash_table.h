#ifndef _MY_HASH_TABLE_
#define _MY_HASH_TABLE_

#include <string>

class MyHashTable{
 private:
  static const int SIZE = 11;
  int slots[SIZE];
  std::string datum[SIZE];
  int hashFunction(int key, int size);
  int rehashFunction(int oldHash, int size);
 public:
  MyHashTable();
  void insert(int key, std::string data);
  std::string find(int key);
};
#endif //_MY_HASH_TABLE_
