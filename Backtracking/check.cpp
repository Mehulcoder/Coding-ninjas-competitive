// CPP code to fill the crossword puzzle 
#include <bits/stdc++.h> 
using namespace std; 
  
// ways are to calculate the number of 
// possible ways to fill the grid 
int ways = 0; 
  
// this function is used to print 
// the resultant matrix 
void printMatrix(vector<string>& matrix, int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << matrix[i] << endl; 
} 
  
// this function checks for the current word 
// if it can be placed horizontally or not 
// x -> it represent index of row 
// y -> it represent index of column 
// currentWord -> it represent the 
// current word in word array 
vector<string> checkHorizontal(int x, int y, 
                               vector<string> matrix, 
                               string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x][y + i] == '-' ||  
            matrix[x][y + i] == currentWord[i]) { 
            matrix[x][y + i] = currentWord[i]; 
        } 
        else { 
  
            // this shows that word cannot  
            // be placed horizontally 
            matrix[0][0] = '+'; 
            return matrix; 
        } 
    } 
  
    return matrix; 
} 
  
// this function checks for the current word 
// if it can be placed vertically or not 
// x -> it represent index of row 
// y -> it represent index of column 
// currentWord -> it represent the 
// current word in word array 
vector<string> checkVertical(int x, int y, 
                             vector<string> matrix, 
                             string currentWord) 
{ 
    int n = currentWord.length(); 
  
    for (int i = 0; i < n; i++) { 
        if (matrix[x + i][y] == '-' ||  
            matrix[x + i][y] == currentWord[i]) { 
            matrix[x + i][y] = currentWord[i]; 
        } 
        else { 
  
            // this shows that word 
            // cannot be placed vertically 
            matrix[0][0] = '+'; 
            return matrix; 
        } 
    } 
    return matrix; 
} 
  
// this function recursively checks for every 
// word that can align vertically in one loop 
// and in another loop it checks for those words 
// that can align horizontally words -> it 
// contains all the words to fill in a crossword 
// puzzle matrix -> it contain the current 
// state of crossword index -> it represent 
// the index of current word n -> it represent 
// the length of row or column of the square matrix 
void solvePuzzle(vector<string>& words, 
                 vector<string> matrix, 
                 int index, int n) 
{ 
    if (index < words.size()) { 
        string currentWord = words[index]; 
        int maxLen = n - currentWord.length(); 
  
        // loop to check the words that can align vertically. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkVertical(j, i, 
                                        matrix, currentWord); 
  
                if (temp[0][0] != '+') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
  
        // loop to check the words that can align horizontally. 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j <= maxLen; j++) { 
                vector<string> temp = checkHorizontal(i, j, 
                                      matrix, currentWord); 
  
                if (temp[0][0] != '+') { 
                    solvePuzzle(words, temp, index + 1, n); 
                } 
            } 
        } 
    } 
    else { 
        // calling of print function to 
        // print the crossword puzzle 
        cout << (ways + 1) << " way to solve the puzzle "
             << endl; 
        printMatrix(matrix, n); 
        cout << endl; 
  
        // increase the ways 
        ways++; 
        return; 
    } 
} 
  
// Driver Code 
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