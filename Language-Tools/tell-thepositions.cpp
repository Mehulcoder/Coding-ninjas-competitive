/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/

/*
				PROBLEM STATEMENT

In a class there are ‘n’ number of students. They have three different subjects: Data Structures, Algorithm Design & Analysis and Operating Systems.
Marks for each subject of all the students are provided to you. You have to tell the position of each student in the class. 
Print the names of each student according to their position in class. Tie is broken on the basis of their roll numbers. Between two students having same marks, 
the one with less roll number will have higher rank. The input is provided in order of roll number.

*/


#include <bits/stdc++.h>

using namespace std;

class student{
	public:
		string name;
		int marks;
		int roll;
};

bool mycompare(student a, student b){

	if (a.marks!=b.marks)
	{
		return (a.marks>b.marks);
	}else{
		return(a.roll<b.roll);
	}
	
}


int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n;
	std::cin>>n;

	//std::vector<string> name;		//ncross1
	std::vector<student> stud;			//ncross3

	for (int i = 0; i < n; ++i)
	{
		string temp_name;
		int sub1;
		int sub2;
		int sub3;
		cin>>temp_name>>sub1>>sub2>>sub3;

		int sum = sub1+sub2+sub3;

		student temp_sub;

		temp_sub.name = temp_name;
		temp_sub.marks = sum;
		temp_sub. roll = i+1;

		stud.push_back(temp_sub);
	}

	

	sort(stud.begin(), stud.end(), mycompare);

	for (int i = 0; i < n; ++i)
	{
		cout << i+1<<" "<<stud.at(i).name<<'\n';
		
	}


	

	return 0 ; 



}
