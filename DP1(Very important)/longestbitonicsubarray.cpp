/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
You are given an array of positive integers as input. Write a code to return the length of the largest such sub-array in which the values are arranged first in strictly ascending order and then in strictly descending order.
Such a sub-array is known as bitonic sub-array. A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.
Note that the elements in bitonic sub-array need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic Sub-Array
Input Constraints:
1<= N <= 10^5
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic sub-array is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*/

#include <bits/stdc++.h>

using namespace std;

int longestBitonicSubarray(int *arr, int n) {
	int i, j; 
  
   /* Allocate memory for LIS[] and initialize LIS values as 1 for 
      all indexes */
   int *lis = new int[n]; 
   for (i = 0; i < n; i++) 
      lis[i] = 1; 
  
   /* Compute LIS values from left to right */
   for (i = 1; i < n; i++) 
      for (j = 0; j < i; j++) 
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
            lis[i] = lis[j] + 1; 
  
   /* Allocate memory for lds and initialize LDS values for 
      all indexes */
   int *lds = new int [n]; 
   for (i = 0; i < n; i++) 
      lds[i] = 1; 
  
   /* Compute LDS values from right to left */
   for (i = n-2; i >= 0; i--) 
      for (j = n-1; j > i; j--) 
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1) 
            lds[i] = lds[j] + 1; 
  
  
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int max = lis[0] + lds[0] - 1; 
   for (i = 1; i < n; i++) 
     if (lis[i] + lds[i] - 1 > max) 
         max = lis[i] + lds[i] - 1; 
   return max; 

}
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int n, input[100000];
	cin>>n;
	for(int i=0; i<n; i++) {
	cin>>input[i];
	}
	cout<<longestBitonicSubarray(input, n);
	return 0;



}
