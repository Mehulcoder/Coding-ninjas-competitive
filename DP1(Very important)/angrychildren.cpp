/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*/


#include <bits/stdc++.h>

using namespace std;

long long go(vector<long long> candies, long long n, long long k){
	//size is n+1

	sort(candies.begin(), candies.end());

	long long sum = 0;
	long long buffer = 0;
	for (long long i = 1; i <=k; ++i)
	{
		sum += i*candies[i];
		sum -= (k-i+1)*candies[i];

		buffer += candies[i];
	}


	long long ans = sum;
	for (long long i = 2; i <= n-k+1; ++i)
	{
		sum = sum - 2*(buffer - candies[i-1])+(k-1)*candies[i-1]+(k-1)*candies[i+k-1];
		
		buffer = buffer - candies[i-1]+candies[i+k-1];
		

		ans = min(ans, sum);
	}

	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long n, k;
	cin>>n>>k;

	vector<long long> candies(n+1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cin>>candies[i];
	}

	cout << go(candies, n, k) << '\n';

	return 0 ; 



}
