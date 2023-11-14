#ifndef STACK_H_
#define STACK_H_
#include <vector>

// Thanks to Kevin for some of the stack implementation
// as well as https://www.geeksforgeeks.org/stack-in-cpp-stl/
namespace stackNS {
template <typename Item_Type> class stack {
public:
  stack();
  void push(const Item_Type &item);
  Item_Type &top();
  void pop();
  bool empty() const;
  std::size_t size() const;

private:
  std::vector<Item_Type> container;
};
#ifndef STACK_TC_
#define STACK_TC_

// Makes stack
template <typename Item_Type> stack<Item_Type>::stack() {}

// Pushes to stack
template <typename Item_Type>
void stack<Item_Type>::push(const Item_Type &item) {
  container.push_back(item);
}

// Pop front
template <typename Item_Type> void stack<Item_Type>::pop() {
  container.pop_back();
}

// Is empty?
template <typename Item_Type> bool stack<Item_Type>::empty() const {
  return container.empty();
}

// Returns top item
template <typename Item_Type> Item_Type &stack<Item_Type>::top() {
  return container.back();
}

// Returns items in stack
template <typename Item_Type> std::size_t stack<Item_Type>::size() const {
  return container.size();
}
#endif
} 
#endif