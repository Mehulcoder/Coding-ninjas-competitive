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
	cin>>n;
	int* arr=new int[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	long double sum=0;

	for (int i = 0; i < n; ++i)
	{
		sum+=(long double)log10(arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << int(pow((long double)10.00, sum-log10(arr[i]))) << " ";
	}



	return 0 ; 



}
