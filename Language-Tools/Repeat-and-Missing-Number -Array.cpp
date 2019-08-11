/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.




*/



#include <bits/stdc++.h>

using namespace std;
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int len = A.size(); 
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6; 
    long long int missingNumber=0, repeating=0; 
      
    for(int i=0;i<A.size(); i++){ 
       Sum_N -= (long long int)A[i]; 
       Sum_NSq -= (long long int)A[i]*(long long int)A[i]; 
    } 
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2; 
    repeating= missingNumber - Sum_N; 
    vector <int> ans; 
    ans.push_back(repeating); 
    ans.push_back(missingNumber); 
    return ans; 
      



}
