#ifndef __STUD_UTILS_H__
#define __STUD_UTILS_H__

#include "stud_types.h"

#include <stdbool.h>

void printWoman(Student*);
void printMan(Student*);

void getOneValue(char* textToPrint, char* format, void* mem);
void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3);

void copyStudents(Student* destination, Student* source);
unsigned getAge(Date birthDate);
bool checkIfStudentExist(const Student* tempStudent, Student* students, const int numOfStudents);

#endif
