#include "Infix_To_Postfix.h"
#include <cctype>
#include <sstream>
using istringstream;
using string;


// Thanks to hallee for some of these function shenanigans
const string Infix_To_Postfix::OPEN = "([{";
const string Infix_To_Postfix::CLOSE = ")]}";
const string Infix_To_Postfix::OPERATORS = "+-*/%";
const int Infix_To_Postfix::PRECEDENCE[] = {1, 1, 2, 2, 2};

// based off of
// https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/#
// All functions without comments are self explanatory
string Infix_To_Postfix::convert(const string &infix) {
  postfix = "";
  // Stack error checking
  while (!operator_stack.empty()) {
    operator_stack.pop();
  }
  istringstream infix_tokens(infix);
  string next_token;
  while (infix_tokens >> next_token) {
    // add to postifx if in order
    if (isalnum(next_token[0])) {
      postfix += next_token;
      postfix += " ";
    }
    // Processes the operators and parenthesis
    else if (is_operator(next_token[0]) || open_parentheses(next_token[0]) ||
             closed_parentheses(next_token[0])) {
      process_operator(next_token[0]);
    }
  }
  // Clean up stack
  while (!operator_stack.empty()) {
    char op = operator_stack.top();
    operator_stack.pop();
    postfix += op;
    postfix += " ";
  }
  return postfix;
}

// all self explanatory
int Infix_To_Postfix::precedence(char op) const {
  return PRECEDENCE[OPERATORS.find(op)];
}

bool Infix_To_Postfix::is_operator(char ch) const {
  return (OPERATORS.find(ch) != string::npos);
}

bool Infix_To_Postfix::open_parentheses(char ch) const {
  return (OPEN.find(ch) != string::npos);
}

bool Infix_To_Postfix::closed_parentheses(char ch) const {
  return (CLOSE.find(ch) != string::npos);
}

// Function computes order of operations
void Infix_To_Postfix::process_operator(char op) {
  if (operator_stack.empty() || open_parentheses(op)) {
    operator_stack.push(op);
  } else {
    // add the operators to postfix
    while (!operator_stack.empty() && !open_parentheses(operator_stack.top()) &&
           (precedence(op) <= precedence(operator_stack.top()))) {
      postfix += operator_stack.top();
      postfix += " ";
      operator_stack.pop();
    }
    // Find closing parenthesis if there's an open
    if (closed_parentheses(op)) {
      while (!operator_stack.empty() &&
             !open_parentheses(operator_stack.top())) {
        postfix += operator_stack.top();
        postfix += " ";
        operator_stack.pop();
      }
      if (!operator_stack.empty() && open_parentheses(operator_stack.top())) {
        operator_stack.pop();
      } else {
        throw runtime_error("Open parenthesis detected");
      }
    } else {
      operator_stack.push(op);
    }
  }
}
