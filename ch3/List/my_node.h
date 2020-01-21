#ifndef _MY_NODE_
#define _MY_NODE_
class MyNode {
 public:
  MyNode(int data);
  int getData();
  MyNode* getNext();
  void setData(int data);
  void setNext(MyNode* next);
 private:
  int data;
  MyNode* next;
};
#endif // _MY_NODE_
