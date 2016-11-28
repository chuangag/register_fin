#ifndef _OBJECTS_H
#define _OBJECTS_H
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;
const int LENOFSTUID=8;

/*TODO:
 remember delete function should both delete the type table and the course selection linked list ok
 
 remember the existence is checked when getting from sorted list so not mind it ok
 
 *****set functions should include checking valid input ok
 */
bool is_number(const string& s);
bool is_upper_or_number(const string& s);

//-------------------class Student

class Student
{
public:
    /*a static Student for some function to return when the student to find not exist, 
     * this prevent from returning a local variable by reference, 
     * which will cause serious problem*/
    static Student notPrint;
    //contructor and destructor
    Student(string StuID=""){
        StudentID=StuID;
        canPrint=true;
        Year=0;
        notPrint.setcanPrintToFalse();
    }
    ~Student(){}
    
    //get functions
    string getStudentID() const{return StudentID;}
    string getStudentName() const{return StudentName;}
    int getYear() const{return Year;}
    char getGender()const{return Gender;}
    string getFullGender()const;
    string getHashKey()const{return HashKey;}
    bool getCanPrint(){return canPrint;}
    
    //set functions(include checking)
    void setcanPrintToFalse(){canPrint=false;}
    void setStudentID(string &StuID);
    void setStudentName(string &StuName);
    void setYear(string &y);
    void setGender(string &g);
    
    //overload operators
    bool operator==(const Student& stu) const;
    bool operator<(const Student& stu) const;
    
    //print functions
    void print_not_exist();
    void print_exist();
    void print_insert_success();
    void print_delete_success();
    void print_modify_success();
    void print_Query();
private:
    string StudentID;//length=8
    string StudentName;//1<=length<=32
    int Year;//{1,2,3}
    char Gender;//M or F
    string HashKey;//StudentID
    bool canPrint;
};






//class Course
class Course
{
public:
  /*a static Course for some function to return when the student to find not exist, 
     * this prevent from returning a local variable by reference, 
     * which will cause serious problem*/
    static Course notPrint;
    //contructor and destructor
    Course(string CCode=""){
        CourseCode=CCode;
        canPrint=true;
        Credit=-1;
        notPrint.setcanPrintToFalse();
    }
    ~Course(){}
    //get functions
    string getCourseCode() const{return CourseCode;}
    string getCourseName() const{return CourseName;}
    int getCredit() const{return Credit;}
    string getHashKey() const{return HashKey;}
    bool getCanPrint(){return canPrint;}
    
    //set functions
    void setcanPrintToFalse(){canPrint=false;}
    void setCourseCode(string &CCode);
    void setCourseName(string &CName);
    void setCredit(string &credit);
    
    //overload operators
    bool operator==(const Course& cour) const;
    bool operator<(const Course& cour) const;
    
    //print functions
    void print_not_exist();
    void print_exist();
    void print_insert_success();
    void print_delete_success();
    void print_modify_success();
    void print_Query();
private:
    string CourseCode;//len=7 or 8,first four are upper letters
    string CourseName;//1<=len<=50
    int Credit;//{0,1,2,3,4,5}
    string HashKey;//CourseCode
    bool canPrint;
};





#endif
