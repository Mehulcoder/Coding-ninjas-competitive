/*
 
				Name: Mehul Chaturvedi
				IIT-Guwahati
 
*/
 
/*
				PROBLEM STATEMENT
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on 
down to ‘Z’ being assigned 26.”
 
Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could 
decode that in many different ways!”
 
Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, 
‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’. I think you would be able to figure out the correct decoding. 
And why would you send me the word ‘BEAN’ anyway?”
 
Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there 
would be tons of different decodings and with that many you would find at least two different 
ones that would make sense.”
 
Alice: “How many different decodings?”
 
Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that 
will determine how many decodings there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 
digits representing a valid encryption (for example, no line will begin with a 0). There will be 
no spaces between the digits. An input line of ‘0’ will terminate the input and should not be 
processed.
Output
For each input set, output the number of possible decodings for the input string. Prlong long your 
answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
 
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
long long go(string a){
	long long n = a.size();
	//cout << a[n] << '\n';
 
	vector<long long> dp(n+2,0);
 
	dp[n] = 1;
    if(a.at(n-1)=='0'){
        dp[n] = 0;
    }
	dp[n+1] = 0;
 
	for (long long i = n-1; i > 0; --i)
	{
		// 1) if a[i-1] is in range (1 to 9)
		if (a.at(i-1) == '0')
		dp.at(i)=0;
        else
        dp.at(i)=dp.at(i+1);
 
        // 2) if a[i-1]*10+a[i] is in range (10 to 26)
 
		if ((a[i-1]-'0')*10+(a[i]-'0')<=26 && (a[i-1]-'0')*10+(a[i]-'0')>=10)
		{
			if(i!=n-1){
			dp.at(i) += dp.at(i+2);
			}else{
				dp.at(i)++;
			}
            dp.at(i)%=1000000007;
		}
 
		// both 1) and 2) conditions calculate answer for (1 to 9) and (10 to 26)
		// overall answer for (1 to 26) is calculated
	}
 
	return dp.at(1)%1000000007;;
 
}
 
 
int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
 
	std::vector<string> v;
	string a;
	cin>>a;
 
	while(a!="0"){
		v.push_back(a);
		cin>>a;
	}
 
	for (long long i = 0; i < v.size(); ++i)
	{
		cout << go(v.at(i)) << '\n';
	}
	return 0 ;
}