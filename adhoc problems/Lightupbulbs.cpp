/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’. Their status is represented in a string of size ‘n’ consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ represent the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.
He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it. E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) is reversed here. This operation will cost him Rs. ‘X’.
Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’, make it ‘OFF’ and if it is ‘OFF’, make it ‘ON’. E.g. “0 011 001” -> “0 100 001”. Substring (1, 3) is complemented. This operation will cost him Rs. ‘Y’.
You need to help Mr. Navdeep that how much minimum amount it will require to make all the bulbs lightened. (or make all the characters as ‘1’ in the representation string)
Input Format:
The first line will contain three space separated long longegers: ‘n’, ‘X’, ‘Y’ denoting the number of bulbs, cost of first operation and cost of second operation respectively.
The second line contains a representation string of length ‘n’ consisting of 0’s and 1’s representing whether the bulb is ‘OFF’ or ‘ON’.
Output Format:
Prlong long a single long longeger denoting the minimum cost required to light up all the bulbs.
Constralong longs:
1 <= n <= 3,00,000
0 <= X, Y <= 10^9
Time Limit: 1 second
Sample Input:
5 1 10
01000
Sample Output:
11
Explanation:
First, Reverse substring (0, 1): “01000” -> “10000”, COST = 1
Second, Invert substring (1, 4): “10000” -> “11111”, COST = 10
Total cost = 1+10 => 11
*/
/*
#include <bits/stdc++.h>

using namespace std;
long long go(long long* arr, long long n, long long x ,long long y){
	long long breaks = 0;
	if (arr[0]==0)
	{
		breaks++;
	}
	for (long long i = 0; i < n-1; ++i)
	{
		// cout <<arr[i]  << '\n';
		// cout << arr[i+1] << '\n';
		if (arr[i+1] == 0 && arr[i] == 1)
		{
			breaks++;
		}
	}

	//cout << breaks << '\n';
	if (breaks == 0)
	{
		return 0;
	}
	long long operation = breaks-1;

	long long ans = operation*min(x,y)+y;
	return ans;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	long long n, x, y;
	cin>>n>>x>>y;
	
	string str;
	cin>>str;


	long long* arr = new long long[n];

	for (long long i = 0; i < n; ++i)
	{
		arr[i] = str[i]-'0';
	}

	cout << go(arr, n, x, y) << '\n';

	delete [] arr;

	return 0 ; 



}
*/

#include <bits/stdc++.h>

using namespace std;
int main()
{
	long long n, x, y, num = 0;
	//num = no. of reverse operations required   to put all the zeros together so that only one light up operation is required
	cin >> n >> x >> y;
	string s;
	cin >> s;
	s = s + '1';
	//no. of reverse operations required = no. of continuos segments of zeros - 1
	//that's why I added 1 at the end of string to count no. of changes from zero to one
	//example : s = 0011100010 in this case num= 3 -1 = 2
	for (int i = 1; i < n + 1; i++)
	{
		if (s[i] == '1')
		{
			if (s[i - 1] == '0')
			{
				num++;
			}
		}
	}
	if (num == 0)
	{
		cout << "0";
		return 0;
	}
	long long ans = min(num * y, (num - 1) * x + y);
	//num*y = cost of lighting all the segments of zeros in our example it will be 3*y as there are 3 segments of zeros
	//(num-1)*x = cost of reverse operations required to get one continuos segment + 1*y (cost of lighting up that 1 segment)
	cout << ans;
	return 0;
}
