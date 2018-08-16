#include "stud_utils.h"
#include <stdio.h>
#include <string.h>

Date today = {6, 8, 2018};

void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3)
{
    printf("%s", textToPrint);
    scanf(format, mem, mem2, mem3);
}

void getOneValue(char* textToPrint, char* format, void* mem)
{
    printf("%s", textToPrint);
    scanf(format, mem);
}

void copyStudents(Student* destination, Student* source)
{
    strcpy(destination->name, source->name);
    strcpy(destination->surname, source->surname);
    destination->age = source->age;
    destination->date_joined = source->date_joined;
    destination->gender = source->gender;
}

int getAge(Date* birthDate)
{
    if (birthDate->month < today.month)
        birthDate->year--;
    else if (birthDate->month == today.month)
    {
        if (birthDate->day <= today.day)
            birthDate->year--;
    }
    int age = today.year - birthDate->year -1;
    if (age < 0) age = 0;
    return age;
}


