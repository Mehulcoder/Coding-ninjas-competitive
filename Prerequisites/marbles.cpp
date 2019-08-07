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
	
	int n,sum;

	cin>> n>>sum;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int start=0;
	int end=0;
	int tempsum=arr[end];

	while(1){
		//tempsum=tempsum+arr[end];
		cout << "temp"<<tempsum << '\n';

		if(tempsum==sum){
			cout << "true" << '\n';
			for (int i = start; i <= end; ++i)
			{
				cout << arr[i]<< " ";
			}
			return 0;
		}else if (tempsum < sum )
		{
		//	cout << "imhere" << '\n';
			if (end<n-1)
			{
				end++;
				//cout << "arrend"<<arr[end] << '\n';
					tempsum = tempsum + arr[end];
				//cout << "sumhere"<<tempsum << '\n';
				continue;
			}else{
				cout << "false" << '\n';
				return 0;
			}
			
		}else if (tempsum>sum)
		{	if (start<n-1){
			
			tempsum=tempsum-arr[start];
			start++;
			if(start>end){
				end++;
				tempsum =  arr[end];
			}
			continue;
			}else{
				cout << "false" << '\n';
				return 0;
			}
			
		}else if (start == n-1)
		{
			cout << "false"  << '\n';
			return 0;
		}




	}






	return 0 ; 



}
