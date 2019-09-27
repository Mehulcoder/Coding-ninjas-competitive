/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1

*/

#include <bits/stdc++.h>

using namespace std;

class treeclass{
public:
		int sumsquare;
		int sum;
};

class lazyclass{
public:
	int type;
	int key;
};

//Type 1 for increment
//Type 2 for change

// void update1(int* arr, treeclass* tree, lazyclass* lazy, int start, int end, int treeNode, int left ,int right, int value){

// 	if (start>end)
// 	{
// 		return;
// 	}

// 	if (lazy[treeNode]!=0)
// 	{
// 		tree[treeNode]
// 	}


// }

void create(int* arr, treeclass* tree, int start, int end, int treeNode){
	if (start == end)
	{
		tree[treeNode].sumsquare = arr[start]*arr[start];
		tree[treeNode].sum = arr[start];
		return;
	}

	int mid = (start+end)/2;

	create(arr, tree, start, mid, 2*treeNode+1);
	create(arr, tree, mid+1, end, 2*treeNode+2);

	treeclass left = tree[2*treeNode+1];
	treeclass right = tree[2*treeNode+2];


	tree[treeNode].sumsquare = left.sumsquare+right.sumsquare;
	tree[treeNode].sum = left.sum+right.sum;

	return;

}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int t;
	cin>>t;

	while(t--){
		int n, q;
		cin>>n>>q;

		int* arr = new int[n];
		
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}

		treeclass* tree = new treeclass[4*n];

		create(arr, tree, 0, n-1, 0);
		for (int i = 0; i < 4*n; ++i)
		{
			cout << "squares "<<tree[i].sumsquare<<" sum "<<tree[i].sum << '\n';
		}

		/*while(q--){
			int a
			cin>>a;

			if (a==2)
			{
				int b,c;
				cin>>b>>c;
				cout << query(tree, 0, n-1, 0, b, c) << '\n';

			}else if (a==1)
			{
				//1 forIncrement
				int b, c, x;
				cin>>b>>c>>x;
				update1(arr, tree, 0, n-1, 0, b, c, x);

			}else if(a==0){
				//2 for change
				int b, c, x;
				cin>>b>>c>>x;
				update2(arr, tree, 0, n-1, 0, b, c, x)
			}
		}
		*/
	}


}
