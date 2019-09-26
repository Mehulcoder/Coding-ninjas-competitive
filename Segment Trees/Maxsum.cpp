/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
*/


#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>

class node{
public:
	int prefixsum;
	int suffixsum;
	int sum;
	int bestsum;
};

node query(node* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		node temp;
		temp.prefixsum = INT_MIN;
		temp.suffixsum = INT_MIN;
		temp.sum = INT_MIN;
		temp.bestsum = INT_MIN;
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	
	int mid = (start+end)/2;

	if(left>mid){
		return query(tree, mid+1, end, 2*treeNode+2, left, right);
	}

	if(right<=mid){
		return query(tree, start, mid, 2*treeNode+1, left, right);
	}


	node l = query(tree, start, mid, 2*treeNode+1, left, right);
	node r = query(tree, mid+1, end, 2*treeNode+2, left, right);

	node result;

	result.sum = l.sum+r.sum;
	result.prefixsum = max(l.prefixsum, l.sum+r.prefixsum);
	result.suffixsum = max(r.suffixsum, r.sum+l.suffixsum);
	result.bestsum = max(result.prefixsum, 
					max(result.suffixsum,
					max(l.bestsum,max(r.bestsum,
					l.suffixsum+r.prefixsum))));

	return result;
	

}


void create(int* arr, node* tree, int start, int end, int treeNode){
	if (end == start)
	{
		tree[treeNode].prefixsum = arr[start];
		tree[treeNode].suffixsum = arr[start];
		tree[treeNode].sum = arr[start];
		tree[treeNode].bestsum = arr[start];
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	node left = tree[2*treeNode+1];
	node right = tree[2*treeNode+2];

	tree[treeNode].sum = left.sum+right.sum;
	tree[treeNode].prefixsum = max(left.prefixsum, left.sum+right.prefixsum);
	tree[treeNode].suffixsum = max(right.suffixsum, right.sum+left.suffixsum);
	tree[treeNode].bestsum = max(tree[treeNode].prefixsum, 
								max(tree[treeNode].suffixsum,
								max(left.bestsum,
								max(right.bestsum,
								left.suffixsum+right.prefixsum))));

	return;
}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, q;
	cin>>n;

	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cin>>q;
	node* tree = new node[4*n];

	create(arr, tree, 0, n-1, 0);

	for (int i = 0; i < 4*n; ++i)
	{
		cout << i<<" = I  "<<tree[i].bestsum<< '\n';
	}

	while(q--){
		
		int b, c;
		cin>>b>>c;
		
		node result = query(tree, 0, n-1, 0, b, c);
		cout << result.bestsum << '\n';		

	}


	return 0 ; 



}