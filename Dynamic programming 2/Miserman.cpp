/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
Jack is a wise and miser man. Always tries to save his money.
One day, he wants to go from city A to city B. Between A and B, there are N number of cities(including B and excluding A) and in each city there are M buses numbered from 1 to M. And the fare of each bus is different. Means for all N*M busses, fare (K) may be different or same. Now Jack has to go from city A to city B following these conditions:
1. At every city, he has to change the bus.
2. And he can switch to only those buses which have number either equal or 1 less or 1 greater to the previous.
You are to help Jack to go from A to B by spending the minimum amount of money.
N, M, K <= 100.
Input
Line 1:    N M

Line 2:    NxM Grid

Each row lists the fares the M busses to go form the current city to the next city.
Output
Single Line containing the minimum amount of fare that Jack has to give.
Sample Input
5 5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
Sample Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int findFare(int **input, int n, int m, int row, int col, int **dp){
    if(row == n) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if(col-1 >= 0) a = input[row][col]+findFare(input, n, m, row+1, col-1, dp);
    b = input[row][col]+findFare(input, n, m, row+1, col, dp);
    if(col+1 < m) c = input[row][col]+findFare(input, n, m, row+1, col+1, dp);

    dp[row][col] = min(a, min(b, c));
    return min(a, min(b, c));
}

int main(){
    int n, m;
    cin >> n >> m;

    int **input = new int *[n];
    for(int i = 0; i < n; i++){
        input[i] = new int[m];
        for(int j = 0; j < m; j++) cin >> input[i][j];
    }

    int **dp = new int *[n];
    for(int i = 0; i < n; i++) dp[i] = new int[m];

    int minFare = INT_MAX;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) dp[j][k] = -1;
        }

        minFare = min(minFare, findFare(input, n, m, 0, i, dp));
    }

    cout << minFare << endl;
}
