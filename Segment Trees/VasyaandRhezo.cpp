/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
ueen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*/

#include <bits/stdc++.h>

using namespace std;

int query(int* arr1, int* arr2, int*tree, int start, int end, int treeNode, int left, int right){
	
	//Completely out
	if (left>end || right<start)
	{
		return left;
	}

	//Completely inside
	if (start>=left && end<=right)
	{
		return tree[treeNode];
	}

	//Partially inside
	int mid = (start+end)/2;
	

	int leftindex = query(arr1, arr2, tree, start, mid, 2*treeNode+1, left, right);
	int rightindex = query(arr1, arr2, tree, mid+1, end, 2*treeNode+2, left, right);

	if (arr1[leftindex]>arr1[rightindex])
	{
		return leftindex;

	}else if(arr1[leftindex]<arr1[rightindex]){
		
		return rightindex;

	}else{
		
		if (arr2[leftindex]>arr2[rightindex])
		{
			return rightindex;
		}else if(arr2[leftindex]<arr2[rightindex]){
			return leftindex;
		}else{
			return leftindex;
		}
	}

	return INT_MIN;

}


//tree will store even count
void create(int* arr1, int* arr2, int* tree, int start, int end, int treeNode){

	if (end == start)
	{
		tree[treeNode] = start;
		return;
	}

	int mid = (start+end)/2;

	create(arr1, arr2, tree, start, mid, 2*treeNode+1);
	create(arr1, arr2, tree, mid+1, end, 2*treeNode+2);

	int leftindex = tree[2*treeNode+1];
	int rightindex = tree[2*treeNode+2];

	if (arr1[leftindex]>arr1[rightindex])
	{
		tree[treeNode] = leftindex;

	}else if(arr1[leftindex]<arr1[rightindex]){
		tree[treeNode] = rightindex;

	}else{
		if (arr2[leftindex]>arr2[rightindex])
		{
			tree[treeNode] = rightindex;
		}else if(arr2[leftindex]<arr2[rightindex]){
			tree[treeNode] = leftindex;
		}else{
			tree[treeNode] = leftindex;
		}
	}
	//tree[treeNode] = left+right;
	return;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, q;
	cin>>n;
	int* arr1 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr1[i];
	}

	int* arr2 = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr2[i];
	}

	cin>>q;
	int* tree = new int[4*n];

	create(arr1, arr2, tree, 0, n-1, 0);
	// for (int i = 0; i < 4*n; ++i)
	// {
	// 	cout << "I- "<<i<<"   "<<tree[i] << '\n';
	// }
	//return 0;
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		cin>>a>>b;

		cout << query(arr1, arr2, tree, 0, n-1, 0, a-1, b-1)+1 << '\n';
	}

	delete[] tree;
	delete[] arr2;
	delete[] arr1;

	return 0 ; 



}
