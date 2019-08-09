/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT
Ayush loves the characters ‘a’, ‘s’, and ‘p’. 
He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ 
occurs in the string respectively. Help him find it out.
*/
#include <bits/stdc++.h>

using namespace std;


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	cin>>n;
	string s;
	std::cin>>s;

	unordered_map<char, int> m1;

	for (int i = 0; i < s.size(); ++i)
	{
		m1[s[i]]++;
	}

	cout << m1['a']<<" "<<m1['s']<<" "<<m1['p'] << '\n';

	return 0 ; 



}
