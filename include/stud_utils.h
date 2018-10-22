#ifndef __STUD_UTILS_H__
#define __STUD_UTILS_H__

#include "stud_types.h"

#include <stdbool.h>

void printWoman(Student*);
void printMan(Student*);

void getOneValue(char* textToPrint, char* format, void* arg);
void getThreeValues(char* textToPrint, char* format, void* arg,
                                                     void* mem2,
                                                     void* arg3);


void addNewStudent(Student *students, int *numOfStudents, Student tempStudent);
void copyStudents(Student* destination, Student* source);
unsigned getAge(Date birthDate);
bool isNewStudent(const Student *tempStudent, Student *students, int numOfStudents);

#endif
