#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  char c;
  int match;
  int i, j;
  for (j = 1; j < argc; j++) {
    match = 1;
    Stack s;
    for (i = 1; i < strlen(argv[j]); i++) {
      switch (argv[j][i]) {
      case '{':
      case '[':
        s.push(argv[j][i]);
        break;

      case '}':
        c = s.pop();
        if (c != '{')
          match = 0;
        break;

      case ']':
        c = s.pop();
        if (c != '{')
          match = 0;
        break;

      default:
        break;
      }
      if (match == 0)
        break;
    }
    if (match == 0)
      cout << "Parentheses Do Not Match" << endl;
    // else if () //too many open/close parentheses
    else if (s.get_size() > 0)
      cout << "Too many open parentheses" << endl;
    /*else if (s.get_size()==0)
      cout<< "Too many close parentheses"<< endl;*/
    else
      cout << "Parentheses Match" << endl;
  }
}