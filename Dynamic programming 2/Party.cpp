/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
You just received another bill which you cannot pay because you lack the money.
Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
You make up your mind to solve the problem where it arises, namely at the parties themselves. You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
Write a program which finds this optimal set of parties that offer the most fun. Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, and do not spend more money than is absolutely necessary.
Input
The first line of the input specifies your party budget and the number n of parties.

The following n lines contain two numbers each. The first number indicates the entrance fee of each party. Parties cost between 5 and 25 francs. The second number indicates the amount of fun of each party, given as an integer number ranging from 0 to 10.

The budget will not exceed 500 and there will be at most 100 parties. All numbers are separated by a single space.

There are many test cases. Input ends with 0 0.
Output
For each test case your program must output the sum of the entrance fees and the sum of all fun values of an optimal solution. Both numbers must be separated by a single space. 
Sample Input
50 10
12 3
15 8
16 9
16 6
10 2
21 9
18 4
12 4
17 8
18 9 

50 10
13 8
19 10
16 8
12 9
10 2
12 8
13 5
15 5
11 7
16 2

0 0
Sample Output
49 26
48 32
*/

#include <bits/stdc++.h>

using namespace std;

pair<int, int> go(vector<pair<int, int>> v, int n, int totalmoney){
	//Initializing a (0,0) pair 2d DP array;
	//Left to Right represents the budget starting from 0-total money
	//Top to bottom represents the starting index of our chosen subvector from fun vector(pair).
	//We'll work on subarray from that i to bottom of the fun vector
	pair<int,int> pairzero = make_pair(0, 0);
	vector<vector<pair<int, int>>> dp(n+1, vector<pair<int, int>>(totalmoney+1, pairzero));


	for (int j = 1; j < totalmoney+1; ++j)
	{
		for (int i = n-1; i >= 0; --i)
		{
			if (v[i].first <= j)
			{
				pair<int, int> c1;
				c1.first = v[i].first + dp[i+1][j-v[i].first].first;
				c1.second = v[i].second + dp[i+1][j-v[i].first].second;

			//	pair<int, int> c1 = make_pair(v[i].first, v[i].second)+dp[i+1][j-v[i].first];
				pair<int, int> c2 = dp[i+1][j];

				if (c1.second > c2.second)
				{
					dp[i][j] = c1;
				}else if(c1.second < c2.second)
					dp[i][j] = c2;
				else{
					if (c1.first <= c2.first)
					{
						dp[i][j] = c1;
					}else
						dp[i][j] = c2;
				}


			}else{

				dp[i][j] = dp[i+1][j];

			}
		}
	}

	return dp[0][totalmoney];


}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	

	while(1){
		int totalmoney, n;
		cin>>totalmoney>>n;

		if (totalmoney == 0 || n==0)
			break;
		vector<pair<int, int>> v;

		for (int i = 0; i < n; ++i)
		{
			int cost, fun;
			cin>>cost>>fun;
			v.push_back(make_pair(cost, fun));
		}

		pair<int, int> ans = go(v, n, totalmoney);

		cout << ans.first <<" "<<ans.second << '\n';
	}



	return 0 ; 



}
