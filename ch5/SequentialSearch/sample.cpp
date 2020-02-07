#include "my_sequential_search.h"
#include <iostream>

using namespace std;

int main() {
  list<int> alist;
  alist.push_back(1);
  alist.push_back(3);
  alist.push_back(10);
  alist.push_back(5);

  cout << boolalpha << sequentialSearch(alist, 3) << endl;
  cout << boolalpha << sequentialSearch(alist, 100) << endl;

  list<int> blist;
  blist.push_back(1);
  blist.push_back(3);
  blist.push_back(5);
  blist.push_back(10);
  blist.push_back(7);
  cout << "blist start" << endl;
  cout << boolalpha << orderedSequentialSearch(blist, 3) << endl;
  cout << boolalpha << orderedSequentialSearch(blist, 7) << endl;
  cout << boolalpha << orderedSequentialSearch(blist, 100) << endl;
}
