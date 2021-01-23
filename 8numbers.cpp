#include<iostream>
#include<cmath>
using namespace std;

bool test(int cross[], int x) { 
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	for(int i = 0; checkList[x][i] != -1; i++) { //Checking if the number with its respective array is conglicting 
		if(abs(cross[checkList[x][i]] - cross[x]) == 1 ) { 
			return false;
		} 
		for (int i = 0; i < x; i++) {
			if(cross[i] == cross[x]) {
				return false;
			}
		}
	}
	return true;
}

void print(int cross[], int cap) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}
int main() {
   int c = 0;
   int q[8] = {0}; 
   q[0] = 0; 
   while (c >= 0) { 
      c++;// Move to the next column
      if (c == 8) { //If we reached the end call on the print func for the solution
        print(q,c);
	    c-=1;
 } else { //if not move back and check the number placements till we get a solution
 	q[c] =- 1;
}
      while (c >= 0) {
      	q[c]++;
      	if(q[c] == 8) {
      		c--;
		} else {
        if ((test(q,c)) == true) //if the numbers are all good return true and break out of the checking loop 
         break;
     }
      }
   }
   return 0;
}
