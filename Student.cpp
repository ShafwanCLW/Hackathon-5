#include <iostream>
#include "Student.h"

using namespace std;

void Student::setStudent(string studName, int studMatricNo){
	studentName = studName;
	studentMatricNo = studMatricNo;
}

void Student::printStudent(){
	cout<<"Student Name    : "<<studentName<<endl
		<<"Matric No.      : "<<studentMatricNo<<endl;
}
