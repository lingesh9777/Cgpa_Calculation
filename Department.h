#ifndef DEPARTMENT_H
#define DEPARTMENT_H


#include "Semester.h"
#include<iostream>
#include <vector>
using namespace std;

class Department{
	vector<Semester> semesters;

public :
	Department(vector<vector<vector<string>>> Dep){
		
		for(int i=0;i<Dep.size();i++)
		{
			semesters.push_back(Semester(Dep[i]));
		}				
	}
	
	void display(){
		for(int i=0;i<semesters.size();i++)
		{
			cout<<"		SEMESTER  - "<<i+1 <<endl<<endl;
			semesters[i].display();
			cout<<endl<<endl<<endl<<endl;
		}
	}
	
	vector<Semester> getsemesters(){
		return semesters;
	}
};

#endif
