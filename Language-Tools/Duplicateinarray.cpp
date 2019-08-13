/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Given an array of integers of size n which contains numbers from 0 to n - 2. Each number is present at least once. That is, if n = 5, numbers from 0 to 3 is present in the given array at least once and one number is present twice. You need to find and return that duplicate number present in the array.
Assume, duplicate number is always present in the array.
Input format :
Line 1 : Size of input array
Line 2 : Array elements (separated by space)
Output Format :
Duplicate element

*/


#include <bits/stdc++.h>

using namespace std;
int MissingNumber(int arr[], int size){
    unordered_map<int, int> m1;
    for (int i = 0; i < size; ++i)
    {
    	m1[arr[i]]++;
    }

    for (int i = 0; i < size; ++i)
    {
    	if (m1[arr[i]] == 2)
    	{
    		return arr[i];
    	}
    }

    return -1;
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout << MissingNumber(input, size);	
	
	delete [] input;

	return 0;



	return 0 ; 



}
