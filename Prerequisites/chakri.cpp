/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin >>n;
	int * arr = new int[n];
	int max =0,min=0;
	int j=1;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];

		while(j==1){
			min = arr[0];
			j--;
		}

		if (arr[i]>=max)
		{
			max=arr[i];
		}
		if (arr[i]<=min)
		{
			min=arr[i];
		}
	}

	//cout <<max  << '\n';
	//cout << min << '\n';
	cout <<max-min<< '\n';


	return 0 ; 



}
