#include "stud_utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const Date today = {6, 8, 2018};

void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    printf("%s", textToPrint);
    scanf(format, mem, mem2, mem3);
}

void getOneValue(char* textToPrint, char* format, void* mem)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    printf("%s", textToPrint);
    scanf(format, mem);
}

Student* addNewStudent(Student *students, int *numOfStudents, const Student tempStudent)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    if ( isNewStudent(&tempStudent, students, *numOfStudents) )
    {
        (*numOfStudents)++;
        students = (Student*) realloc(students, sizeof(Student) * (*numOfStudents) );
        memcpy(&students[*numOfStudents - 1], &tempStudent, sizeof(Student));
    }
    return students;
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
    return true;
}