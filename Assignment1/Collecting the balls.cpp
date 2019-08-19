/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to took balls out from 
the container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth
 of the remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 
 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls 
 remaining at some moment, then Mr. Sharma will take all the balls which will get the container 
 empty. The process will last till the container becomes empty. Your task is to choose minimal ‘k’ 
 for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container.
Input Format:
Only line of input contains a single integer ‘n’.
Output Format:
Print a single integer denoting the minimal value of ‘k’.
Constraints:
1 <= n <= 10^18
Time Limit: 1 second
Sample Input:
68
Sample Output:
3
Explanation:
68-3 = 65; 65/10 = 6; 65-6 = 59
59-3 = 56; 56/10 = 5; 56-5 = 51
51-3 = 48; 48/10 = 4; 48-4 = 44
44-3 = 41; 41/10 = 4; 41-4 = 37
…..
…..
…..
6-3 = 3; 3/10 = 0; 3-0 = 3
3-3 = 0; 0/10 = 0; 0-0 = 0
*/


#include <bits/stdc++.h>

using namespace std;

long long helper(long long start, long long end, long long N, long long &ans){
	// cout << "start: "<<start << '\n';
	// cout << "end "<<end << '\n';
	
	if (start > end)
	{
		return ans;
	}

	long long n = N;

	long long mid = (start+end)/2;
	//cout << "mid; "<<mid << '\n';
	long long k =  mid;
	//cout << k << '\n';

	long long sharma = 0, singh = 0;

	while(n>=k && n>0){
		sharma += k;
		n = n-k;
		singh += (n)/10;
		n = n-(n)/10;
	}

	sharma += n;
	//  cout << "sharma: " <<sharma<< '\n';
	// cout <<"singh: "<<singh  << '\n';

	
	// cout << sharma << '\n';
	// cout << N/2 << '\n';
	if (2*sharma<N)	
	{
		return helper(mid+1, end, N, ans);
	}else{
		ans = k;
		//cout <<"here "<<mid  << '\n';
		return helper(start, mid-1, N, ans);
		
	}


}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long n;
	cin>>n;

	cout << helper(1, n, n, n) << '\n';


	return 0 ; 



}
