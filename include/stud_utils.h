#ifndef __STUD_UTILS_H__
#define __STUD_UTILS_H__

#include "stud_types.h"

void getOneValue(char* textToPrint, char* format, void* mem);
void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3);

void copyStudents(Student* destination, Student* source);
int getAge(Date* birthDate);

#endif
