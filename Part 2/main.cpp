// This file contains the main source code
#include <iostream> // replit likes to forget this exists sometimes.

#include "queue.h"

#include <string>
using namespace combine;
using namespace std; // technically a bad idea but im using it for a simple assignment

int main() {
  int input;             // this is what the user types
  string userInput = ""; // this is what will be parsed

  Queue<std::string> queue;

  // menu
  cout << "What operation would you like to do to the queue?" << endl;
  cout << "  1 - push to front" << endl;
  cout << "  2 - pop from front" << endl;
  cout << "  3 - return front element" << endl;
  cout << "  4 - check if the queue is empty" << endl;
  cout << "  5 - return size" << endl;
  cout << "  6 - quit" << endl << endl;

  // while not quit
  while (true) {
    cout << "> ";
    cin >> input;
    cout << endl;

    // I keep trying a != 6 while loop but it never works
    // A switch statement also broke looping?
    if (input == 6) {
      break;
    }
    // push
    else if (input == 1) {
      cout << "What would you like to add to the queue? ";
      cin >> userInput;
      queue.push(userInput);
      queue.printQueue();
    }

    // pop
    else if (input == 2) {
      cout << "Removed " << queue.pop() << "\n\n";
      queue.printQueue();
    }

    // front
    else if (input == 3) {
      cout << "Front element: " << queue.front() << "\n\n";
      queue.printQueue();
    }

    // empty
    else if (input == 4) {
      if (queue.empty()) {
        cout << "The queue is empty" << endl;
      } else {
        cout << "The queue is not empty" << endl;
      }
      queue.printQueue();
    }

    // size
    else if (input == 5) {
      cout << "Size: " << queue.size() << endl;
      queue.printQueue();
    }
  }
}