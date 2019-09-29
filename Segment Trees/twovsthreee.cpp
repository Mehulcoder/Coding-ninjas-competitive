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
typedef long long ll;
#define pb push_back

int power[100001];

void buildPower(){
    power[0] = 1;
    for(int i = 1; i < 100001; i++) power[i] = (power[i-1]*2)%3;
}

void buildTree(int *tree, int *input, int si, int ei, int id){
    if(si == ei) tree[id] = input[si];
    else{
        int mid = (si+ei)/2;
        buildTree(tree, input, si, mid, 2*id);
        buildTree(tree, input, mid+1, ei, 2*id+1);

        tree[id] = (power[ei-mid]*tree[2*id] + tree[2*id+1])%3;
    }
}

int query(int *tree, int si, int ei, int id, int left, int right){
    if(si > right || ei < left) return 0;
    else if(si >= left && ei <= right) return (tree[id]*power[right-ei])%3;

    int mid = (si+ei)/2;

    int x = query(tree, si, mid, 2*id, left, right);
    int y = query(tree, mid+1, ei, 2*id+1, left, right);
    return (x+y)%3;
}

void update(int *tree, int *input, int si, int ei, int id, int key){
    if(si == ei){
        input[key] = 1;
        tree[id] = 1;
    }
    else{
        int mid = (si+ei)/2;
        if(si <= key && mid >= key) update(tree, input, si, mid, 2*id, key);
        else update(tree, input, mid+1, ei, 2*id+1, key);

        tree[id] = (power[ei-mid]*tree[2*id] + tree[2*id+1])%3;
    }
}

int main(){
    buildPower();

    int n;
    scanf("%d", &n);

    string s;
    cin >> s;
    int *input = new int[n];
    for(int i = 0; i < n; i++) input[i] = s[i]-'0';

    int *tree = new int[4*n];
    buildTree(tree, input, 0, n-1, 1);

    int q, type, key, left, right;
    scanf("%d", &q);
    while(q--){
        scanf("%d", &type);
        if(type == 0){
            scanf("%d%d", &left, &right);
            printf("%d\n", query(tree, 0, n-1, 1, left, right));
        }
        else{
            scanf("%d", &key);
            if(input[key] == 0) update(tree, input, 0, n-1, 1, key);
        }
    }
}