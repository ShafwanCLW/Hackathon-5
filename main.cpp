#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Student.h"
#include "NodeCourse.h"

using namespace std;

void functMenu(int &addRemoveSubmit){
	cout<<"\n\nFUNCTION         : FUNCTION NO.\n"
		<<"To Add course    :     1\n"
		<<"To Remove course :     0\n"
		<<"To Save Change   :     2\n\n";
	do{
		cout<<"Function No.       >> ";
		cin>>addRemoveSubmit;		
		if( (addRemoveSubmit < 0) || (addRemoveSubmit > 2) ){
			cout<<"\n^PLEASE RE-ENTER VALID FUNCTION NO. AS INSTRUCTION SHOWN ABOVE^\n\n";
		}
	}while( (addRemoveSubmit < 0) || (addRemoveSubmit > 2) );
	return;
}
void funct(NodeCourse list){//friend of NodeCourse to use the function inside class
	char courseType;
	//to find chosen Course to be add or delete for next step 
	string chosenCourse, gradeInsert;
	int addRemoveSubmit, function = 1;
	
	while( (function == 1) || (function == 2) ){
		list.resetCourseList();
		system("CLS");
		cout<<"---------------------------------- MENU -------------------------------\n"
			<<"No. | Function\n"
			<<" 1. | Student Registration System  - Register Your Course In The System\n"
			<<" 2. | Student GPA Calculator 	   - Calculate GPA Based On Your Grade\n"
			<<"-----------------------------------------------------------------------\n\n"
			<<"Function No. >> ";
		cin>>function;	
		system("CLS");
		
		switch(function){
			case 1 : 	do{
							list.printCourseList();		
							list.printCourseTaken();
							
							functMenu(addRemoveSubmit);

							if(addRemoveSubmit == 1){
								cout<<"Chosen Course Code >> ";
								cin>>chosenCourse;
								cout<<"Chosen Course Type >> ";
								cin>>courseType;
								list.addCourse(chosenCourse,courseType);
							}
							else if(addRemoveSubmit == 0){
								cout<<"Chosen Course Code >> ";
								cin>>chosenCourse;
								list.removeCourse(chosenCourse);

							}
							system("CLS");		
						}while(addRemoveSubmit != 2);
						
						list.printCourseTaken();
						cout<<"        Total Unit : "<<list.calculateTotalUnit()<<" Unit\n";
						cout<<"Total Course Taken : "<<list.calculateTotalCourseTaken()<<" Course\n\n";
					
						cout<<"Press ENTER To Continue To Home\n";
						cin.get();
						if(cin.get()){
							break;
						}
					 break;
			case 2 : 	do{
							list.printCourseList();		
							list.printGrade();

							functMenu(addRemoveSubmit);

							if(addRemoveSubmit == 1){
								cout<<"Chosen Course Code >> ";
								cin>>chosenCourse;
								cout<<"Grade Got           >> ";
								cin>>gradeInsert;	
								list.addGrade(chosenCourse, gradeInsert);;						
							}
							else if(addRemoveSubmit == 0){
								cout<<"Chosen Course Code >> ";
								cin>>chosenCourse;
								list.removeGrade(chosenCourse);
							}
							system("CLS");		
						}while(addRemoveSubmit != 2);
						list.printGrade();
						cout<<"GPA : "<<list.calculateGPA()<<endl;
						cout<<"Press ENTER To Continue To Home\n";
						cin.get();
						if(cin.get()){
							break;
						}
					 break;
			default: cout<<"INVALID FUNCTION NO.\n"; 
		}
	}
}

void studentInfo(string &userName, int &matricNo){
	cout<<"-- WELCOME TO COMPUTER SCIENCE STUDENT'S SYSTEM --\n\n";
	
	cout<<"Student Name >> ";
	getline(cin, userName);
	cout<<"Matric No.   >> ";
	cin>>matricNo;
	cout<<"\nPress [ENTER] To Submit";
	cin.get();
	if(cin.get()){
		return;
	}
	system("CLS");
}

int main(){
	//variable for studentInfo
	string userName;
	int matricNo;
	//variable to store course data from txt file to node
	string titleC, codeC;
	int unitC, CourseListTotal=20;	
	
	studentInfo(userName, matricNo);//
	
	NodeCourse list(userName,matricNo);//object of NodeCourse class

	ifstream inFile;
	inFile.open("CourseList.txt");
	if(inFile.is_open()){//read from txt file and store inside link list
		for(int count=0; count<CourseListTotal; count++){
			getline(inFile, titleC, '\t');
			getline(inFile, codeC, '\t');
			inFile>>unitC;
			inFile.ignore();
			
			list.insertEnd(titleC, codeC, unitC);
		}
	}
	inFile.close();
	
	funct(list);//All operation to register course and to calculate gpa 
	
	return 0;
}
