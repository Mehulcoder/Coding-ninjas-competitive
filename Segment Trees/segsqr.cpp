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
	int data;
};



//Type 1 for increment
//Type 2 for change

void update1(lazyclass* lazy, treeclass* tree, int start, int end, int treeNode, int left ,int right, int value){

	if (start>end)
	{
		return;
	}

	if (lazy[treeNode].data!=0 && lazy[treeNode].type == 1)
	{
		tree[treeNode].sumsquare += 2*lazy[treeNode].data*tree[treeNode].sum+lazy[treeNode].data*lazy[treeNode].data*(right-left+1);
		tree[treeNode].sum += lazy[treeNode].data*(right-left+1);

		if (start!=end)
		{
			lazy[2*treeNode+1].data += lazy[treeNode].data;
			lazy[2*treeNode+1].type = 1;
			lazy[2*treeNode+2].type = 1;
			lazy[2*treeNode+2].data += lazy[treeNode].data;
		}

		lazy[treeNode].data = 0;
	}
    
    if (lazy[treeNode].data!=0 && lazy[treeNode].type == 2)
	{
        int value = lazy[treeNode].data;
        tree[treeNode].sumsquare = (value * value) * (right-left+1);
        tree[treeNode].sum = value * (right-left +1);
		

		if (start!=end)
		{
			lazy[2*treeNode+1].data += lazy[treeNode].data;
			lazy[2*treeNode+1].type = 2;
			lazy[2*treeNode+2].type = 2;
			lazy[2*treeNode+2].data += lazy[treeNode].data;
		}

		lazy[treeNode].data = 0;
	}

	//No overlap
	if (left>end || right< start)
	{
		return;
	}

	//Full
	if (left<=start && right>=end)
	{
		tree[treeNode].sumsquare += 2*value*tree[treeNode].sum+value*value*(right-left+1);
		tree[treeNode].sum += value*(right-left+1);

		if(start!=end){
			lazy[treeNode*2+1].data += value;
			lazy[2*treeNode+1].type = 1;
			lazy[2*treeNode+2].type = 1;
			lazy[treeNode*2+2].data += value;
		}

		return;
	}

	//Partial
	int mid = (start+end)/2;

	update1(lazy, tree, start, mid, 2*treeNode+1, left, right, value);
	update1(lazy, tree, mid+1, end, 2*treeNode+2, left, right, value);

	tree[treeNode].sumsquare = tree[2*treeNode+1].sumsquare+tree[2*treeNode+2].sumsquare;
	tree[treeNode].sum = tree[2*treeNode+1].sum+tree[2*treeNode+2].sum;

	return;
}

void update2(lazyclass* lazy, treeclass* tree, int start, int end, int treeNode, int left ,int right, int value){

	if (start>end)
	{
		return;
	}

	if (lazy[treeNode].data!=0 && lazy[treeNode].type == 2)
	{
		tree[treeNode].sumsquare = lazy[treeNode].data*lazy[treeNode].data*(right-left+1);
		tree[treeNode].sum = lazy[treeNode].data*(right-left+1);

		if (start!=end)
		{
			lazy[2*treeNode+1].data = lazy[treeNode].data;
			lazy[2*treeNode+1].type = 2;
			lazy[2*treeNode+2].type = 2;
			lazy[2*treeNode+2].data = lazy[treeNode].data;
		}

		lazy[treeNode].data = 0;
		lazy[treeNode].type = 1;
	}

	//No overlap
	if (left>end || right< start)
	{
		return;
	}

	//Full
	if (left<=start && right>=end)
	{
		tree[treeNode].sumsquare = value*value*(right-left+1);
		tree[treeNode].sum = value*(right-left+1);

		if(start!=end){
			lazy[treeNode*2+1].data = value;
			lazy[treeNode*2+1].type = 2;
			lazy[treeNode*2+2].type = 2;
			lazy[treeNode*2+2].data = value;
		}

		return;
	}

	//Partial
	int mid = (start+end)/2;

	update2(lazy, tree, start, mid, 2*treeNode+1, left, right, value);
	update2(lazy, tree, mid+1, end, 2*treeNode+2, left, right, value);

	tree[treeNode].sumsquare = tree[2*treeNode+1].sumsquare+tree[2*treeNode+2].sumsquare;
	tree[treeNode].sum = tree[2*treeNode+1].sum+tree[2*treeNode+2].sum;

	return;
}

int query(lazyclass* lazy, treeclass* tree, int start, int end, int treeNode, int left ,int right){

	if (start>end)
	{
		return 0;
	}
	//Updation if value at lazytree is not zero
	if (lazy[treeNode].data!=0)
	{
		if (lazy[treeNode].type==1)		
		{
			tree[treeNode].sumsquare += 2*lazy[treeNode].data*tree[treeNode].sum+lazy[treeNode].data*lazy[treeNode].data*(right-left+1);
			tree[treeNode].sum += lazy[treeNode].data*(right-left+1);

			if (start!=end)
			{
				lazy[2*treeNode+1].data += lazy[treeNode].data;
				lazy[2*treeNode+1].type = 1;
				lazy[2*treeNode+2].type = 1;
				lazy[2*treeNode+2].data += lazy[treeNode].data;
			}

			lazy[treeNode].data = 0;
			
		}else{

			tree[treeNode].sumsquare = lazy[treeNode].data*lazy[treeNode].data*(right-left+1);
			tree[treeNode].sum = lazy[treeNode].data*(right-left+1);

			if (start!=end)
			{
				lazy[2*treeNode+1].data = lazy[treeNode].data;
				lazy[2*treeNode+1].type = 2;
				lazy[2*treeNode+2].type = 2;
				lazy[2*treeNode+2].data = lazy[treeNode].data;
			}

			lazy[treeNode].data = 0;
			lazy[treeNode].type = 1;

			}
	}

	//No overlap
	if (left>end || right< start)
	{
		return 0;
	}

	//Full
	if (left<=start && right>=end)
	{
		return tree[treeNode].sumsquare;
	}

	//Partial
	int mid = (start+end)/2;

	int l = query(lazy, tree, start, mid, 2*treeNode+1, left, right);
	int r = query(lazy, tree, mid+1, end, 2*treeNode+2, left, right);

	return l+r;
}

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
	int i=1;

	while(t--){
		cout << "Case "<<i<<":"<< '\n';
		i++;
		int n, q;
		cin>>n>>q;

		int* arr = new int[n];
		
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}

		treeclass* tree = new treeclass[4*n]();
		lazyclass* lazy = new lazyclass[4*n];

		create(arr, tree, 0, n-1, 0);
		// for (int i = 0; i < 4*n; ++i)
		// {
		// 	cout << "squares "<<tree[i].sumsquare<<" sum "<<tree[i].sum << '\n';
		// }

		while(q--){
			int a;
			cin>>a;

			if (a==2)
			{
				int b,c;
				cin>>b>>c;
				cout << query(lazy, tree, 0, n-1, 0, b-1, c-1) << '\n';

			}else if (a==1)
			{
				//1 forIncrement
				int b, c, x;
				cin>>b>>c>>x;
				update1(lazy, tree, 0, n-1, 0, b-1, c-1, x);

			}else if(a==0){
				//2 for change
				int b, c, x;
				cin>>b>>c>>x;
				update2(lazy, tree, 0, n-1, 0, b-1, c-1, x);
			}
		}

		//Printing

		// for (int i = 0; i < 4*n; ++i)
		// {
		// 	cout <<"I= "<<i <<" squares "<<tree[i].sumsquare<<" sum "<<tree[i].sum <<" Lazy Data "<<lazy[i].data<<" type "<<lazy[i].type<< '\n';
		// }
		
	}


}
