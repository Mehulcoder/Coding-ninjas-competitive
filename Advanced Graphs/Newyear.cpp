/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    // int **graph = new int*[n];
    // for(int i = 0; i < n; i++){
    //     graph[i] = new int[n];
    //     for(int j = 0; j < n; j++) graph[i][j] = 0;
    // }

    int position = 0;

    for(int i = 0; i < n-1; i++){
        if(position == t-1){
            cout << "YES" << endl;
            return 0;
        }
        int a;
        cin >> a;
        // graph[i][i+a] = 1;
        if(i == position) position += a;
    }

    cout << "NO" << endl;
}
