/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Harshit knows by his resources that this time the winning lottery number is the smallest 
number whose sum of the digits is S and the number of digits is D. You have to help Harshit 
and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and 
number of digits as 2. The smallest of them is 18.

*/


/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Harshit knows by his resources that this time the winning lottery number is the smallest 
number whose sum of the digits is S and the number of digits is D. You have to help Harshit 
and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and 
number of digits as 2. The smallest of them is 18.

*/


#include <bits/stdc++.h>

using namespace std;

void findSmallest(int m, int s) 
{ 
    // If sum of digits is 0, then a number is possible 
    // only if number of digits is 1. 
    if (s == 0) 
    { 
        (m == 1)? cout << 0 
                : cout << "Not possible"; 
        return ; 
    } 
  
    // Sum greater than the maximum possible sum. 
    if (s > 9*m) 
    { 
        cout << "Not possible"; 
        return ; 
    } 
  
    // Create an array to store digits of result 
    int res[m]; 
  
    // deduct sum by one to account for cases later 
    // (There must be 1 left for the most significant 
    //  digit) 
    s -= 1; 
  
    // Fill last m-1 digits (from right to left) 
    for (int i=m-1; i>0; i--) 
    { 
        // If sum is still greater than 9, 
        // digit must be 9. 
        if (s > 9) 
        { 
            res[i] = 9; 
            s -= 9; 
        } 
        else
        { 
            res[i] = s; 
            s = 0; 
        } 
    } 
  
    // Whatever is left should be the most significant 
    // digit. 
    res[0] = s + 1;  // The initially subtracted 1 is 
                     // incorporated here. 
  
    
    for (int i=0; i<m; i++) 
        cout << res[i]; 
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int s,d;
	cin>>s>>d;

	findSmallest(d,s);


	return 0 ; 



}
