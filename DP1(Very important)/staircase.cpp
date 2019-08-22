/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
				PROBLEM STATEMENT
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps 
at a time. Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7

*/

#include <bits/stdc++.h>

using namespace std;
long staircase(int n){
	long* arr = new long[n+1];
    arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < n+1; ++i)
	{
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}

	return arr[n];

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n; 
	cin >> n ;
	cout << staircase(n) << endl;


	return 0 ; 



}
