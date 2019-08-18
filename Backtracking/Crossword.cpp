/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
				PROBLEM STATEMENT
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its 
cell values. Now, you are also provided with word list which needs to placed accurately in 
the grid. Cells marked with '-' are to be filled with word list.
For example: The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contains crossword. Each of 10 lines have a character array of 
size 10. Input characters are either '+' or '-'.
Next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

*/

#include <bits/stdc++.h>

using namespace std;

bool check_vertical(vector<string> matrix, int x, int y, string current_word, vector<bool>& checker){
	int n=matrix.size();

	if (x<0 || y<0 || x>=n || y>=n)
	{
		return 0;
	}

	if (current_word.size()==1)
	{
		if (matrix[x][y]=='-')
		{
			matrix[x][y]=current_word.substr(0,1);
			checker.push_back(1);
			return 1;

		}else if (matrix[x][y]==current_word.substr(0,1))
		{
			checker.push_back(0);
			return 1;
		}

		return 0;
	}

	int small = check_vertical(matrix, x, y, current_word.substr(0,1));
	int recur = check_vertical(matrix, x, y+1, current_word.substr(1, n-1));

	return(small && recur);
}

void reset_horizontal(vector<string> matrix, int x, int y, vector<bool> checker, int i){
	if (i>=checker.size())
	{
		return;
	}

	if (checker[i]==1)
	{
		matrix[x][y]='-';
		i++;
	}else{
		i++;
	}

	reset_horizontal(matrix, x+1, y, checker , i);
}

void reset_vertical(vector<string> matrix, int x, int y, vector<bool> checker, int i){
	if (i>=checker.size())
	{
		return;
	}

	if (checker[i]==1)
	{
		matrix[x][y]='-';
		i++;
	}else{
		i++;
	}

	reset_vertical(matrix, x, y+1, checker , i);

}

bool check_horizontal(vector<string> matrix, int x, int y, string current_word){
	int n=matrix.size();

	if (x<0 || y<0 || x>=n || y>=n)
	{
		return 0;
	}

	if (current_word.size()==1)
	{
		if (matrix[x][y]=='-')
		{
			checker.push_back(1);
			matrix[x][y]=current_word.substr(0,1);
			return 1;

		}else if (matrix[x][y]==current_word.substr(0,1))
		{
			checker.push_back(0);
			return 1;
		}

		return 0;
	}

	int small = check_vertical(matrix, x, y, current_word.substr(0,1));
	int recur = check_vertical(matrix, x+1, y, current_word.substr(1, n-1));

	return(small && recur);
}

void solvePuzzle(vector<string> words, vector<string>matrix, int a, int n){
	for (int p = 0; p < words.size(); ++p)
	{
		string current_word = words.at(i);
		
		

	}


}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ;
	int n1 = 10;
	
	std::vector<string> matrix;
	for (int i = 0; i < n1; ++i)
	{
		string temp;
		std::cin>>temp;
		matrix.push_back(temp);
	}

	vector<string> words;
	string temp_input;
	cin>>temp_input;

	string buffer = "";

	for (int i = 0; i < temp_input.size(); ++i)
	{
		if (i==temp_input.size()-1)
		{
			buffer = buffer+temp_input[i];
			words.push_back(buffer);
			break;
		}

		if (temp_input[i] == ',')
		{
			words.push_back(buffer);
			buffer = "";
			continue;
		}
		
		buffer = buffer+temp_input[i];
	}

	solvePuzzle(words, matrix, 0, n1);

	return 0 ; 



}
