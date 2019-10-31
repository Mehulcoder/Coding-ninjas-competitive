/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int countPalindromes(string s) 
{
	int count  = 0;
    unordered_map<string, int> m; 
    for (int i = 0; i < s.length(); i++) { 
  
        // check for odd length palindromes 
        for (int j = 0; j <= i; j++) { 
  
            if (!s[i + j]) 
                break; 
  
            if (s[i - j] == s[i + j]) { 
  
                // check for palindromes of length 
                // greater than 1 
                if ((i + j + 1) - (i - j) > 1){ 
                    m[s.substr(i - j,  
                        (i + j + 1) - (i - j))]++; 
                    count++;
                }
  
            } else
                break; 
        } 
  
        // check for even length palindromes 
        for (int j = 0; j <= i; j++) { 
            if (!s[i + j + 1]) 
                break; 
            if (s[i - j] == s[i + j + 1]) { 
  
                // check for palindromes of length  
                // greater than 1 
                if ((i + j + 2) - (i - j) > 1) 
                    m[s.substr(i - j,  
                         (i + j + 2) - (i - j))]++; 
                count++;
  
            } else
                break; 
        } 
    } 
    return count; 
}
int countPalindromeSubstrings(char s[]) {
	string str;
	for (int i = 0; s[i]!='\0'; ++i)
	{
		str += s[i];
	}

	return countPalindromes(str)+str.size();
	
}
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;

	



	return 0 ; 



}

