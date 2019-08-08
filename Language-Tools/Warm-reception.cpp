/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
There is only one beauty parlour in the town CodingNinjasLand. The receptionist at beauty parlour is flooded with appointment requests because “Hakori” festival is round the corner and everyone wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell minimum number of chairs required such that none of the customer has to stand.

*/


#include <bits/stdc++.h>

using namespace std;

class detail
{
public:
	int time;
	bool status;
	
};


bool mysort(detail a, detail b){
	return(a.time < b.time);
}



int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

//Arrival
	std::vector<detail> people;
	for (int i = 0; i < n; ++i)
	{
		int temp_time;
		cin>>temp_time;
		detail temp;
		temp.time = temp_time;
		temp.status = 1;
		people.push_back(temp);
	}

//Departure
	for (int i = 0; i < n; ++i)
	{
		int temp_time;
		cin>>temp_time;
		detail temp;
		temp.time = temp_time;
		temp.status = 0;
		people.push_back(temp);
	}

//Sorting

	sort(people.begin(), people.end(), mysort);
	

	int ans = 0;
	int count = 0;

	vector<detail> :: iterator it = people.begin();

	for (int i = 0; i < people.size(); ++i)
	{
		if (people.at(i).status == 1)
		{
			count++;
		}else{
			count--;
		}
		ans = max(ans, count);
	}

	cout << ans << '\n';


	return 0 ; 



}
