


#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>> n;
	int* arr = new int[n];
	int sum1=0, sum2=0;

	for (int i = 0; i < n; ++i)
	{
		int a;
		cin>>a;
		arr[i] = a;
		if(i%2==0 && a%2==0){
			sum1+=a;
		}else if(i%2 != 0 && a%2!=0){
			sum2+=a;
		}
	}

	cout << sum1<<" "<<sum2 << '\n';






	return 0 ; 



}

