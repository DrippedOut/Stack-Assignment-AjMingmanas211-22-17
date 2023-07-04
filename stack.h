#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
private:
  NodePtr top;
  int size;

public:
  Stack(NodePtr = NULL);
  ~Stack();
  char pop();
  void push(char);
  int Getsize();
};

Stack::Stack(NodePtr t) {
  if (t) {
    top = t;
    size = 1;
  } else {
    top = NULL;
    size = 0;
  }
}

void Stack::push(char x) {
  NodePtr new_node = new NODE(x); // 1
  if (new_node) {
    new_node->set_next(top); // 2
    top = new_node;          // 3
    ++size;                  // 4
  } else
    cout << "No memory left for new nodes" << endl;
  // Left missing for exercises…
}

char Stack::pop() {
  NodePtr t = top;
  char value; // return value
  if (t) {
    
    value = t->get_value();
    top = t->get_next();
    // Left missing for exercises
    delete t;
    --size;
    return value;
  }
  cout << "Empty stack" << endl;
  return 0;
}
  
Stack::~Stack(){
  cout << "Clearing all stacks" << endl;
  NodePtr t = top;
  for (int i = 0; i < size; i++) {
    top = top->get_next();
    delete t;
    t = top;
  }
  // while(size>0) pop();
}

int Stack::Getsize(){
  return size;
}

#endif