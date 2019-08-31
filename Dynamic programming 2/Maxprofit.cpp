/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Mike is a stock trader and makes a profit by buying and selling stocks. He buys a stock at a lower price and sells it at a higher price to book a profit. He has come to know the stock prices of a particular stock for n upcoming days in future and wants to calculate the maximum profit by doing the right transactions (single transaction = buying + selling). Can you help him maximize his profit?
Note: A transaction starts after the previous transaction has ended. Two transactions can't overlap or run in parallel.
The stock prices are given in the form of an array A for n days.
Given the stock prices and a positive integer k, find and print the maximum profit Mike can make in at most k transactions.
Input Format
The first line of input contains an integer q denoting the number of queries.

The first line of each test case contains a positive integer k, denoting the number of transactions. 

The second line of each test case contains a positive integer n, denoting the length of the array A.

The third line of each test case contains n space-separated positive integers, denoting the prices of each day in the array A.
Constraints
1<=q<=100

0<k<10

2<=n<=30

0<=elements of array A<=1000
Output Format
For each query print the maximum profit earned by Mike on a new line. 
Sample Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25
Sample Output
87
1040
0

*/	


#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

int maxProfit(int *input, int id, int n, int k, bool buy, pii **memo){
    if(k == 0 || id == n) return 0;

    if(buy){
        if(memo[id][k].f != -1) return memo[id][k].f;
    }
    else{
        if(memo[id][k].s != -1) return memo[id][k].s;
    }

    if(buy){
        int a = maxProfit(input, id+1, n, k, false, memo)-input[id];
        int b = maxProfit(input, id+1, n, k, true, memo);
        memo[id][k].f = max(a, b);
        return max(a, b);
    }
    else{
        int a = input[id]+maxProfit(input, id+1, n, k-1, true, memo);
        int b = maxProfit(input, id+1, n, k, false, memo);
        memo[id][k].s = max(a, b);
        return max(a, b);
    }
}

int main(){
    int q;
    cin >> q;
    while(q--){
        int k, n;
        cin >> k >> n;

        int *input = new int[n];
        for(int i = 0; i < n; i++) cin >> input[i];

        pii **memo = new pii *[n+1];
        for(int i = 0; i <= n; i++){
            memo[i] = new pii[k+1];
            for(int j = 0; j <= k; j++){
                memo[i][j].f = -1;
                memo[i][j].s = -1;
            }
        }

        cout << maxProfit(input, 0, n, k, true, memo) << endl;
    }
}
