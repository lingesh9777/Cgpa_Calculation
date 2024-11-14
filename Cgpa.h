#ifndef CGPA_H
#define CGPA_A


#include <iostream>
#include <vector>
#include <unordered_map>
#include "Semester.h"
#include "Course.h"
using namespace std;

class Cgpa{
	
	vector<pair<int,int>> sgpa;
	int total_creditmark = 0;
	int total_credit = 0;
	unordered_map<string,int> grademarkmp;
	
	int grademark(string grade){
		return grademarkmp[grade];
	}
	
	pair<int,int> SgpaCalculate(Semester semesters){
		
		
		int credit = 0 ;
		int creditmark = 0;
		
		for(Course courses : semesters.getCourse()){
			string grade;
			cout<<"Enter "<<courses.getCcode()<<" "<<courses.getCname()<<" : ";
			cin>>grade;
			int crd = courses.getCredits();
			credit += crd;
			creditmark += crd * grademark(grade);
		}
			
		total_credit += credit;
		total_creditmark += creditmark;
		return make_pair(credit,creditmark);			
	}
	
	double cgpaCalc(double creditmarks , double credits){
		
		return creditmarks / credits;
	}
		
public : 
	Cgpa(){
		grademarkmp = {{"O",10},{"A+",9},{"A",8},{"B+",7},{"B",6},{"C",5},{"RA",0},{"AB",0}};
	}
	void Calculate(Department department){
		
		for(Semester sem : department.getsemesters()){
			
			sgpa.push_back(SgpaCalculate(sem));
			cout<<"Continue to next Semester ? \nPress 1 : continue ... Press 2 : break ... \nChoice : ";
			int choice;
			cin>>choice;
			if(choice!=1)
				break;
			cout<<endl;
			
		}
		cout<<endl;
		for(int i=0;i<sgpa.size();i++){
			cout<<"Sem "<< (i+1) << ", Sgpa : "<< cgpaCalc(sgpa[i].second,sgpa[i].first) <<endl;
		}
		
				
		cout<<"CGPA : "<< cgpaCalc(total_creditmark , total_credit) <<endl;
	}
};

#endif
