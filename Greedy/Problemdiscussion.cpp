/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum 
value and minimum value by modifying the array under the condition that each array element either 
increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array
Output Format
The output contains a single integer denoting the minimum difference between maximum value and 
the minimum value in the array
Constraints
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't 
get a lower difference.

*/


#include <bits/stdc++.h>

using namespace std;

int getMinDiff(int arr[], int n, int k) 
{ 
    if (n == 1) 
       return 0; 
  
    // Sort all elements 
    sort(arr, arr+n); 
  
    // Initialize result 
    int ans = arr[n-1] - arr[0]; 
  
    // Handle corner elements 
    int small = arr[0] + k; 
    int big = arr[n-1] - k; 
    if (small > big) 
       swap(small, big); 
  
    // Traverse middle elements 
    for (int i = 1; i < n-1; i ++) 
    { 
        int subtract = arr[i] - k; 
        int add = arr[i] + k; 
  
        // If both subtraction and addition 
        // do not change diff 
        if (subtract >= small || add <= big) 
            continue; 
  
        // Either subtraction causes a smaller 
        // number or addition causes a greater 
        // number. Update small or big using 
        // greedy approach (If big - subtract 
        // causes smaller diff, update small 
        // Else update big) 
        if (big - subtract <= add - small) 
            small = subtract; 
        else
            big = add; 
    } 
  
    return  min(ans, big - small); 
} 

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n,k;
	cin>>n>>k;

	int* arr = new int[n];
	
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout << getMinDiff(arr, n, k) << '\n';


	return 0 ; 



}
