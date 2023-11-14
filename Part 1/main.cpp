#include "Infix_To_Postfix.h"
#include "functions.h"
#include "stack.h"
#include <iostream>
#include <vector>
using namespace std;

// functions self explanatory
int main() {
  string infix = "", postfix = "";
  Infix_To_Postfix infix_to_postfix;
  cout << "Input infix expression (Seperated by spaces): ";
  while (getline(cin, infix) && (infix != "")) {
    // while (infix != "q"){   // I dont know why this while statement breaks
    if (infix == "q") {
      break;
    }
    if (balanced(infix)) {
      cout << "Expression is balanced\n" << endl;
      postfix = infix_to_postfix.convert(infix);
      cout << postfix << endl << endl;
    } else {
      cout << "Expression is not balanced\n" << endl;
    }
    cout << "Enter next infix expression (q to quit): ";
    //}
  }
}