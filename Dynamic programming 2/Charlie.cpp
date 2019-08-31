/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible. There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot. However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int go(vector<pii> pilots, int i, int ncap, int nass, int*** mem){
	if (i>=pilots.size())
	{
		return 0;
	}


	if (ncap == 0 && nass == 0)
	{
		return 0;
	}

	if (pilots.size()-i<ncap+nass)
	{
		return 0;
	}
	// if (i==0)
	// {
	// 	cout<<ncap<<" "<<nass;
	// }
	// return 0;

	if(mem[i][ncap][nass] != -1){
		return mem[i][ncap][nass];
	}

	int c1 = INT_MAX;
	int c2 = INT_MAX;

	if (nass<ncap)
	{
		c1 = pilots[i].f + go(pilots, i+1, ncap-1, nass, mem);
		mem[i+1][ncap-1][nass] = go(pilots, i+1, ncap-1, nass, mem);
	}

	if (nass>=1)
	{
		c2 = pilots[i].s + go(pilots, i+1, ncap, nass-1, mem);
		mem[i+1][ncap][nass-1] = go(pilots, i+1, ncap, nass-1, mem);	
	}

	//cout << "i "<<i<<" ncap "<<ncap<<" nass "<<nass << '\n';
	mem[i][ncap][nass] = min(c1, c2);
	return min(c1, c2);



}



int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	vector<pii> v1(n, make_pair(0, 0));
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin>>a>>b;
		v1[i] = make_pair(a,b);
	}

	int*** mem = new int**[n+2];
	for (int i = 0; i < n+2; ++i)
	{
		mem[i] = new int*[n/2+3];
		for (int j = 0; j < n/2+3; ++j)
		{
			mem[i][j] = new int[n/2+3];
		}
	}
	//int mem[100][100][100];


	//memset(mem, -1, (n+2)*(n/2+3)*(n/2+3)*sizeof(int));
	for (int i = 0; i < n+2; ++i)
	{
		for (int j = 0; j < n/2+3; ++j)
		{
			for (int k = 0; k < n/2+3; ++k)
			{
				mem[i][j][k] = -1;
			}
		}
	//	cout << '\n';
	}

	// for (int i = 0; i < n+2; ++i)
	// {
	// 	for (int j = 0; j < n/2+3; ++j)
	// 	{
	// 		cout << mem[i][j][0] << ' ';
	// 	}
	// 	cout << '\n';
	// }


	cout << go(v1, 0, n/2, n/2, mem) << '\n';

	return 0 ; 
}
