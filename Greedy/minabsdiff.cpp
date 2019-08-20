/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

Given an integer array A of size N, find and return the minimum absolute difference between
 any two elements in the array.
We define the absolute difference between two elements ai, and aj (where i != j ) is |ai - aj|.
Input format :
Line 1 : Integer N, Array Size
Line 2 : Array elements (separated by space)
Output Format :
Minimum difference
*/

int minAbsoluteDiff(int arr[], int n) {
	int minimum = INT_MIN;

	sort(arr, arr+n);

	for (int i = 0; i < n-1; ++i)
	{
		int temp = arr[i+1]-arr[i];
		minimum = min(temp, minimum);
	}

	return minimum;

}


#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	



	return 0 ; 



}
