/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number 
is present only once in the array.You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
	
*/


#include <bits/stdc++.h>

using namespace std;

int FindUnique(int arr[], int size){
	unordered_map<int, int> m1;

	for (int i = 0; i < size; ++i)
	{
		m1[arr[i]]++;
	}

	for (int i = 0; i < size; ++i)
	{
		if (m1[arr[i]]==1)
		{
			return arr[i];
		}
	}

	return 0;
	
    
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;


	return 0 ; 



}
