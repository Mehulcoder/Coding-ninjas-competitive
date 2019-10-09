/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the
 profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250


*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct job{
    ll start, finish, profit;

    job(ll s, ll f, ll p){
        start = s;
        finish = f;
        profit = p;
    }
};

bool compare(job a, job b){
    return a.finish < b.finish;
}

ll search(vector<job> *input, ll limit, ll si, ll ei){
    if(si > ei) return -1;

    if(si == ei){
        if((input->at(si)).finish <= limit) return si;
        else return -1;
    }

    ll mid = (si+ei)/2;
    if((input->at(mid)).finish <= limit){
        ll answer = search(input, limit, mid+1, ei);
        if(answer == -1) return mid;
        else return answer;
    }
    else return search(input, limit, si, mid-1);
}

int main(){
    ll n;
    cin >> n;

    vector<job> input;
    for(ll i = 0; i < n; i++){
        ll s, f, p;
        cin >> s >> f >> p;
        input.push_back(job(s, f, p));
    }

    sort(input.begin(), input.end(), compare);

    ll *dp = new ll[n];
    dp[0] = input[0].profit;
    for(ll i = 1; i < n; i++){
        ll include = input[i].profit;

        ll id = -1;
        id = search(&input, input[i].start, 0, i-1);
        // for(ll j = i-1; j >= 0; j--){
        //     if(input[j].finish <= input[i].start){
        //         id = j;
        //         break;
        //     }
        // }

        if(id != -1){
            include += dp[id];
        }

        dp[i] = max(dp[i-1], include);
    }

    cout << dp[n-1] << endl;
}