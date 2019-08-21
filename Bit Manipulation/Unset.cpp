/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
				PROBLEM STATEMENT
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 
and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Two integers N and i (separated by space)
Output Format :
Updated N
Sample Input 1 :
7 2
Sample Output 1 :
3
Sample Input 2 :
12 1
Sample Output 2 :
12
*/

#include <bits/stdc++.h>

using namespace std;

int turnOffIthBit(int n, int i){
    // k must be greater than 0 
    if (i < 0) return n; 
  
    // Do & of n with a number with all set bits except 
    // the k'th bit 
    return (n & ~(1 << (i))); 
    
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, i;

	cin >> n >> i;
	
	cout<< turnOffIthBit(n, i) <<endl;
		
	return 0;

}
