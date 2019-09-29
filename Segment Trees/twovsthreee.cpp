/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1
*/

#include <bits/stdc++.h>

using namespace std;

int create(int* arr, int* tree, int start, int end, int treeNode){
	if(start == end){
		tree[treeNode] = arr[start];
	}

	//Completely out
}

int query(int* tree, int start, int end, int treeNode, int left, int right){

}

void update(int* tree, int start, int end, int treeNode, int index){

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

	int* tree = new int[4*n];
	create(arr, tree, 0, n-1, 0);

	int q;
	cin>>q;

	while(q--){
		int type;
		cin>>type;

		if (type==0)
		{
			int b, c;
			cin>>b>>c;
			cout << query(tree, 0, n-1, 0, b, c) << '\n';
		}else if(type==1){
			int b;
			cin>>b;
			cout << update(tree, 0, n-1, 0, b) << '\n';
		}

	}



	return 0 ; 



}
