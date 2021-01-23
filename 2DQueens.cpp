#include <iostream>
using namespace std;

int main() {
      int q[8][8] = {};// Initialize the board to 0
      int r = 0, c = 0;
      q[r][c] = 1; // Place the first queen on the upper left corner 
      
nextCol://Next colummn
    c++; // Moving to next column
    if (c > 7) {//If we went passed the last row then print the outcome
      goto print;
	  }else{
	  	r = -1; //otherwise start at the "top" of the board
	  }
	  
nextRow:
   r++; //Move to next row
   if (r > 7) {//you have passed the end of the column
      goto backtrack; //Start the moms spaghetti
  }
   for(int i = 1; i<= c; i++){ //Horizontal check
      if (q[r][c-i]==1) 
         goto nextRow;
   }
    for (int i = 1; i < 8; i++){
      if((r+i) > 7 || (c-i) <0) {
	  break; //We are 100% off the board, break the loop
	  }
      if (q[r+i][c-i] == 1) //there is a queen i spots below and left of the current square
         goto nextRow;
   }
   for (int i = 1; i < 8; i++){
      if((r-i) < 0 && (c-i) < 0){
	  break;
	  } 
      if (q[r-i][c-i] == 1) 
         goto nextRow;
   }
   q[r][c] = 1;// Place a queen in the current square 
   goto nextCol;

backtrack:
   // Move back one col
   c--;

   if (c < 0)
        return 0;//you have moved all the way to the left of the bored so were done no more solutions

   for(int i = 0; i < 8; i++){
        if(q[i][c] == 1){
            r = i;
            break;
        }
   }

    q[r][c] = 0;


   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";

   for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << q[i][j];
        }
        cout << endl;
   }
   cout<<endl;
   // Use a nested loop to print the chessboard
   goto backtrack;

   return 0;
}

