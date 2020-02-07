#include "my_sequential_search.h"

bool sequentialSearch(std::list<int> alist, int item) {
  for (auto itr = alist.begin(); itr != alist.end(); itr++) {
    if (*itr == item) return true;
  }
  return false;
}

bool orderedSequentialSearch(std::list<int> alist, int item) {
  for (auto itr = alist.begin(); itr != alist.end(); itr++) {
    if (*itr > item) return false;
    if (*itr == item) return true;
  }
  return false;
}
