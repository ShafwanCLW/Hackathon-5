#ifndef STUDENT_H
#define STUDENT_H
#include <string>

using namespace std;
//Class to store student information
class Student{
	private:
		string studentName;
		int studentMatricNo;
	public:
		Student(){
			studentName = "";
			studentMatricNo = 0;
		}
		void setStudent(string studName, int studMatricNo);
		void printStudent();
};
#endif
