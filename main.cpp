#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;
//_______________________including extra files
#include"types.h"
#include"headerFiles.h"
#include"allFunc.cpp"
//_______________________
void clear();
string thegetch();

int main()
{
//  readFile();
  char input[50];
  int choice;
  while(1)
 {
    clear();
    readFile();

    puts("|||||||||||||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||  STUDENT ADDMISSION INFORMATION   |||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 1.Insert new Entry ~~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 2.Display All Entry ~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 3.Search by First Name ~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 4.Search by Last Name ~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 5.Search by School Name ~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 6.Search by Blood Group ~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 7.Search by Mobile Number~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 8.Search by Email ~~~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 9.Delete Information ~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 10.Save to Database ~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~ 11.Exit ~~~~~~~~~~~~~~~~~~|||||||||||||||||");
    puts("|||||||||||||||||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|||||||||||||||||");

    do{
      puts("enter your choise:");
      fgets(input,50,stdin);
      choice=atoi(input);
    }while(choice<1||choice>11);

    switch(choice)
    {
      case 1:
             addEntry();
             break;
      case 2:
             displayAll();
             break;
      case 3:
             puts("Enter the First Name:");
             fgets(input,50,stdin);
             name(input);
             search(input,F_NAME);
             break;
      case 4:
             puts("Enter the Last Name:");
             fgets(input,50,stdin);
             name(input);
             search(input,L_NAME);
             break;
      case 5:
             puts("Enter the School Name:");
             fgets(input,50,stdin);
             name(input);
             search(input,S_NAME);
             break;
      case 6:
             puts("Enter the Blood Group:");
             fgets(input,50,stdin);
             name(input);
             search(input,B_GROUP);
             break;
      case 7:
             puts("Enter the Mobile Number:");
             fgets(input,50,stdin);
             name(input);
             search(input,M_NUM);
             break;
      case 8:
             puts("Enter the Email:");
             fgets(input,50,stdin);
             name(input);
             search(input,EMAIL);
             break;
      case 9:
             cout<<"Enter mobile number to delete: ";
             fgets(input,50,stdin);
             name(input);
             deleteEntry(input);
             saveFile();
             break;
      case 10:
             saveFile();
             break;
      case 11:
             exit(0);
    }
    thegetch();
 }
 return 0;
}

string thegetch()
{
  string val;
  string ral;

  getline(cin,val);
//  getline(cin,ral);

  return val;
}

void clear()
{
  system("clear");
}
