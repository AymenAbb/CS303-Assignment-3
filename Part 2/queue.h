#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
#include <iostream>
#include <list>

// fancy pancy container, help from hallee on it
namespace combine {
template <typename Item_Type> class Queue {
public:
  Queue();
  void push(const Item_Type &item);
  bool empty() const;
  size_t size() const;
  Item_Type pop();
  Item_Type &front();
  void printQueue();

private:
  list<Item_Type> container;
};

#ifndef QUEUE_TC_
#define QUEUE_TC_

// makes queue
template <typename Item_Type> Queue<Item_Type>::Queue() {}

// push top
template <typename Item_Type>
void Queue<Item_Type>::push(const Item_Type &item) {
  container.push_back(item);
}

// pop top
template <typename Item_Type> Item_Type Queue<Item_Type>::pop() {
  Item_Type front = this->front();
  container.pop_front();
  return front;
}

// return top
template <typename Item_Type> Item_Type &Queue<Item_Type>::front() {
  return container.front();
}

// empty?
template <typename Item_Type> bool Queue<Item_Type>::empty() const {
  return container.empty();
}

// size
template <typename Item_Type> size_t Queue<Item_Type>::size() const {
  return container.size();
}

// print
// https://stackoverflow.com/questions/15097778/why-do-c-stl-container-begin-and-end-functions-return-iterators-by-value-rathe
template <typename Item_Type> void Queue<Item_Type>::printQueue() {
  cout << "The current queue in order:" << endl << endl;
  for (auto it = this->container.begin(); it != this->container.end(); ++it) {
    cout << "   " << *it << endl << endl;
  }
}
#endif
}

#endif