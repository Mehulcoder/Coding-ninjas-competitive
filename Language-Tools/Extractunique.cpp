/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Given a string, you need to remove all the duplicates. 
That means, the output string should contain each character only once.
The respective order of characters should remain same.


*/


#include <bits/stdc++.h>

using namespace std;


char* uniqueChar(char *s){
	unordered_map<char, int> m1;
	
	char out[10000000];
	int j= 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		m1[s[i]]++;
		if (m1[s[i]]==1)
		{
			out[j] = s[i];
			j++;
		}

	}
	out[j]='\0';
	return out;

}
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;

	return 0 ; 



}
