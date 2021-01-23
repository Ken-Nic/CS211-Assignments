#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) { //Okay function of 1D queens 
   for (int i=0; i<c ;i++){
     if ((q[c]==q[i])||(c-i)== abs(q[c]-q[i]))
         return false; 
    }
   return true;
}
// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int x) {
int* q= new int[x]; //Declaring a pointer to memroy to dynamically allocate memory for the array
q[0] = 0; //Having everything to zero
int c=0;
int Solutions = 0; //THis variable will increment ever time a solution for the queens of n size is found
  while (c >= 0) {  
   	 c++;
      if(c == x){ //FOund a answer? 
        Solutions++; //increase the number of solution
        c--; //Decrease the colummn
      }
      else{
      q[c]=-1;
    }
      while (c >= 0) {
         q[c]++;
         if(q[c]== x){
           c--;
    }
    else if(ok(q,c) == true){ //Using okay fc,if it = true, as a way to break from the loop so we dont run forever
        break;
        }
	}
    }
   return Solutions; //Return ans
   delete[] q; //Delete the array cause c++ doesnt have garbage collection. Also i dont want a memory leak, Genji.exe cant take all that
}
   
int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i) //Printing out the solutions
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
   
