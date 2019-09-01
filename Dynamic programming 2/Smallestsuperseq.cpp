/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3.
*/
#include <bits/stdc++.h>

using namespace std;

int go(string s1, string s2, int i, int j, int** mem){
	int m = s1.size();
	int n = s2.size();

	//cout << m<<" "<<n << '\n';

	if (i > m-1)
	{
		return n-j;
	}

	if (j > n-1)
	{
		return m-i;
	}

	if (mem[i][j]!=-1)
	{
		return mem[i][j];
	}

	if (s1[i] == s2[j])
	{
		mem[i][j] = 1 + go(s1, s2, i+1, j+1, mem);
		return mem[i][j];
	}else{
		mem[i][j] = min(1+go(s1, s2, i+1, j, mem), 1+go(s1, s2, i, j+1, mem));
		return mem[i][j];
	}

}

int smallestSuperSequence(char str1[], int len1, char str2[], int len2) { 
  string s1 = "";
  string s2 = "";

  for (int i = 0; i < len1; ++i)
  {
  	s1 += str1[i];
  }

  for (int i = 0; i < len2; ++i)
  {
  	s2 += str2[i];
  }

  int** mem = new int*[len1+1];

  for (int i = 0; i < len1+1; ++i)
  {
  	mem[i] = new int[len2+1];
  	for (int j = 0; j < len2+1; ++j)
  	{
  		mem[i][j] = -1;
  	}
  }


  return go(s1, s2, 0, 0, mem);

  

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	char str1[50], str2[50];
    cin>>str1;
    cin>>str2;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = smallestSuperSequence(str1, len1, str2, len2);
    cout<<min_len<<endl;
    return 0;



	return 0 ; 



}
