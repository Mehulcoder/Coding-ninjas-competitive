/*Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/


#include<iostream>
using namespace std;

string getKeypadString(int c){
    if(c==2) return "abc";
    else if (c==3) return "def";
    else if (c==4) return "ghi";
    else if (c==5) return "jkl";
    else if (c==6) return "mno";
    else if (c==7) return "pqrs";
    else if (c==8) return "tuv";
    else if (c==9) return "wxyz";
    else return "";
}

int32_t keypad(int n,string output[]){
    if(n==0){
        cout<<"";
        return 1 ;
    }

    int smallNumber = n/10;
    int lastDigit = n % 10;

    int smallerOutput = keypad(smallNumber,output);
    string temp[smallerOutput*getKeypadString(lastDigit).length()];

    int k=0;
    for (int i = 0;i<=smallerOutput-1;i++){
        for(int j=0;j<getKeypadString(lastDigit).length();j++){
            temp[k] = output[i] + getKeypadString(lastDigit)[j];
            k++;
        }
    }

    for (int i = 0;i<=smallerOutput*getKeypadString(lastDigit).length()-1;i++){
        output[i] = temp[i];
        cout<<output[i]<<" ";
    }
    return smallerOutput*getKeypadString(lastDigit).length();
}

int getNumberLength(int n){
    if(n==0)
        return 1;
    else{
       return  getNumberLength(n/10) * getKeypadString(n%10).length();
    }
}

int main(){
    int n;
    cin >> n;
    int size = getNumberLength(n);

    // cout << size;

    string *output= new string[size];
    // string output[size];
    keypad(n,output);
    for(int i=0;i<size;i++){
        cout<<output[i]<<endl;
    }

    delete[] output;
    
}

