/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Shaky has N (1<=N<=50000) candy boxes each of them contains a non-zero number of candies 
(between 1 and 1000000000). 
Shaky want to distibute these candies among his K (1<=K<=1000000000) IIIT-Delhi students.
 He want to distibute them in a way such that:
1. All students get equal number of candies.
2. All the candies which a student get must be from a single box only.
As he want to make all of them happy so he want to give as many candies as possible. 
Help Shaky in finding out what is the maximum number of candies which a student can get.

*/


#include <bits/stdc++.h>

using namespace std;
int is_possible(vector<int> v, int k, int mid){
	int n = v.size();
	int givento = 0;

	int i = 0;
	while(i<n){
		givento += v.at(i)/mid;
		
	}
	
	return(givento >= k);
}

int go(vector<int> v, int k){

	int n = v.size();
	sort(v.begin(), v.end());
	
	int max_candies = v.at(n-1);
	int min_candies = 0;
	int mid = (min_candies+max_candies)/2;

	int i = 0;
	int ans = 0;
	
	while(max_candies>=min_candies){
		if (is_possible(v, k, mid))
		{
			ans = max(ans, mid);
			min_candies = mid+1;
			mid = (min_candies+max_candies)/2;

		}else{
			max_candies = mid-1;
			mid = (min_candies+max_candies)/2;
		}
	}
	
	return ans;

}




int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;

	int t;
	cin>>t;

	while(t--){
		int n, k;
		cin>>n>>k;
		int m=n;
		std::vector<int> v;
		while(m--){
			int a;
			cin>>a;
			v.push_back(a);
		}
		cout << go(v,k) << '\n';
	}
	
	return 0 ; 

}
