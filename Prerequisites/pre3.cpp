

#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	int sum = 0;
	int** arr = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i]=new int[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
			if(i==0 || j==0 || i==j || i==n-1 || j==n-1 || i+j==n-1){
				sum=sum+arr[i][j];
			}
		}
	}

	cout << sum << '\n';



	return 0 ; 



}

