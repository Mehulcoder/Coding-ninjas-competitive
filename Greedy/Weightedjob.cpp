/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the
 profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250


*/


#include <bits/stdc++.h>

using namespace std;

// A job has start time, finish time and profit. 
class Job 
{public:
    int start, finish, profit; 
}; 
  
// A utility function that is used for sorting events 
// according to finish time 
bool jobComparataor(Job s1, Job s2) 
{ 
    return (s1.finish < s2.finish); 
} 
  
// Find the latest job (in sorted array) that doesn't 
// conflict with the job[i]. If there is no compatible job, 
// then it returns -1. 
int latestNonConflict(Job arr[], int i) 
{ 
    for (int j=i-1; j>=0; j--) 
    { 
        if (arr[j].finish <= arr[i-1].start) 
            return j; 
    } 
    return -1; 
} 
  
// A recursive function that returns the maximum possible 
// profit from given array of jobs.  The array of jobs must 
// be sorted according to finish time. 
int findMaxProfitRec(Job arr[], int n) 
{ 
    // Base case 
    if (n == 1) return arr[n-1].profit; 
  
    // Find profit when current job is inclueded 
    int inclProf = arr[n-1].profit; 
    int i = latestNonConflict(arr, n); 
    if (i != -1) 
      inclProf += findMaxProfitRec(arr, i+1); 
  
    // Find profit when current job is excluded 
    int exclProf = findMaxProfitRec(arr, n-1); 
  
    return max(inclProf,  exclProf); 
} 
  
// The main function that returns the maximum possible 
// profit from given array of jobs 
int findMaxProfit(Job arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, jobComparataor); 
  
    return findMaxProfitRec(arr, n); 
} 
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	Job* arr = new Job[n];
	for (int i = 0; i < n; ++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		Job temp;
		temp.start = a;
		temp.finish = b;
		temp.profit = c;

		arr[i] = temp;
	}

	cout << findMaxProfit(arr, n) << '\n';



	return 0 ; 



}
