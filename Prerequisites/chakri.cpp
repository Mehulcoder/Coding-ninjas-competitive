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
  	int a[n];
  	for(int i=0;i<n;i++)
    cin>>a[i];
 	 int profit=0;
 	 for(int i=0;i<n-1;i++)
 	 {
    	for(int j=i;j<n;j++)
    	{
     	 if((a[j]-a[i]>0) && ((a[j]-a[i])>profit))
    	  {
     	   profit=a[j]-a[i];
     	 }
   	 }
 	 }
  	cout<<profit<<endl;



}
