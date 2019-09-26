/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
*/

#include <bits/stdc++.h>

using namespace std;

int query(int*tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		return -1;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;

	int l = query(tree, start, mid, 2*treeNode+1, left, right);
	int r = query(tree, mid+1, end, 2*treeNode+2, left, right);


	int result;
	result = left+right;
   	return result;

}

//tree will store even count
void create(int* arr, int* tree, int start, int end, int treeNode){
	if (end == start)
	{
		if (arr[start]%2==0)
		{
			tree[treeNode] = 1;
		}else{
			tree[treeNode] = 0;
		}
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	int left = tree[2*treeNode+1];
	int right = tree[2*treeNode+2];

	tree[treeNode] = left+right;
	return;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, q;
	cin>>n;
	int* arr = new int[n];

	cin>>q;
	int* tree = new int[4*n];

	create(arr, tree, 0, n-1, 0);

	for (int i = 0; i < q; ++i)
	{
		int a, b, c;
		cin>>a>>b>>c;
		if (a == 1)
		{
			cout << query(tree, 0, n-1, 0, b, c) << '\n';
		}else if(a == 0)
		{
			update(arr, tree, 0, n-1, 0, b, c);
		}else{

			int k = query(tree, 0, n-1, 0, b, c);
			cout << b-c+1-k << '\n';
		}
	}



	return 0 ; 



}
