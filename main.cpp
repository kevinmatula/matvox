#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  // I believe this line is needed to clear the screen.
  cout << "\033[2J\033[H" << endl;
  const int SQUARELEN = 10;
  for (int i = 0; i < SQUARELEN; i++) {
    for (int j = 0; j < SQUARELEN; j++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
