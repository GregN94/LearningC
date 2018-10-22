#ifndef __STUD_FILE_H__
#define __STUD_FILE_H__

#include "stud_types.h"
#include <stdio.h>

void readStudentsFromFile(Student* students, int* numOfStudents);
Student getStudentFromLine(const char* line);
void writeStudentsToFile(const Student* students, const int numOfStudents);
void writeStudentToFile(FILE* file, const Student* student);

#endif

