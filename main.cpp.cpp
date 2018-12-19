#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>


using namespace std;

//FOR STUDENT.
 struct student
{
    //student info.
 string id, firstname, lastname, sex, age, clas;

};

void addstudent() //get student data.
{
    char inchoice;
    int i;
    student stu;
    ofstream outputfile;
    cout<< "\npress 1 again to confirm add student: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tADD STUDENT"<<endl;
    cout<<"\tId number: "; cin>>stu.id;
    cout<<"\tFirst Name: "; cin>>stu.firstname;
    cout<<"\tLast Name: "; cin>>stu.lastname;
    cout<<"\tClass: "; cin>>stu.clas;
    cout<<"\tSex: "; cin>>stu.sex;
    cout<<"\tAge: "; cin>>stu.age;

    //output to student file.
    outputfile.open("student.txt",ios::app);
    outputfile<<stu.id<<" "<<stu.firstname<<" "<<stu.lastname<<" "<<stu.clas<<" "<<stu.sex<<" "<<stu.age<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tStudent has been Added!!!.\n";
    cout<<"\n\n\n\npress 'Y' to add another student or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}


void editstudent()
{
    char inchoice;
    int i;

    cout<< "\npress 2 again to confirm edit student: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STUDENT"<<endl;
    string id;
    cout<<"\n Enter the student's ID number: ";
    cin>>id;

    student stu;
    fstream intofile ("student.txt");
    fstream temporalfile ("temp.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName:"; cin>>stu.firstname;
            cout<<"LastName:"; cin>>stu.lastname;
            cout<<"Class:"; cin>>stu.clas;
            cout<<"Sex: "; cin>>stu.sex;
            cout<<"Age: "; cin>>stu.age;

            temporalfile<<id<<" "<<stu.firstname<<" "<<stu.lastname<<" "<<stu.clas<<" "<<stu.sex<<" "<<stu.age<<endl;
            cout<<"\nstudent information has been successfully edited.endl;
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
cout<<"\n\n\n\npress 'Y' to edit another student or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestudent()
{
    char inchoice;
    int i;

    cout<< "\npress 3 again to confirm delete student: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STUDENT"<<endl;
    string id;
    cout<<"Enter Id number: ";
    cin>>id;

    student stu;
    fstream intofile ("student.txt");
    fstream temporalfile ("temp.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Student has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
cout<<"\n\n\n\npress 'Y' to delete another student or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}


void studentslist()
{
    ifstream outputfile("student.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t  ALL STUDENTS \t\t\n\n\n";
    cout << setw(15) <<"ID NUMBER" << setw(15) << "FIRST_NAME" << setw(15) << "LAST_NAME" <<setw(15) << "CLASS"<<setw(15)<<"SEX"<<setw(15)<<"AGE"<< endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, endl);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << '\n';

    }

cout<< "\n\n\n\nenter any key to continue to main menu: "; cin>>i;
system("cls");
}




//FOR STAFF
 struct staff
{
 string id, firstname, lastname,sex, age, teachcourse;
};
void addstaff() //get staff data.
{
     char inchoice;
    int i;
    staff sta;
    ofstream outputfile;
    cout<< "\npress 1 again to confirm add staff: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){


    cout<< "\n\n\t\t\tADD STAFF"<<endl;
    cout<<"\tId number: "; cin>>sta.id;
    cout<<"\tFirst Name: "; cin>>sta.firstname;
    cout<<"\tLast Name: "; cin>>sta.lastname;
    cout<<"\tteachcourse: "; cin>>sta.teachcourse;
    cout<<"\tSex: "; cin>>sta.sex;
    cout<<"\tAge: "; cin>>sta.age;

    //output to student file.
    outputfile.open("staff.txt",ios::app);
    outputfile<<sta.id<<" "<<sta.firstname<<" "<<sta.lastname<<" "<<sta.teachcourse<<" "<<sta.sex<<" "<<sta.age<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tStaff has been Added!!!.\n";
    cout<<"\n\n\n\npress 'Y' to add another staff or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editstaff()
{
    char inchoice;
    int i;

    cout<< "\npress 2 again to confirm edit staff: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STAFF"<<endl;
    string id;
    cout<<"\n Enter the staff's ID number: ";
    cin>>id;

    staff sta;
    fstream intofile ("staff.txt");
    fstream temporalfile ("temp1.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"FirstName:"; cin>>sta.firstname;
            cout<<"LastName:"; cin>>sta.lastname;
            cout<<"Class:"; cin>>sta.teachcourse;
            cout<<"Sex: "; cin>>sta.sex;
            cout<<"Age: "; cin>>sta.age;

            temporalfile<<id<<" "<<sta.firstname<<" "<<sta.lastname<<" "<<sta.teachcourse<<" "<<sta.sex<<" "<<sta.age<<endl;
            cout<<"\nstaff has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("staff.txt");
    rename("temp1.txt","staff.txt");
cout<<"\n\n\n\npress 'Y' to edit another staff or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestaff()
{
    char inchoice;
    int i;

    cout<< "\npress 3 again to confirm delete student: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STAFF"<<endl;
    string id;
    cout<<"Enter Id number: ";
    cin>>id;

    staff sta;
    fstream intofile ("staff.txt");
    fstream temporalfile ("temp1.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Staff has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("staff.txt");
    rename("temp1.txt","staff.txt");

cout<<"\n\n\n\npress 'Y' to delete another student or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}


void staffslist()
{
    string i;
    ifstream outputfile("staff.txt");
    string content;
    cout<<endl<<"\t\t\t\t  ALL STAFF \t\t\n\n\n";
    cout << setw(15) <<"ID NUMBER" << setw(15) << "FIRST_NAME" << setw(15) << "LAST_NAME" <<setw(15) << "SUBJECT_TAKEN"<<setw(15)<<"SEX"<<setw(15)<<"AGE"<< endl<<endl;

    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << endl

    }

cout<< "\n\n\n\nenter any key to continue: "; cin>>i;
system("cls");
}



//FOR COURSES
struct course
{
    string code, title, credithrs, tutor;
};
void addcourse() //get course data.
{
    char inchoice;
    int i;
    course cou[1000];
    ofstream outputfile;
    cout<< "\npress 1 again to confirm add course: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tADD COURSE"<<endl;
    cout<<"\tcourse code: "; cin>>cou[i].code;
    cout<<"\tcourse title: "; cin>>cou[i].title;
    cout<<"\tcredit hours: "; cin>>cou[i].credithrs;
    cout<<"\tcourse tutor: "; cin>>cou[i].tutor;

    //output to student file.
    outputfile.open("course.txt",ios::app);
    outputfile<<cou[i].code<<" "<<cou[i].title<<" "<<cou[i].credithrs<<" "<<cou[i].tutor<<" "<<endl;
    outputfile.close();
    cout<<"\n\n\t\t\tCourse has been Added!!!.\n";
    cout<<"\n\n\n\npress 'Y' to add another course or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editcourse()
{
    char inchoice;
    int i;

    cout<< "\npress 2 again to confirm edit course: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT COURSE"<<endl;
    string code;
    cout<<"\n Enter the course code: ";
    cin>>code;

    course cou;
    fstream intofile ("course.txt");
    fstream temporalfile ("temp2.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && code==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
            cout<<"Course title:"; cin>>cou.title;
            cout<<"Credit hours:"; cin>>cou.credithrs;
            cout<<"Tutor:"; cin>>cou.tutor;

            temporalfile<<code<<" "<<cou.title<<" "<<cou.credithrs<<" "<<cou.tutor<<endl;
            cout<<"\nCourse information has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("course.txt");
    rename("temp.txt","course.txt");
cout<<"\n\n\n\npress 'Y' to edit another course or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletecourse()
{
    char inchoice;
    int i;

    cout<< "\npress 3 again to confirm delete course: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE COURSE"<<endl;
    string code;
    cout<<"Enter Course Code: ";
    cin>>code;

    course cou;
    fstream intofile ("course.txt");
    fstream temporalfile ("temp2.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && code==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Course has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("course.txt");
    rename("temp2.txt","course.txt");
cout<<"\n\n\n\npress 'Y' to delete another course or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}


void courselist()
{
    ifstream outputfile("course.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t  ALL COURSES \t\t\n\n\n";
    cout << setw(15) <<"COURSE_CODE" << setw(15) << "COURSE_TITLE" << setw(15) << "CREDIT_HOURS" <<setw(15) << "COURSE_TUTOR"<< endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << endl;

    }

cout<< "\n\n\n\nenter any key to continue to main menu: "; cin>>i;
system("cls");
}



struct studentrecord
{
    string id, firstname, lastname;
    float acawrt, maths, prog, stat, culture;
    char acagrd, mathgrd, progrd, statgrd, culgrd;
    string acarem, mathrem, progrem, statrem, culrem;
};
void addstudentrecord() //get student data.
{
    char inchoice;
    int i;
    studentrecord g;
    ofstream outputfile;
    ofstream outputfile2;
    cout<< "\npress 1 again to confirm add student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='1')){

    cout<< "\n\n\t\t\tRECORD STUDENT GRADE"<<endl;
    cout<<"Student ID: ";cin>>g.id;
    cout<<"First name: ";cin>>g.firstname;
    cout<<"Last name: ";cin>>g.lastname;
    cout<<"\n\n\n\t\t\tenter marks for "<<g.firstname<<" "<<g.lastname<<" ("<<g.id<<")"<<endl;

    cout<<"\n\n\tenter Academic Writing mark: ";cin>>g.acawrt;
    if (g.acawrt >= 80) g.acagrd='A'; else if (g.acawrt>= 70) g.acagrd='B'; else if (g.acawrt>= 60) g.acagrd='C'; else if (g.acawrt>= 50) g.acagrd='D'; else if (g.acawrt>= 40) g.acagrd='E'; else g.acagrd='F';
    if (g.acawrt >= 80) g.acarem="EXCELLENT"; else if (g.acawrt>= 70) g.acarem="V.GOOD"; else if (g.acawrt>= 60) g.acarem="GOOD"; else if (g.acawrt>= 50) g.acarem="CREDIT"; else if (g.acawrt>= 40) g.acarem="PASS"; else g.acarem="FAIL";

    cout<<"\tenter Math mark: ";cin>>g.maths;
    if (g.maths >= 80) g.mathgrd='A'; else if (g.maths>= 70) g.mathgrd='B'; else if (g.maths>= 60) g.mathgrd='C'; else if (g.maths>= 50) g.mathgrd='D'; else if (g.maths>= 40) g.mathgrd='E'; else g.mathgrd='F';
    if (g.maths >= 80) g.mathrem="EXCELLENT"; else if (g.maths>= 70) g.mathrem="V.GOOD"; else if (g.maths>= 60) g.mathrem="GOOD"; else if (g.maths>= 50) g.mathrem="CREDIT"; else if (g.maths>= 40) g.mathrem="PASS"; else g.mathrem="FAIL";

    cout<<"\tenter Programming1 mark for: ";cin>>g.prog;
    if (g.prog >= 80) g.progrd='A'; else if (g.prog>= 70) g.progrd='B'; else if (g.prog>= 60) g.progrd='C'; else if (g.prog>= 50) g.progrd='D'; else if (g.prog>= 40) g.progrd='E'; else g.progrd='F';
    if (g.prog >= 80) g.progrem="EXCELLENT"; else if (g.prog>= 70) g.progrem="V.GOOD"; else if (g.prog>= 60) g.progrem="GOOD"; else if (g.prog>= 50) g.progrem="CREDIT"; else if (g.prog>= 40) g.progrem="PASS"; else g.progrem="FAIL";

    cout<<"\tStatistics mark: "; cin>>g.stat;
    if (g.stat >= 80) g.statgrd='A'; else if (g.stat>= 70) g.statgrd='B'; else if (g.stat>= 60) g.statgrd='C'; else if (g.stat>= 50) g.statgrd='D'; else if (g.stat>= 40) g.statgrd='E'; else g.statgrd='F';
    if (g.stat >= 80) g.statrem="EXCELLENT"; else if (g.stat>= 70) g.statrem="V.GOOD"; else if (g.stat>= 60) g.statrem="GOOD"; else if (g.stat>= 50) g.statrem="CREDIT"; else if (g.stat>= 40) g.statrem="PASS"; else g.statrem="FAIL";

    cout<<"\tCulture mark: "; cin>>g.culture;
    if (g.culture >= 80) g.culgrd='A'; else if (g.culture>= 70) g.culgrd='B'; else if (g.culture>= 60) g.culgrd='C'; else if (g.culture>= 50) g.culgrd='D'; else if (g.culture>= 40) g.culgrd='E'; else g.culgrd='F';
    if (g.culture >= 80) g.culrem="EXCELLENT"; else if (g.culture>= 70) g.culrem="V.GOOD"; else if (g.culture>= 60) g.culrem="GOOD"; else if (g.culture>= 50) g.culrem="CREDIT"; else if (g.culture>= 40) g.culrem="PASS"; else g.culrem="FAIL";

    //output to student record file.
    outputfile.open("record.txt",ios::app);
    outputfile<<g.id<<" "<<g.firstname<<" "<<g.lastname<<" "<<g.acagrd<<" "<<g.mathgrd<<" "<<g.progrd<<" "<<g.statgrd<<" "<<g.culgrd<<endl<<endl;
    outputfile2.open("record2.txt",ios::app);
    outputfile2<<g.id<<endl<<g.firstname<<endl<<g.lastname<<endl<<setw(10)<<g.acawrt<<" "<<setw(10)<<g.acagrd<<" "<<setw(15)<<g.acarem<<endl<<setw(10)<<g.maths<<" "<<setw(10)<<g.mathgrd<<" "<<setw(15)<<g.mathrem<<endl<<setw(10)<<g.prog<<" "<<setw(10)<<g.progrd<<" "<<setw(15)<<g.progrem<<endl<<setw(10)<<g.stat<<" "<<setw(10)<<g.statgrd<<" "<<setw(15)<<g.statrem<<endl<<setw(10)<<g.culture<<" "<<setw(10)<<g.culgrd<<" "<<setw(15)<<g.culrem<<endl<<endl;
    outputfile.close();
    outputfile2.close();
    cout<<"\n\n\t\t\tStudent grade has been Added!!!.\n";
    cout<<"\n\n\n\npress 'Y' to add another student or 'N' to finish: "; cin>>inchoice;

            }
    }
system("cls");
    return;
}

void editstudentrecord()
{
    char inchoice;
    int i;

    cout<< "\npress 2 again to confirm edit student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='2')){
    cout<< "\n\n\t\t\tEDIT STUDENT"<<endl;
    string id;
    cout<<"\n Enter the student's ID number: ";
    cin>>id;

    studentrecord g;
    fstream intofile ("record.txt");
    fstream temporalfile ("temp8.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {
    cout<<"First name: ";cin>>g.firstname;
    cout<<"Last name: ";cin>>g.lastname;
    cout<<"\n\n\n\t\t\tenter marks for "<<g.firstname<<" "<<g.lastname<<" ("<<id<<")"<<endl;

    cout<<"\n\n\tenter Academic Writing mark: ";cin>>g.acawrt;
    if (g.acawrt >= 80) g.acagrd='A'; else if (g.acawrt>= 70) g.acagrd='B'; else if (g.acawrt>= 60) g.acagrd='C'; else if (g.acawrt>= 50) g.acagrd='D'; else if (g.acawrt>= 40) g.acagrd='E'; else g.acagrd='F';
    if (g.acawrt >= 80) g.acarem="EXCELLENT"; else if (g.acawrt>= 70) g.acarem="V.GOOD"; else if (g.acawrt>= 60) g.acarem="GOOD"; else if (g.acawrt>= 50) g.acarem="CREDIT"; else if (g.acawrt>= 40) g.acarem="PASS"; else g.acarem="FAIL";

    cout<<"\tenter Math mark: ";cin>>g.maths;
    if (g.maths >= 80) g.mathgrd='A'; else if (g.maths>= 70) g.mathgrd='B'; else if (g.maths>= 60) g.mathgrd='C'; else if (g.maths>= 50) g.mathgrd='D'; else if (g.maths>= 40) g.mathgrd='E'; else g.mathgrd='F';
    if (g.maths >= 80) g.mathrem="EXCELLENT"; else if (g.maths>= 70) g.mathrem="V.GOOD"; else if (g.maths>= 60) g.mathrem="GOOD"; else if (g.maths>= 50) g.mathrem="CREDIT"; else if (g.maths>= 40) g.mathrem="PASS"; else g.mathrem="FAIL";

    cout<<"\tenter Programming1 mark for: ";cin>>g.prog;
    if (g.prog >= 80) g.progrd='A'; else if (g.prog>= 70) g.progrd='B'; else if (g.prog>= 60) g.progrd='C'; else if (g.prog>= 50) g.progrd='D'; else if (g.prog>= 40) g.progrd='E'; else g.progrd='F';
    if (g.prog >= 80) g.progrem="EXCELLENT"; else if (g.prog>= 70) g.progrem="V.GOOD"; else if (g.prog>= 60) g.progrem="GOOD"; else if (g.prog>= 50) g.progrem="CREDIT"; else if (g.prog>= 40) g.progrem="PASS"; else g.progrem="FAIL";

    cout<<"\tStatistics mark: "; cin>>g.stat;
    if (g.stat >= 80) g.statgrd='A'; else if (g.stat>= 70) g.statgrd='B'; else if (g.stat>= 60) g.statgrd='C'; else if (g.stat>= 50) g.statgrd='D'; else if (g.stat>= 40) g.statgrd='E'; else g.statgrd='F';
    if (g.stat >= 80) g.statrem="EXCELLENT"; else if (g.stat>= 70) g.statrem="V.GOOD"; else if (g.stat>= 60) g.statrem="GOOD"; else if (g.stat>= 50) g.statrem="CREDIT"; else if (g.stat>= 40) g.statrem="PASS"; else g.statrem="FAIL";

    cout<<"\tCulture mark: "; cin>>g.culture;
    if (g.culture >= 80) g.culgrd='A'; else if (g.culture>= 70) g.culgrd='B'; else if (g.culture>= 60) g.culgrd='C'; else if (g.culture>= 50) g.culgrd='D'; else if (g.culture>= 40) g.culgrd='E'; else g.culgrd='F';
    if (g.culture >= 80) g.culrem="EXCELLENT"; else if (g.culture>= 70) g.culrem="V.GOOD"; else if (g.culture>= 60) g.culrem="GOOD"; else if (g.culture>= 50) g.culrem="CREDIT"; else if (g.culture>= 40) g.culrem="PASS"; else g.culrem="FAIL";


    temporalfile<<id<<" "<<g.firstname<<" "<<g.lastname<<" "<<g.acagrd<<" "<<g.mathgrd<<" "<<g.progrd<<" "<<g.statgrd<<" "<<g.culgrd<<endl;

            cout<<"\nstudent record has been successfully edited.\n";
        }
        else
        {
            temporalfile<<line<<endl;
        }


    }
    intofile.close();
    temporalfile.close();
    remove("record.txt");
    rename("temp8.txt","record.txt");
cout<<"\n\n\n\npress 'Y' to edit another student record or 'N' to finish: "; cin>>inchoice;
            }
    }
system("cls");
}

void deletestudentrecord()
{
    char inchoice;
    int i;

    cout<< "\npress 3 again to confirm delete student record: ";cin>>inchoice;
    for (i=0; inchoice!='n'&&inchoice!='N'; i++){
            if((inchoice=='y')||(inchoice=='Y')||(inchoice=='3')){
    cout<< "\n\n\t\t\tDELETE STUDENT"<<endl;
    string id;
    cout<<"Enter Id number: ";
    cin>>id;

    student stu;
    fstream intofile ("record.txt");
    fstream temporalfile ("temp9.txt",ios::app);
    string line;

    while(std::getline(intofile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && id==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temporalfile<<line<<endl;
        }
        else
        {
            cout<<"\n Student record has been successfully deleted \n";
        }


    }
    intofile.close();
    temporalfile.close();
    remove("record.txt");
    rename("temp9.txt","record.txt");
cout<<"\n\n\n\npress 'Y' to delete another student record or 'N' to finish: "; cin>>inchoice;
            }
    }

system("cls");
}

void studentsrecordlist()
{
    ifstream outputfile("record.txt");
    string content,i;
    cout<<endl<<"\t\t\t\t\t\t\tALL STUDENT RECORDS \t\t\n\n\n";
    cout <<setw(15) <<"ID"<<setw(15)<<"FIRST_NAME"<<setw(15)<<"LAST_NAME"<<setw(20)<<"ACADEMIC_WRITING"<<setw(15)<<"MATHEMATICS"<<setw(15)<<"PROGRAMMING"<<setw(15)<<"STATISTICS"<<setw(15)<<"CULTURE"<<endl<<endl;
    string line;
    while(std::getline(outputfile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), endl;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << endl;

    }

cout<< "\n\n\n\nenter any key to continue to main menu: "; cin>>i;
system("cls");
}

void display()
{
int notfound=0,y=1,q,i;
string find, id,firstname,lastname,acawriting,maths,prog,stats,culture;
ifstream f2("record2.txt");
cout<<"Enter ID of student whose record you want to display: ";cin>>find;
cout<<endl;

for(q=0; (q<y)||(!f2.eof()); q++)
{
getline(f2,id);
if (id==find)
{
notfound=1;
cout<<setw(12)<<"ID: "<<id<<endl;
getline(f2,firstname);
cout<<setw(12)<<"First name: "<<firstname<<endl;
getline(f2,lastname);
cout<<setw(12)<<"Last name: "<<lastname<<endl<<endl;
cout<<"\t\t\t\tCOURSES\n\n";
cout<<setw(20)<<"COURSE "<<setw(12)<<"MARK "<<setw(12)<<"GRADE "<<setw(17)<<"REMARK "<<endl<<endl;
getline(f2,acawriting);
cout<<setw(20)<<"Academic Writing: "<<acawriting<<endl;
getline(f2,maths);
cout<<setw(20)<<"Mathematics: "<<maths<<endl;
getline(f2,prog);
cout<<setw(20)<<"Programming1: "<<prog<<endl;
getline(f2,stats);
cout<<setw(20)<<"Statistics: "<<stats<<endl;
getline(f2,culture);
cout<<setw(20)<<"Culture: "<<culture<<endl;
}
}
if(notfound==0){cout<<"No Record Found"<<endl;}
f2.close();
cout<< "\n\n\n\nenter any key to continue to main menu: "; cin>>i;

}

int main()
{
    int select;
    string find;
    while(1)
    {

            cout <<endl<<endl;
            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM\n\t\t\t\t(by: Doh Derrick - 10663901)"<< endl;
            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
            cout << "\t\t\t\t\t MAIN MENU"<< endl<<endl<<endl;
            cout <<"\tPlease select: "<<endl;
            cout << "\t\t\t1. STUDENT (ADD/EDIT/DELETE/SHOW ALL STUDENTS)"<< endl;
            cout << "\t\t\t2. STAFF (ADD/EDIT/DELETE)"<< endl;
            cout << "\t\t\t3. COURSES (ADD/EDIT/DELETE)"<< endl;
            cout << "\t\t\t4. STUDENT RECORD "<< endl;
            cout << "\t\t\t5. EXIT"<< endl<<endl;
            cout << "what is your choice?: ";


            cin>>select;
            system("cls");
            switch(select)
            {
                case 1:
                            int stuselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tSTUDENT "<< endl<<endl;
                            cout << "\t\t\t1. ADD STUDENT"<< endl;
                            cout << "\t\t\t2. EDIT STUDENT"<< endl;
                            cout << "\t\t\t3. DELETE STUDENT"<< endl;
                            cout << "\t\t\t4. SHOW ALL STUDENTS"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "what is your choice?: ";
                            cin>>stuselect;
                            switch(stuselect)
                            {
                                case 1:
                                    addstudent();
                                    break;
                                case 2:
                                    editstudent();
                                    break;
                                case 3:
                                    deletestudent();
                                    break;
                                case 4:
                                    studentslist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"!!!wrong entry. Enter between 1-5!!!";
                            }

            break;


                case 2:
                            int staffselect;



                             cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tSTAFF "<< endl<<endl;
                            cout << "\t\t\t1. ADD STAFF"<< endl;
                            cout << "\t\t\t2. EDIT STAFF"<< endl;
                            cout << "\t\t\t3. DELETE STAFF"<< endl;
                            cout << "\t\t\t4. SHOW ALL STAFF"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "what is your choice?: ";
                            cin>>staffselect;
                            switch(staffselect)
                            {
                                case 1:
                                    addstaff();
                                    break;
                                case 2:
                                    editstaff();
                                    break;
                                case 3:
                                    deletestaff();
                                    break;
                                case 4:
                                    staffslist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"!!!wrong entry! \npress any key to continue: ";
                            }

                            break;


                     case 3:
                            int couselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tCOURSES "<< endl<<endl;
                            cout << "\t\t\t1. ADD COURSE"<< endl;
                            cout << "\t\t\t2. EDIT COURSE"<< endl;
                            cout << "\t\t\t3. DELETE COURSE"<< endl;
                            cout << "\t\t\t4. SHOW ALL COURSES"<< endl;
                            cout << "\t\t\t5. EXIT"<< endl<<endl;
                            cout << "what is your choice?: ";
                            cin>>couselect;
                            switch(couselect)
                            {
                                case 1:
                                    addcourse();
                                    break;
                                case 2:
                                    editcourse();
                                    break;
                                case 3:
                                    deletecourse();
                                    break;
                                case 4:
                                    courselist();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"!!!wrong entry. Enter between 1-5!!!";
                            }

                       break;

                         case 4:
                            int recordselect;
                            cout <<endl<<endl;
                            cout << "\t\t\t\t SCHOOL MANAGEMENT SYSTEM"<< endl;
                            cout << "\t\t\t\t__________________________"<<endl<<endl<<endl<<endl;
                            cout << "\t\t\t\t\tSTUDENT RECORDS "<< endl<<endl;
                            cout << "\t\t\t1. ADD STUDENT RECORD"<< endl;
                            cout << "\t\t\t2. EDIT STUDENT RECORD"<< endl;
                            cout << "\t\t\t3. DELETE STUDENT RECORD"<< endl;
                            cout << "\t\t\t4. SHOW ALL STUDENTS RECORDS"<< endl;
                            cout << "\t\t\t5. FIND AND DISPLAY DETAILED STUDENT RECORD"<< endl;
                            cout << "\t\t\t6. EXIT"<< endl<<endl;
                            cout << "what is your choice?: ";
                            cin>>recordselect;
                            switch(recordselect)
                            {
                                case 1:
                                    addstudentrecord();
                                    break;
                                case 2:
                                    editstudentrecord();
                                    break;
                                case 3:
                                    deletestudentrecord();
                                    break;
                                case 4:
                                    studentsrecordlist();
                                    break;
                                case 5:
                                    display();
                                    break;
                                case 6:exit(0);
                                break;
                                default:
                                        cout<<"!!!wrong entry. Enter between 1-5!!!";
                            }

                       break;
                       case 5:exit(0);
                        break;
                default:cout<<"wrong entry, please re-try";
            }
            system("cls");
    }

    return 0;
}

