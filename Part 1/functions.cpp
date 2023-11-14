#include "functions.h"

const string OPEN = "([{";
const string CLOSE = ")]}";

bool open(char ch) { return OPEN.find(ch) != string::npos; }
bool closed(char ch) { return CLOSE.find(ch) != string::npos; }

// Checks for balance
bool balanced(const string &expression) {
  // creates an empty stack
  stackNS::stack<char> s;
  bool balanced = true;
  string::const_iterator iter = expression.begin();
  while (balanced && (iter != expression.end())) {
    char next_ch = *iter;
    // checks if character is open parentheses and pushed onto the stack
    if (open(next_ch)) {
      s.push(next_ch);
    } else if (closed(next_ch)) {
      if (s.empty()) {
        balanced = false;
      } else {
        char top_ch = s.top();
        s.pop();
        // finds matching opening and closing parentheses
        balanced = (OPEN.find(top_ch) == CLOSE.find(next_ch));
      }
    }
    ++iter;
  }
  return balanced && s.empty();
}