#ifndef TYPES_HEADING//INCLUDE GUARDING ???
#define TYPES_HEADING

typedef struct
{
  int id;
  int sscYear;
  int hscYear;
  char firstName[60];
  char lastName[60];
  char schoolName[100];
  char bloodGroup[10];
  char mobileNumber[20];
  char email[100];
} DATA;

//ADD ENUM
typedef enum { F_NAME,L_NAME,S_NAME,B_GROUP,M_NUM,EMAIL } FIND;
//                0      1      2      3      4     5

#endif
