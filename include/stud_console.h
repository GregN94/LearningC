#ifndef __STUD_CONSOLE_H__
#define __STUD_CONSOLE_H__

#include "stud_types.h"

void printMenu();
void printAllStudents(const Student* students, int numOfStudents);
void printOneStudent(const Student* students, int numOfStudents);
void addStudentFromConsole(Student *students, int *numOfStudents);
void deleteStudent(Student* students, int* numOfStudents);
void killStudents(Student* students, int* numOfStudents);

#endif
