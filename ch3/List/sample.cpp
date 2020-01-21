#include "my_unordered_list.h"
#include "my_ordered_list.h"
#include <iostream>

using namespace std;

int main() {
  MyUnorderedList list;
  list.add(31);
  list.add(77);
  list.add(17);
  list.add(93);
  list.add(25);
  list.add(54);
  cout << list.length() << endl;
  cout << boolalpha << list.search(1) << endl;
  cout << boolalpha << list.search(17) << endl;
  list.remove(54);
  cout << list.length() << endl;
  cout << boolalpha << list.search(54) << endl;
  list.remove(17);
  cout << list.length() << endl;
  cout << boolalpha << list.search(17) << endl;

  cout << "ordered list" << endl;
  MyOrderedList olist;
  olist.add(31);
  olist.add(77);
  olist.add(17);
  olist.add(93);
  olist.add(25);
  olist.add(54);
  cout << olist.length() << endl;
  cout << boolalpha << olist.search(1) << endl;
  cout << boolalpha << olist.search(17) << endl;
  olist.remove(54);
  cout << olist.length() << endl;
  cout << boolalpha << olist.search(54) << endl;
  olist.remove(17);
  cout << olist.length() << endl;
  cout << boolalpha << olist.search(17) << endl;
}
