#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for (int i = 0; i < c; i++) { //Setting loop to check every element before c (Making sure its not <= because if it is then i == c and return false)
      if ((q[i] == q[c])  || (c - i) == abs(q[c] - q[i]))
      	 return false;
    }
   return true;
}

//Print Function
void print(int q[]) { 
   static int numSolutions = 0; 
   cout << "Solution #" << ++numSolutions << ": ";
   for(int i = 0; i < 8; i++) {
   	cout << q[i];
   }
   cout << "\n";
}

void next(int q[], int c) {
   if (c == 8)
      print(q);
   else for (q[c] = 1; q[c] <= 8; ++q[c])
      if (ok(q, c))
         next(q, c+1);
}

int main() {
   int q[8];
   next(q, 0);
   return 0;
}

