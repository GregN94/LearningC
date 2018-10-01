#ifndef __STUD_FILE_H__
#define __STUD_FILE_H__

#include "stud_types.h"

Student* readStudentsFromFile(Student* students, int* numOfStudents);
void writeStudentsToFile(const Student* students, const int numOfStudents);

#endif
