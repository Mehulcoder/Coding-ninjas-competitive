/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". 
There is no constraint that out of 5 triplets which have to be printed on 1st line. 
You can print triplets in any order, just be careful about the order of elements in a triplet.
*/


#include <bits/stdc++.h>

using namespace std;
void FindTriplet(int arr[], int size, int x) {
	sort(arr, arr+size);
	 //int end = size-1;
	for (int i = 0; i < size; i++)
	{
		int val = x-arr[i];
		int j = i+1;
		int k = size-1;
		while(j<k ){
			
			
			if (arr[j]+arr[k]>val)	
			{
				k--;

			}else if (arr[j]+arr[k]<val)
			{
				j++;

			}else{
                //cout<<"here"<<i<<j<<k<<"sum"<<sum<<endl;
                
				int leftcount = 0;
				int rightcount = 0;
				
				for (int ptr = j; ptr <= k; ++ptr)
				{
					if (arr[ptr] == arr[j])
					{
						leftcount++;
					}else
						break;
				}
				for (int ptr = k; ptr >= j; ptr--)
				{
					if (arr[ptr] == arr[k])
					{
						rightcount++;
					}else
						break;
				}

				int total = leftcount*rightcount;
              //  cout<<total;
				if (arr[j]==arr[k])
				{
					total = ((k-j+1)*(k-j))/2;
				}
             //   cout<<total;
				for(int m=0;m<total;m++){
					cout << arr[i]<<" "<<arr[j]<<" "<<arr[k] << '\n';
		
				}

				j +=leftcount;
				k=k-rightcount;
			}
		}
	}

    
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	int size;

	int x;
	cin>>size;
	
	int *arr=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>arr[i];
	cin>>x;

	FindTriplet(arr,size,x);
		
	return 0;




}
