#include "stud_utils.h"
#include <stdio.h>
#include <string.h>

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

bool checkIfStudentExist(const Student* tempStudent, Student* students, const int numOfStudents)
{
    for (int i = 0; i < numOfStudents; ++i)
    {
        if ( 0 == memcmp(tempStudent, &students[i], sizeof(Student)) )
            return true;
    }
    return false;
}