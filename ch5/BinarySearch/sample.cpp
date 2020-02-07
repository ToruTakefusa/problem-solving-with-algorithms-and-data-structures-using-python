#include "my_binary_search.h"
#include <iostream>

using namespace std;

int main() {
  vector<int> alist;
  alist.push_back(1);
  cout << boolalpha << binarySearch(alist, 1) << endl;
  cout << boolalpha << binarySearch(alist, 100) << endl;
  alist.push_back(3);
  alist.push_back(5);
  alist.push_back(7);
  alist.push_back(9);
  alist.push_back(11);
  alist.push_back(13);
  cout << boolalpha << binarySearch(alist, 5) << endl;
  cout << boolalpha << binarySearch(alist, 1000) << endl;
}
