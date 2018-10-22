#include "stud_utils.h"
#include "stud_file.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stud_temp.h>

#if OWN_MEM_FUNC
#define memcmp(ptr1, ptr2, num) my_memcmp (ptr1, ptr2, num )
#define memcpy(dest, src, count) my_memcpy(dest, src, count)
#endif

extern void* my_memcpy( void *dest, const void *src, size_t count );
extern void* my_memcmp ( const void * ptr1, const void * ptr2, size_t num );

const Date today = {6, 8, 2018};

void printWoman(Student* student)
{
    printf("Her name is %s, surname %s, she is %d years old, she joined on %d %d %d\n",
           student->name,
           student->surname,
           student->age,
           student->date_joined.day,
           student->date_joined.month,
           student->date_joined.year);
}

void printMan(Student* student)
{
    printf("His name is %s, surname %s, he is %d years old, hhe joined on %d %d %d\n",
           student->name,
           student->surname,
           student->age,
           student->date_joined.day,
           student->date_joined.month,
           student->date_joined.year);
}

void getThreeValues(char* textToPrint, char* format, void* arg,
                                                     void* arg2,
                                                     void* arg3)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    printf("%s", textToPrint);
    scanf(format, arg, arg2, arg3);
}

void getOneValue(char* textToPrint, char* format, void* arg)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    printf("%s", textToPrint);
    scanf(format, arg);
}

void addNewStudent(Student *students, int *numOfStudents, const Student tempStudent)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    if ( isNewStudent(&tempStudent, students, *numOfStudents) )
    {
        if (*numOfStudents < MAX_STUD)
        {
            memcpy(&students[*numOfStudents], &tempStudent, sizeof(Student));
        }
        else
        {
            appendToTemp(tempStudent);
        }
        (*numOfStudents)++;
    }
}

void copyStudents(Student* destination, Student* source)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    strcpy(destination->name, source->name);
    strcpy(destination->surname, source->surname);
    destination->age = source->age;
    destination->date_joined = source->date_joined;
    destination->gender = source->gender;
}

unsigned getAge(Date birthDate)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    if (birthDate.month < today.month)
        birthDate.year--;
    else if (birthDate.month == today.month)
    {
        if (birthDate.day <= today.day)
            birthDate.year--;
    }
    int age = today.year - birthDate.year -1;
    if (age < 0) age = 0;
    return (unsigned) age;
}

bool isNewStudent(const Student *tempStudent, Student *students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    for (int i = 0; i < numOfStudents; ++i)
    {
        if ( 0 == memcmp(tempStudent, &students[i], sizeof(Student)) )
            return false;
    }
    return isNewInTemp(tempStudent);
}