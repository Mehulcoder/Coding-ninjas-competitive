/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


/*
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:
Update:
This will be indicated in the input by a 'U' followed by space and then two integers i and x.
U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8.
This operation sets the value of A[i] to x.
Query:
This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j.
Q x y, 1 ≤ x < y ≤ N.
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
Input
The first line of input consists of an integer N representing the length of the sequence. 
Next line consists of N space separated integers A[i]. Next line contains an integer Q, Q ≤ 10^5, representing the number of operations. Next Q lines contain the operations.
Output
 Output the maximum sum mentioned above, in a separate line, for each Query.
Input:
5
1 2 3 4 5
6
Q 2 4
Q 2 5
U 1 6
Q 1 5
U 1 7
Q 1 5
Output:
7
9
11
12
*/

#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>

pii query(pii* tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		pii temp = make_pair(INT_MIN, INT_MIN);
		return temp;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;

	pii l = query(tree, start, mid, 2*treeNode+1, left, right);
	pii r = query(tree, mid+1, end, 2*treeNode+2, left, right);


	pii result;
	result.first = max(l.first,r.first);
    result.second = min(max(l.first,r.second),max(l.second,r.first));
   	return result;

}


void update(int* arr, pii* tree, int start, int end, int treeNode, int idx, int value){
	int mid = (start+end)/2;

	if (start == end)
	{
		arr[idx] = value;
		tree[treeNode] = make_pair(value, INT_MIN);
		return;
	}

	if (idx<=mid)
	{
		update(arr, tree, start, mid, 2*treeNode+1, idx, value);
	}else{

		update(arr, tree, mid+1, end, 2*treeNode+2, idx, value);
	}

	pii left = tree[2*treeNode+1];
	pii right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
	return;
//	tree[treeNode] = min(tree[2*treeNode+1], tree[2*treeNode+2]);
}


void create(int* arr, pii* tree, int start, int end, int treeNode){
	if (end == start)
	{
		tree[treeNode] = make_pair(arr[start], INT_MIN);
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	pair<int, int> left = tree[2*treeNode+1];
	pair<int, int> right = tree[2*treeNode+2];

	tree[treeNode].first = max(left.first,right.first);
	tree[treeNode].second = min(max(left.first,right.second),max(left.second,right.first));
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
	pii* tree = new pii[4*n];

	create(arr, tree, 0, n-1, 0);

	// for (int i = 0; i < 4*n; ++i)
	// {
	// 	cout << i<<" = I  "<<tree[i].first<<" "<<tree[i].second << '\n';
	// }

	while(q--){
		char a;
		int b, c;
		cin>>a>>b>>c;

		if (a=='q' || a == 'Q')
		{
			pii result = query(tree, 0, n-1, 0, b-1, c-1);
			cout << result.first+result.second << '\n';
		}else{
			update(arr, tree, 0, n-1, 0, b-1, c);
		}

	}


	return 0 ; 



}