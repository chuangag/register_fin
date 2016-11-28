#ifndef _COURSERECORD_H
#define _COURSERECORD_H
#include "objects.h"
#include "hashTable.h"
class CourseRecord
{
public:
    static CourseRecord notPrint;
    CourseRecord(string StuID="",string CCode=""){
        StudentID=StuID;
        CourseCode=StuID;
        canPrint=true;
        ExamMark=-1;//N/A
        notPrint.setcanPrintToFalse();
    }
    ~CourseRecord(){}
    //get functions
    string getStudentID() const{return StudentID;}
    string getCourseCode() const{return CourseCode;}
    int getExamMark() const{return ExamMark;}
    bool getCanPrint(){return canPrint;}
    //set functions
    void setcanPrintToFalse(){canPrint=false;}
    
    //no checking exist in table version, only use when sure about no except(internal use)
    void setStudentID(string StuID);
    //check valid first and check if the student exist in the student table
    void setStudentID(string StuID, HashTable<Student> stuTable);
    
    //no checking exist in table version, only use when sure about no except(internal use)
    void setCourseCode(string CCode);
    //check valid first and check exist
    void setCourseCode(string CCode,HashTable<Course> courTable);

    void setExamMark(string mark);
    //set but don't print success or exist message(for database operation)
    void setExamMarkNotPrint(string mark);
    //check include course or student
    bool include(Student stu);
    bool include(Course cour);
    //print functions
    void print_exist();
    void print_insert_success();
    void print_delete_success();
    void print_not_exist();
    void print_modify_success();
    void print_Query();

    //overload operators
    /*primary sorting key: StudentID
     secondary sorting key: CourseCode
     */

    bool operator==(const CourseRecord& crec) const;
    bool operator<(const CourseRecord& crec) const;
    // overload = :equal this to a student or course by setting the coresponding key
    CourseRecord operator=(Student stu);
    CourseRecord operator=(Course cour);

private:
    string StudentID;//length=8
    string CourseCode;//len=7 or 8,first four are upper letters
    int ExamMark;//0<=mark<=100 or unassigned
    bool canPrint;
};

//implementation of class CourseRecord
CourseRecord CourseRecord::notPrint;
//no checking exist in table version, only use when sure about no except(internal use)
    void CourseRecord::setStudentID(string StuID){
        StudentID=StuID;
    }
    //check valid first and check if the student exist in the student table
    void CourseRecord::setStudentID(string StuID, HashTable<Student> stuTable){

        

        while(StuID.length()!=8||!is_number(StuID)){
            cout<<"Invalid input, re-enter again [student ID]: ";
            cin>>StuID;
        }

        Student virtualStuForChecking;
        virtualStuForChecking.setStudentID(StuID);
        if(stuTable.checkInTable(virtualStuForChecking)){
            StudentID=StuID;
        }
        else{
            virtualStuForChecking.print_not_exist();
            return;
        }
    }

    //no checking exist in table version, only use when sure about no except(internal use)
    void CourseRecord::setCourseCode(string CCode){
        CourseCode=CCode;
    }
    //check valid first and check exist
    void CourseRecord::setCourseCode(string CCode,HashTable<Course> courTable){
        
        while((CCode.length()!=8&&CCode.length()!=7)||(!isupper(CCode[0])||!isupper(CCode[1])||!isupper(CCode[2])||!isupper(CCode[3]))||is_upper_or_number(CCode.substr(4,4))){
            if(CCode.length()==8&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_upper_or_number(CCode.substr(4,4))){
                break;
            }
            if(CCode.length()==7&&isupper(CCode[0])&&isupper(CCode[1])&&isupper(CCode[2])&&isupper(CCode[3])&&is_upper_or_number(CCode.substr(4,4))){
                break;
            }

            cout<<"Invalid input, re-enter again [course code]: ";
            cin>>CCode;
        }

        Course virtualCourseForChecking;
        virtualCourseForChecking.setCourseCode(CCode);
        if(courTable.checkInTable(virtualCourseForChecking)){
            CourseCode=CCode;
        }
        else{
            virtualCourseForChecking.print_not_exist();
            return;
        }
    }

    void CourseRecord::setExamMark(string mark){
        while(!is_number(mark)||(stoi(mark)>100||stoi(mark)<0)){
            cout<<"Invalid input, re-enter again [exam mark]: ";
            cin>>mark;
        }
        print_modify_success();
        ExamMark=stoi(mark);
    }
    void CourseRecord::setExamMarkNotPrint(string mark){
        while(!is_number(mark)||(stoi(mark)>100||stoi(mark)<0)){
            cout<<"Invalid input, re-enter again [exam mark]: ";
            cin>>mark;
        }
       // print_modify_success();
        ExamMark=stoi(mark);
    }
    //check include course or student
    bool CourseRecord::include(Student stu){
        if(this->getStudentID()==stu.getStudentID()){
            return true;
        }
        else
            return false;
    }
    bool CourseRecord::include(Course cour){
        if(this->getCourseCode()==cour.getCourseCode()){
            return true;
        }
        else
            return false;
    }
    //print functions
    void CourseRecord::print_exist(){
        cout<<"The student already registered the course"<<endl;
    }
    void CourseRecord::print_insert_success(){
        cout<<"Add course successful"<<endl;
    }
    void CourseRecord::print_delete_success(){
        if(canPrint){
            cout<<"Drop course successful"<<endl;
        }
    }
    void CourseRecord::print_not_exist(){
        cout<<"The registration record not exist"<<endl;
    }
    void CourseRecord::print_modify_success(){
        cout<<"Modification of exam mark successful"<<endl;
    }
    void CourseRecord::print_Query(){
        if(!canPrint||StudentID==""){return;}
        cout<<"Student ID:  "<<StudentID<<endl;
        cout<<"Course Code: "<<CourseCode<<endl;

        if(ExamMark!=-1)
            cout<<"Exam Mark:   "<<ExamMark<<endl;
        else if(ExamMark==-1)
            cout<<"Exam Mark:   "<<"N/A"<<endl;
    }

    //overload operators
    /*primary sorting key: StudentID
     secondary sorting key: CourseCode
     */

    bool CourseRecord::operator==(const CourseRecord& crec) const{//compare by studentID
        if(this->getCourseCode()==crec.getCourseCode()&&this->getStudentID()==crec.getStudentID()){
            return true;
        }
        else{
            return false;
        }
    }
    bool CourseRecord::operator<(const CourseRecord& crec) const{//compare by studentID, if the same, compare by coursecode
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getStudentID()[i]<crec.getStudentID()[i]){
                return true;
            }
        }
        for(int i=0;i<LENOFSTUID;i++){
            if(this->getCourseCode()[i]<crec.getCourseCode()[i]){
                return true;
            }
        }

        return false;
    }
    // overload = :equal this to a student or course by setting the coresponding key
    CourseRecord CourseRecord::operator=(Student stu){
        setStudentID(stu.getStudentID());
        return *this;
    }
    CourseRecord CourseRecord::operator=(Course cour){
        setCourseCode(cour.getCourseCode());
        return *this;
    }
#endif
