/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given n activities with their start and finish times. Select the maximum number of 
activities that can be performed by a single person, assuming that a person can only work on a
 single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for 
the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
*/

#include <bits/stdc++.h>

using namespace std;

bool mySort(pair<int, int> slot1, pair<int, int> slot2){
	return(slot1.first<slot2.first);
}

int go(vector<pair<int,int>> time){
	int count = 1;
	int n = time.size();
	sort(time.begin(), time.end(), mySort);
	
	pair<int, int> current = time.at(0);

	for (int i = 1; i < n; ++i)
	{
		if (current.second<=time.at(i).first)
		{
			count++;
			current = time.at(i);

		}else if (current.second>time.at(i).first)
		{
			if (time.at(i).second<=current.second)
			{
				current = time.at(i);
			}
		}
	}

	return count;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	std::vector<pair<int, int>> time;

	while(n--){
		int start, end;
		cin>>start>>end;
		pair<int, int> a = make_pair(start, end);
		time.push_back(a);
	}

	cout << go(time) << '\n';


	return 0 ; 



}
