#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course{
	private :
		string course_code;
		string course_name;
		int credit;
	
	public:
		Course(string course_code,string course_name,int credit):course_code(course_code),
				course_name(course_name),credit(credit){
		}
	
		string getCcode(){
			return course_code;
		}
		
		string getCname(){
			return course_name;
		}
		
		int getCredits(){
			return credit;
		}
	
};

#endif

