#include "my_binary_search.h"

using namespace std;

bool binarySearch(std::vector<int> alist, int item) {
  int first = 0;
  int last = alist.size();
  int middle = 0;

  while(first <= last) {
    middle = (first + last) / 2;

    if (alist[middle] == item) return true;
    if (alist[middle] < item) {
      first = middle + 1;
    } else {
      last = middle - 1;
    }
  }

  return false;
}
