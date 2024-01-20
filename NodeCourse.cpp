#include <iostream>
#include <iomanip>
#include <string>
#include "NodeCourse.h"

using namespace std;

void NodeCourse::insertEnd(string newtitle, string newCode, int newUnit){
	ListNode* newNode = new ListNode;
	ListNode* last = headCourse;
	
	//store info
	newNode->codeCourse = newCode;
	newNode->unitCourse = newUnit;
	newNode->titleCourse = newtitle;
	newNode->typeCourse = '-';
	
	newNode->nextCourse = NULL;
	
	if(headCourse == NULL){//
		headCourse = newNode;
		return;
	}
	
	while(last->nextCourse != NULL){
		last = last->nextCourse;
	}
	last->nextCourse = newNode;
	return;
}

void NodeCourse::addCourse(string chosenCourse, char courseType){
	ListNode* markCourse = headCourse;
	ListNode* prevNode = NULL;
	ListNode* lastNode = headStudentCourse;
	
	
	if(headStudentCourse == NULL){ //if there is no course yet added
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if mark course is point at headCourse	
			headCourse = markCourse->nextCourse;
			headStudentCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
		else{//if mark course not point to chosen course
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			headStudentCourse = markCourse;// head student course will point at mark course
			markCourse->nextCourse=NULL;
		}
		markCourse->typeCourse = courseType;
		return;
	}
	
	else{//add more course after at least one course added
		while(lastNode->nextCourse != NULL){//lastNode will point to last node of student course node
			lastNode = lastNode->nextCourse;
		}
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if mark course and chosen course is point at headCourse
			headCourse = markCourse->nextCourse;
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
		else{//if mark course chosen course not point at headCourse
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){ //If User input invalid
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
	}

	markCourse->typeCourse = courseType;
}

void NodeCourse::removeCourse(string chosenCourse){
	ListNode* markCourse = headStudentCourse;
	ListNode* prevNode = NULL;
	ListNode* lastNode = headCourse;


	if(headCourse == NULL){ //if there is no course left to be added
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if chosen course is point at headStudentCourse
			headStudentCourse = markCourse->nextCourse;
			headCourse = markCourse;
			markCourse->nextCourse = NULL;
		}
		else{//if chosen course not point at headStudentCourse
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			headCourse = markCourse;// head student course will point at mark course
			markCourse->nextCourse=NULL;
		}
		markCourse->typeCourse = '-';
		return;
	}
	
	else{//if there is at least 1 course at headCourse
		while(lastNode->nextCourse != NULL){//lastNode will point to last node of course node
			lastNode = lastNode->nextCourse;
		}
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if chosen course is point at headStudentCourse
			headStudentCourse = markCourse->nextCourse;
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
		else{//if mark course chosen course not point at headStudentCourse
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed at chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
	}

	markCourse->typeCourse = '-';
}

void NodeCourse::printCourseList(){
	ListNode* printptr =  headCourse;
	cout<<"-------------------------------------------COURSE LIST-----------------------------------------\n";
	cout<<"###############################################################################################";
	cout<<setw(51)<<left<<"\nCOURSE TITLE "<<"| COURSE CODE\t| COURSE UNIT\t| COURSE TYPE | \n\n";
	if(headCourse == NULL){//When user add all course
			cout<<"-----------------------------------------NO COURSE LEFT----------------------------------------\n";
	}
	while (printptr!=NULL){
		cout<<setw(50)<<left<< printptr->titleCourse<<setw(4)<<left<<"|"
			<< printptr->codeCourse <<setw(8)<<left<<"\t| "
			<< printptr->unitCourse <<setw(8)<<left<<"\t| "<<setw(7)<<left
			<< printptr->typeCourse <<"|\n";
		printptr=printptr->nextCourse;
	}		
	cout<<"###############################################################################################\n\n\n\n";
}

void NodeCourse::printCourseTaken(){
	ListNode* printptr =  headStudentCourse;
	stud.printStudent();
	cout<<"-------------------------------------STUDENT COURSE LIST---------------------------------------\n";
	cout<<"###############################################################################################";
	cout<<setw(51)<<left<<"\nCOURSE TITLE "<<"| COURSE CODE\t| COURSE UNIT\t| COURSE TYPE | \n\n";
	if(headStudentCourse == NULL){
			cout<<"--------------------------------------NO COURSE ADDED YET--------------------------------------\n";
	}
	while (printptr!=NULL){
		cout<<setw(50)<<left<< printptr->titleCourse<<setw(4)<<left<<"|"
			<< printptr->codeCourse <<setw(8)<<left<<"\t| "
			<< printptr->unitCourse <<setw(8)<<left<<"\t| "<<setw(7)<<left
			<< printptr->typeCourse <<"|\n";
		printptr=printptr->nextCourse;
	}	
	cout<<"###############################################################################################\n\n";
}

int NodeCourse::calculateTotalUnit(){
	ListNode* nodePtr = headStudentCourse;
	int totalUnit = 0;
	while(nodePtr != NULL){
		totalUnit = totalUnit + nodePtr->unitCourse ;
		nodePtr = nodePtr->nextCourse;
	}
	return totalUnit;
}

int NodeCourse::calculateTotalCourseTaken(){
	ListNode* nodePtr = headStudentCourse;
	int totalCourse = 0;
	while(nodePtr != NULL){
		totalCourse++;
		nodePtr = nodePtr->nextCourse;
	}
	return totalCourse;
}

void NodeCourse::addGrade(string chosenCourse, string gradeInsert){
	ListNode* markCourse = headCourse;
	ListNode* prevNode = NULL;
	ListNode* lastNode = headGrade;
	
	if((gradeInsert == "A") || (gradeInsert == "A-") || (gradeInsert == "B+") || (gradeInsert == "B") || (gradeInsert == "B-") || (gradeInsert == "C+") || 
		(gradeInsert == "C") || (gradeInsert == "C-") || (gradeInsert == "D+") || (gradeInsert == "D") || (gradeInsert == "D-") || (gradeInsert == "F")){
		if(headGrade == NULL){ //if there is no course yet chosen
			if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if markCourse is point at headCourse	
				headCourse = markCourse->nextCourse;
				headGrade = markCourse;
				markCourse->nextCourse=NULL;
			}
			else{//if mark course not point to chosen course
				while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
					prevNode = markCourse;
					markCourse = markCourse->nextCourse;
				}
				if(markCourse == NULL){
					cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
					cin.get();
					if(cin.get()){
						return;
					}
					return;
				}
				prevNode->nextCourse = markCourse->nextCourse;// link course back
				headGrade = markCourse;// head student course will point at mark course
				markCourse->nextCourse=NULL;
			}
			markCourse->gradeCourse = gradeInsert; 
			return;
		}
	
		else{//add more course after at least one course added
			while(lastNode->nextCourse != NULL){//lastNode will point to last node of student course node
				lastNode = lastNode->nextCourse;
			}
			if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if mark course and chosen course is point at headCourse
				headCourse = markCourse->nextCourse;
				lastNode->nextCourse = markCourse;
				markCourse->nextCourse=NULL;
			}
			else{//if mark course chosen course not point at headCourse
				while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
					prevNode = markCourse;
					markCourse = markCourse->nextCourse;
				}
				if(markCourse == NULL){ //If User input invalid
					cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
					cin.get();
					if(cin.get()){
						return;
					}
					return;
				}
				prevNode->nextCourse = markCourse->nextCourse;// link course back
				lastNode->nextCourse = markCourse;
				markCourse->nextCourse=NULL;
			}
		}
		markCourse->gradeCourse = gradeInsert; 		
	}
	else{
		cout<<"INVALID GRADE . PRESS [ENTER] TO CONTINUE\n";
		cin.get();
		if(cin.get()){
			return;
		}
		return;
	}	

}

void NodeCourse::removeGrade(string chosenCourse){
	ListNode* markCourse = headGrade;
	ListNode* prevNode = NULL;
	ListNode* lastNode = headCourse;


	if(headCourse == NULL){ //if there is no course left to be added
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if chosen course is point at headGrade
			headGrade = markCourse->nextCourse;
			headCourse = markCourse;
			markCourse->nextCourse = NULL;
		}
		else{//if chosen course not point at headGrade
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed o chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			headCourse = markCourse;// head student course will point at mark course
			markCourse->nextCourse=NULL;
		}
		markCourse->typeCourse = '-';
		return;
	}
	
	else{//if there is at least 1 course at headCourse
		while(lastNode->nextCourse != NULL){//lastNode will point to last node of course node
			lastNode = lastNode->nextCourse;
		}
		if(markCourse != NULL && markCourse->codeCourse == chosenCourse){//if chosen course is point at headGrade
			headGrade = markCourse->nextCourse;
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
		else{//if mark course chosen course not point at headGrade
			while(markCourse != NULL && markCourse->codeCourse != chosenCourse){//find chosen course and stop when mark course pointed at chosen course, prev course is previous of mark course
				prevNode = markCourse;
				markCourse = markCourse->nextCourse;
			}
			if(markCourse == NULL){
				cout<<"INVALID COURSE CODE . PRESS [ENTER] TO CONTINUE\n";
				cin.get();
				if(cin.get()){
					return;
				}
				return;
			}
			prevNode->nextCourse = markCourse->nextCourse;// link course back
			lastNode->nextCourse = markCourse;
			markCourse->nextCourse=NULL;
		}
	}
	markCourse->typeCourse = '-';
}

void NodeCourse::printGrade(){
	ListNode* printptr =  headGrade;
	stud.printStudent();
	cout<<"-------------------------------------STUDENT GPA CALCULATOR-------------------------------------\n";
	cout<<"################################################################################################";
	cout<<setw(51)<<left<<"\nCOURSE TITLE "<<"| COURSE CODE\t| COURSE UNIT\t| COURSE GRADE | \n\n";
	if(headGrade == NULL){
			cout<<"--------------------------------------NO COURSE ADDED YET---------------------------------------\n";
	}
	while (printptr!=NULL){
		cout<<setw(50)<<left<< printptr->titleCourse<<setw(4)<<left<<"|"
			<< printptr->codeCourse <<setw(8)<<left<<"\t| "
			<< printptr->unitCourse <<setw(8)<<left<<"\t| "<<setw(8)<<left
			<<fixed<<setprecision(2)<< printptr->gradeCourse <<"|\n";
		printptr=printptr->nextCourse;
	}	
	cout<<"################################################################################################\n\n";
}

float NodeCourse::calculateGPA(){
	ListNode* nodePtr = headGrade;
	float totalGrade = 0.0, gradeValue = 0.0, totalGPA=0.0, totalUnit=0.0;
	while(nodePtr != NULL){
		if(nodePtr->gradeCourse == "A"){
			gradeValue = 4.00;
		}
		else if(nodePtr->gradeCourse == "A-"){
			gradeValue = 3.67;
		}
		else if(nodePtr->gradeCourse == "B+"){
			gradeValue = 3.33;
		}
		else if(nodePtr->gradeCourse == "B"){
			gradeValue = 3.00;
		}
		else if(nodePtr->gradeCourse == "B-"){
			gradeValue = 2.67;
		}
		else if(nodePtr->gradeCourse == "C+"){
			gradeValue = 2.33;
		}
		else if(nodePtr->gradeCourse == "C"){
			gradeValue = 2.00;
		}
		else if(nodePtr->gradeCourse == "C-"){
			gradeValue = 1.67;
		}
		else if(nodePtr->gradeCourse == "D+"){
			gradeValue = 1.33;
		}
		else if(nodePtr->gradeCourse == "D"){
			gradeValue = 1.00;
		}
		else if(nodePtr->gradeCourse == "D-"){
			gradeValue = 0.67;
		}
		else if(nodePtr->gradeCourse == "F"){
			gradeValue = 0.00;
		}
		totalGrade = totalGrade + (gradeValue * nodePtr->unitCourse);
		totalUnit = totalUnit + nodePtr->unitCourse ;
		nodePtr = nodePtr->nextCourse;
	}
	totalGPA = totalGrade / totalUnit;
	return totalGPA;
}

void NodeCourse::resetCourseList(){
	//To make sure there is nothing pointed by headStudentCourse
	ListNode* lastNode_1 = headCourse;
	if(headStudentCourse != NULL){//reset headStudentCourse node
		while(lastNode_1->nextCourse != NULL){//Find last node for course list 
			lastNode_1 = lastNode_1->nextCourse;
		}
		lastNode_1->nextCourse = headStudentCourse;
		headStudentCourse = NULL;
	}
	if(headGrade != NULL){//reset headGrade node
		while(lastNode_1->nextCourse != NULL){//Find last node for course list 
			lastNode_1 = lastNode_1->nextCourse;
		}
		lastNode_1->nextCourse = headGrade;	
		headGrade = NULL;
	}
	
	lastNode_1 = headCourse;//point back lastNode_1 to headCourse
	while(lastNode_1 != NULL){//to reset value in typeCourse and gradeCourse
		lastNode_1->typeCourse = '-';//reset typeCourse
		lastNode_1->gradeCourse = "";//reset gradeCourse
		lastNode_1 = lastNode_1->nextCourse;
	}	
}

