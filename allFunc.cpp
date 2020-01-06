#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<iomanip>
using namespace std;

#include"types.h"
#include"headerFiles.h"


#define MAX_ENTRY 5

DATA info[MAX_ENTRY]; //array to hold all data

int studentNumber=0;//currentSize of info array

void readFile()
{
  int count_read=0;
  ifstream file("student_info.dat", ios::in | ios::binary);

  file.read((char *) &studentNumber,sizeof(studentNumber));
  file.read((char *) info,sizeof(info));
  //
  if(!file && count_read == 0)
  cout<<"*** NO DATA SAVED YET ***"<<endl;
  if(!file && count_read > 0)
  cout<<"!!! ERROR !!! Can't read data !!!"<<endl;
}

void saveFile()
{
  ofstream outfile("student_info.dat", ios::out | ios::binary);
  //
  if(!outfile)
  cout<<"can't open file"<<endl;
  //
  outfile.write((char *) &studentNumber,sizeof(studentNumber));

  outfile.write((char *) info,sizeof(info));

  puts("***Student Information Saved Successfully***");
}

void addEntry()
{
  if(studentNumber == MAX_ENTRY)
  {
    puts("!!!!!!!!!__ADDMISSION CLOSED__!!!!!!!!!");
    return;
  }

  DATA student;
  puts("Enter Your First Name:");
//  scanf("%s",student.firstName);
  fgets(student.firstName,60,stdin);
  name(student.firstName);

  puts("Enter Your Last Name:");
//  scanf("%s",student.lastName);
  fgets(student.lastName,60,stdin);
  name(student.lastName);


  puts("Enter Your School Name:");
//  scanf("%s",student.schoolName );
  fgets(student.schoolName,100,stdin);
  name(student.schoolName);

  puts("Enter Your Blood Group:");
//  scanf("%s",student.bloodGroup );
  fgets(student.bloodGroup,10,stdin);
  name(student.bloodGroup);

  puts("Enter Your Mobile Number:");
//  scanf("%s",student.mobileNumber);
  fgets(student.mobileNumber,20,stdin);
  name(student.mobileNumber);

  puts("Enter your Email Address:");
//  scanf("%s",student.email);
  fgets(student.email,100,stdin);
  name(student.email);


  info[studentNumber] = student;        //***important***
  ++studentNumber;

  puts("***Student Information Added Successfully***");
}

void displayAll()
{
  if(studentNumber==0)
  {
    puts("NO STUDENTS ADMITTED YET");
    return;
  }

  else
  {
    cout<<"Full Name:          School Name:        Blood Group:        Mobile Number:      Email:"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    for(int i=0 ; i<studentNumber ; ++i)
    {
      display(i);
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
  }
}

void display(int index)
{
  if(index<0 || index>=studentNumber)
  {
    puts("!!!_ERROR: INVALID INDEX_!!!");
    return;
  }

  DATA student = info[index];

  char addName[120];
  strcpy(addName,student.firstName);
  strcat(addName,student.lastName);

  cout.setf(ios::left);
  cout<<setw(20)<<addName<<setw(20)<<student.schoolName<<setw(20)<<student.bloodGroup<<setw(20)<<student.mobileNumber<<setw(20)<<student.email;
  cout<<endl;
}

void search(char *name,FIND type)
{
  //name = input
  strtolower(name);

  int found=0,i;
  char match[50];

  if(type == F_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].firstName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
      }
    }
  }

  else if(type == L_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].lastName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
      }
    }
  }

  else if(type == S_NAME)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].schoolName);
      strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
      }
    }
  }

  else if(type==B_GROUP)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].bloodGroup);
      //strtolower(match);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
      }
    }
  }

  else if(type==M_NUM)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].mobileNumber);

      if(strcmp(match,name) == 0)
      {
        display(i);
        found=1;
      }
    }
  }

  else if(type==EMAIL)
  {
    for(i=0;i<studentNumber;i++)
    {
      strcpy(match,info[i].email);

      if(strcmp(match,name)==0)
      {
        display(i);
        found=1;
      }
    }
  }

  else
  {
    puts("!!!_ERROR_!!!");
    puts("!!!_INVALID SEARCH TYPE");
    return;
  }

  if(!found)
  {
    puts("!!!_NOT ADMITTED_!!!");
  }

}

void strtolower(char *str)
{
  int len = strlen(str);
  for(int i=0;i<len;i++)
  str[i]=tolower(str[i]);
}

void name(char *str)
{
  while(*str != '\n')
  *str++;
  *str = '\0';
}

void deleteEntry(char *mobileNumber)
{
    if(studentNumber == 0) {
        puts("Database is empty! Nothing to delete!");
        return;
    }

    int i, j;
    int count = 0;
    for(i=0; i<studentNumber; i++) {
        if(strcmp(info[i].mobileNumber, mobileNumber) == 0)
        {
            for(j=i; j<studentNumber-1 ; j++)
            {
                info[j] = info[j+1];
            }

            strcpy(info[j].firstName, "");
            strcpy(info[j].lastName, "");
            strcpy(info[j].mobileNumber, "");

            studentNumber -= 1;
            ++count;
        }
    }

    if(count == 0) {
        puts("No entry deleted");
    }
    else {
        cout<<count<<" entry deleted"<<endl;
    }
}
