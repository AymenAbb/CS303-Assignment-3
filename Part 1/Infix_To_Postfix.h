#ifndef INFIX_TO_POSTFIX_H_
#define INFIX_TO_POSTFIX_H_
#endif
using namespace std;
#include "stack.h"
#include <string>

class Infix_To_Postfix {
public:
  string convert(const string &infix);

private:
  stackNS::stack<char> operator_stack;
  string postfix;
  void process_operator(char op);
  int precedence(char op) const;
  bool is_operator(char ch) const;
  static const string OPERATORS;
  static const int PRECEDENCE[];
  bool open_parentheses(char ch) const;
  bool closed_parentheses(char ch) const;
  static const string OPEN;
  static const string CLOSE;
};
