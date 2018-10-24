#include "stud_utils.h"
#include "stud_file.h"
#include <string.h>
#include <stdlib.h>
#include <stud_temp.h>

const Date today = {6, 8, 2018};

void printWoman(Student* student)
{
    DEBUG("");
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
    DEBUG("");
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
    DEBUG("");
    printf("%s", textToPrint);
    scanf(format, arg, arg2, arg3);
}

void getOneValue(char* textToPrint, char* format, void* arg)
{
    DEBUG("");
    printf("%s", textToPrint);
    scanf(format, arg);
}

void addNewStudent(Student *students, int *numOfStudents, const Student tempStudent)
{
    DEBUG("");
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
    DEBUG("");
    strcpy(destination->name, source->name);
    strcpy(destination->surname, source->surname);
    destination->age = source->age;
    destination->date_joined = source->date_joined;
    destination->gender = source->gender;
}

unsigned getAge(Date birthDate)
{
    DEBUG("");
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
    DEBUG("");
    for (int i = 0; i < numOfStudents; ++i)
    {
        if ( 0 == memcmp(tempStudent, &students[i], sizeof(Student)) )
            return false;
    }
    return isNewInTemp(tempStudent);
}