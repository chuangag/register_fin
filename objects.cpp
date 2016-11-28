#include "objects.h"

/*check if a string is int number*/
bool is_number(const string& s)
{   if(s.empty())
        return false;
    for(int i=0;i<s.length();i++){
        if(s[i]>57||s[i]<48){
            return false;
        }
    }
    return true;
}

bool is_upper_or_number(const string& s){
  if(s.empty())
        return false;
  for(int i=0;i<s.length();i++){
        if(!((s[i]<='9'&&s[i]>='0')||(s[i]<='Z'&&s[i]>='A'))){
            return false;
        }
    }
  return true;
}

//implementation of class Student
Student Student::notPrint;

    string Student::getFullGender()const{
	    if(Gender=='M'){
		return "Male";
	    }
	    else
		return "Female";
	}
    void Student::setStudentID(string &StuID){
	    while(StuID.length()!=8||!is_number(StuID)){
		cout<<"Invalid input, re-enter again [student ID]: ";
		getline(cin,StuID);
	    }
	    StudentID=StuID;
	    HashKey=StudentID;
	}
    void Student::setStudentName(string &StuName){
	    while(StuName.length()>32||StuName.length()<1){
		cout<<"Invalid input, re-enter again [student name]: ";
		getline(cin,StuName);
	    }
	    StudentName=StuName;
	}
    
    void Student::setYear(string &y){
        while(!is_number(y)||(stoi(y)>3||stoi(y)<1)){
            cout<<"Invalid input, re-enter again [student year]: ";
            getline(cin,y);
        }
        Year=stoi(y);
    }
    
    void Student::setGender(string &g){
        while(g!="M"&&g!="m"&&g!="F"&&g!="f"){
            cout<<"Invalid input, re-enter again [M,F]: ";
            getline(cin,g);
        }
        if(g=="f")
            Gender='F';
        if(g=="m")
            Gender='M';
        Gender=g[0];
    }
    //overload operators
    bool Student::operator==(const Student& stu) const{//compare by studentID
        if(this->getStudentID()==stu.getStudentID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool Student::operator<(const Student& stu) const{//compare by studentID
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getStudentID()[i]<stu.getStudentID()[i]){
                return true;
            }
            else if(this->getStudentID()[i]>stu.getStudentID()[i])
                return false;
        }
        return false;
    }
    
    
    //print functions
    
    
    void Student::print_not_exist(){
        cout<<"Student not exist"<<endl;
    }
    
    void Student::print_exist(){
        cout<<"Student already exist"<<endl;
    }
    
    void Student::print_insert_success(){
        cout<<"Creation of student record successful"<<endl;
    }
    
    void Student::print_delete_success(){
        cout<<"Deletion of student record successful"<<endl;
    }
    
    void Student::print_modify_success(){
        cout<<"Modification of student record successful"<<endl;
    }
    
    void Student::print_Query(){
        if(!canPrint||Year==0){return;}
        cout<<"ID:     "<<StudentID<<endl;
        cout<<"Name:   "<<StudentName<<endl;
        cout<<"Year:   "<<Year<<endl;
        if(Gender=='M'){
            cout<<"Gender: "<<"Male"<<endl;
        }
        else if(Gender=='F'){
            cout<<"Gender: "<<"Female"<<endl;
        }
    }    
    
    
    
//implementation of class Course

Course Course::notPrint;

void Course::setCourseCode(string &CCode){
        while((CCode.length()!=8&&CCode.length()!=7)||!(isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3]))||!is_upper_or_number(CCode)){
            if(CCode.length()==8&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_upper_or_number(CCode.substr(4,4))){
                break;
            }
            if(CCode.length()==7&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_upper_or_number(CCode.substr(4,3))){
                break;
            }

            cout<<"Invalid input, re-enter again [course code]: ";
            getline(cin,CCode);
        }
        CourseCode=CCode;
        HashKey=CourseCode;
    }
    void Course::setCourseName(string &CName){
        while(CName.length()>50||CName.length()<1){
            cout<<"Invalid input, re-enter again [course name]: ";
            getline(cin,CName);
        }
        CourseName=CName;
    }
    void Course::setCredit(string &credit){
        while(credit!="0"&&credit!="1"&&credit!="2"&&credit!="3"&&credit!="4"&&credit!="5"){
            cout<<"Invalid input, re-enter again [course credit]: ";
            getline(cin,credit);
        }
        Credit=stoi(credit);
    }
    //overload operators
    bool Course::operator==(const Course& cour) const{//compare by CourseCode
        if(this->getCourseCode()==cour.getCourseCode()){
            return true;
        }
        else{
            return false;
        }
    }
    bool Course::operator<(const Course& cour) const{//compare by CourseCode
        for(int i=0;i<8;i++){
            if(this->getCourseCode()[i]<cour.getCourseCode()[i]){
                return true;
            }
            else if(this->getCourseCode()[i]>cour.getCourseCode()[i])
                return false;
        }
        return false;
    }
    
    //print functions
    void Course::print_not_exist(){
        cout<<"Course not exist"<<endl;
    }
    
    void Course::print_exist(){
        cout<<"Course already exist"<<endl;
    }
    
    void Course::print_insert_success(){
        cout<<"Creation of course record successful"<<endl;
    }
    
    void Course::print_delete_success(){
        cout<<"Deletion of course record successful"<<endl;
    }
    
    void Course::print_modify_success(){
        cout<<"Modification of course record successful"<<endl;
    }
    
    void Course::print_Query(){
        if(!canPrint||Credit==-1){return;}
        cout<<"Code:   "<<CourseCode<<endl;
        cout<<"Name:   "<<CourseName<<endl;
        cout<<"Credit: "<<Credit<<endl;
    }
