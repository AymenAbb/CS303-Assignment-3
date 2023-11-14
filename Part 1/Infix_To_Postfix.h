#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_
#endif

#include "stack.h"
#include <string>

class Infix_To_Postfix {
public:
  std::string convert(const std::string &infix);

private:
  stackNS::stack<char> operator_stack;
  std::string postfix;
  void process_operator(char op);
  int precedence(char op) const;
  bool is_operator(char ch) const;
  static const std::string OPERATORS;
  static const int PRECEDENCE[];
  bool open_parentheses(char ch) const;
  bool closed_parentheses(char ch) const;
  static const std::string OPEN;
  static const std::string CLOSE;
};
