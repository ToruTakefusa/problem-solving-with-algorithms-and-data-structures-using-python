#include <iostream>
#include "my_hash_table.h"

using namespace std;

int main() {
  MyHashTable h;
  h.insert(54, "cat");
  h.insert(26, "dog");
  h.insert(93, "lion");
  h.insert(17, "tiger");
  h.insert(77, "bird");
  h.insert(31, "cow");
  h.insert(44, "goat");
  h.insert(55, "pig");
  cout << h.find(17) << endl;
  h.insert(20, "chicken");
  h.insert(20, "duck");
  cout << h.find(20) << endl;
  cout << h.find(99) << endl;
}
