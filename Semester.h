#ifndef SEMESTER_H
#define SEMESTER_H

#include<vector>
#include "Course.h"

class Semester{
	private :
		vector<Course> courses;
	
	public :
		Semester(vector<vector<string>> sem){
					
			for(int i=0;i<sem.size();i++){
				courses.push_back(Course(sem[i][0],sem[i][1],stoi(sem[i][2])));
			}
			
		}
		
		void display(){
			cout<<"CourseCode	CourseName			Credits"<<endl;
			for(Course course:courses){
				cout<<course.getCcode()<<"	 	"<<course.getCname()<<"		"<<course.getCredits()<<endl;	
			}
		}
		
		vector<Course> getCourse(){
			return courses;
		}
};
#endif
