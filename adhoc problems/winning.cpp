/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
				PROBLEM STATEMENT
Our college team is going to the sports fest to play a football match with our coach. There are 
n players in our team, numbered from 1 to n.
The coach will know the position of another team hence create a winning strategy. He creates the 
position of every player in a specific order so that we will win and then he starts swapping two 
players at a time to form the positions.
He swaps payers in such a way that it can't be understood by another team:
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose
Input Format
The First line contains numbers of players in team: n
The second line contains n space separated integers denoting the specific position of players: 
i-th integer denotes the position of Ai player in winning strategy
Output Format
If our team wins print "YES"(without quotes) and in next line print the minimum numbers of 
swapping required to form this specific order otherwise print "NO"(without quotes) 
Constraints
1 =< n <= 10^5 
1 <= Ai <= n
Sample Input1:
5
2 1 5 3 4
Sample Output1:
YES
3
Sample Input2:
5
2 5 1 3 4
Sample Output3:
NO   
Explaination
In the First Sample case, 
    Initial state: 1 2 3 4 5
    Three moves required to form this order:
    1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
In the second case, no way to form this specific order
*/

#include <bits/stdc++.h>

using namespace std;
//Returns -1 if not possible
int go(int* arr, int n){
    if(n==1){
        if(arr[0]!=1){
            return -1;
        }else{
            return 0;
        }
    }
    if(n==0){
        return 0;
    }
	
    int count = 0;
	int i = 0;
    
    for (int j = 0; j < n; ++j)
    {
    	if(arr[j]>j+3 || arr[j]<j-1){
            return -1;
        }
    }
	
    for (i ; i < n-2; ++i)
	{
        if(arr[i]>i+3 || arr[i]<i-1){
            return -1;
        }
		if (arr[i]==i+1)
		{
			continue;

		}else if (arr[i+1]==i+1)
		{
			//cout << "here" << '\n';
			swap(arr[i], arr[i+1]);
			count++;
			//cout << count << '\n';
			continue;
		}else if (arr[i+2]==i+1)
		{
			swap(arr[i+2], arr[i+1]);
			count++;
			swap(arr[i+1], arr[i]);
			count++;
			continue;
		}else{
			return -1;
		}
	}
	
    
    //Doing operation on remaining last two elements
	if (arr[i] == i+1 && arr[i+1]==i+2)
	{
		return count;
        
	}else if(arr[i]==i+2 && arr[i+1]==i+1){
		swap(arr[i], arr[i+1]);
		return count+1;
	}else{
		return -1;
	}




}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int ans = go(arr, n);
	if (ans==-1)
	{
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n' << ans <<endl;
	}


	return 0 ; 



}
