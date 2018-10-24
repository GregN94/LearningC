#ifndef __STUD_UTILS_H__
#define __STUD_UTILS_H__

#include "stud_types.h"
#include <stdbool.h>
#include <stdio.h>

#define DEBUG(TEXT)
#ifdef DEBUG_OPT
    #undef DEBUG(TEXT)
    #define DEBUG(TEXT) printf(TEXT, "\nDEBUG: at %s, line %d.", __FILE__, __LINE__)
#endif

#if OWN_MEM_FUNC
    #define memset(dest, ch, count) my_memset(dest, ch, count)
    #define memcmp(ptr1, ptr2, num) my_memcmp (ptr1, ptr2, num )
    #define memcpy(dest, src, count) my_memcpy(dest, src, count)
#endif

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
