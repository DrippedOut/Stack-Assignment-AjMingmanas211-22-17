#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int match = 1;
  char c;

  int i,j;
  for (j = 1; j < argc; j++) {
    for (i = 0; i < strlen(argv[j]); i++) { 
      // open bracket [ { -> 'push'
      // close bracket ] } -> 'pop' & check
      switch (argv[j][i]) { 
      case '[':
      case '{':
        s.push(argv[j][i]);
        break;

      case ']':
        c = s.pop(); // c must b [ to match
        if (c != '[')
          match = 0;
        break;

      case '}':
        c = s.pop(); // c must b { to match
        if (c != '{')
          match = 0;
        break;

      default:
        break;
      }
    }
  }
  if (match == 0)
    cout << "Parentheses doesn't match" << endl;
  else if (s.Getsize() > 0)
    cout << "Too many open brackets" << endl; // too many open
  else
    cout << "Parentheses match" << endl;

  // clear stack
}