#ifndef NODECOURSE_H
#define NODECOURSE_H
#include <string>
#include "Student.h"

using namespace std;


//Class to store all related to course link list
class NodeCourse{
	private:
		Student stud;//declare variableName of class Student
		struct ListNode{//all information to store inside node
			string titleCourse, codeCourse, gradeCourse;
			char typeCourse;
			int unitCourse;
			ListNode* nextCourse;//to point to next node
		};
		ListNode* headCourse;			//head of link list store all course 
		ListNode* headStudentCourse;	//head of link list store only course taken (Registration)
		ListNode* headGrade;			//head of link list store only course taken (grade)
	public:
		NodeCourse(){// default constructor
			headCourse = NULL;
			headStudentCourse = NULL;
			headGrade = NULL;
		}
		NodeCourse(string studName, int studMatricNo){// parameterize constructor
			headCourse = NULL;
			headStudentCourse = NULL;
			headGrade = NULL;
			stud.setStudent(studName, studMatricNo);
		}
		//function declaration
		void insertEnd(string newtitle, string newCode, int newUnit);	//insert node course to all course list
		void addCourse(string chosenCourse, char courseType);			//insert node course to only course taken list (registration)
		void removeCourse(string chosenCourse);							//remove node course from course taken list (registration) and put back to node course of all course list
		void printCourseList();											//print node course of all course list
		void printCourseTaken();										//print node course of only course taken list (registration)
		int calculateTotalUnit();										//calculation of total unit
		int calculateTotalCourseTaken();								//calculation of total course taken
		void addGrade(string chosenCourse, string gradeInsert);			//insert node course to only course taken list (grade)
		void removeGrade(string chosenCourse);							//remove node course from course taken list (grade)
		void printGrade();												//print node course of only course taken list (grade
		float calculateGPA();											//calculation of gpa
		void resetCourseList();											//to reset list of all course
		friend void funct(NodeCourse);									//friend of function in main()
};

#endif
