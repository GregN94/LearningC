#ifndef __STUD_CONSOLE_H__
#define __STUD_CONSOLE_H__

#include "stud_types.h"

void printMenu();
void printAllStudents(Student* students, int numOfStudents);
void printOneStudent(Student* students, int numOfStudents);
Student* addNewStudent(Student* students, int* numOfStudents);
Student* deleteStudent(Student* students, int* numOfStudents);
Student* killStudents(Student* students, int* numOfStudents);

#endif
