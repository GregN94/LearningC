#include "stud_sort.h"
#include "stud_utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool byName(Student left, Student right)
{
    return *left.name > *right.name;
}

bool bySurname(Student left, Student right)
{
    return *left.surname > *right.surname;
}

bool byAge(Student left, Student right)
{
    return left.age > right.age;
}

bool byJoinedDate(Student left, Student right)
{
    bool isBigger = false;
    if ( left.date_joined.year > right.date_joined.year)
    {
        isBigger = true;
    }
    else if ( left.date_joined.year == right.date_joined.year)
    {
        if ( left.date_joined.month > right.date_joined.month)
        {
            isBigger = true;
        }
        else if ( left.date_joined.month == right.date_joined.month)
        {
            if ( left.date_joined.day > right.date_joined.day)
            {
                isBigger = true;
            }
        }
    }
    return isBigger;
}

void swapStudents(Student* left, Student* right)
{
    Student tempStudent;
    copyStudents(&tempStudent, left);
    copyStudents(left, right);
    copyStudents(right, &tempStudent);
}

void sort(bool checkFunc(Student left, Student right), Student* students, int numOfStudents)
{
    for (int i = 1; i <= numOfStudents; ++i)
    {
        for (int j = 0; j < numOfStudents - i; ++j)
        {
            if (checkFunc(students[j], students[j + 1]))
                swapStudents(&students[j], &students[j + 1]);
        }
    }
}

void printSortingOptions()
{
    printf("\nAvaiable options:");
    printf("\n1. Name");
    printf("\n2. Surname");
    printf("\n3. Age");
    printf("\n4. Date joined");
}

void sortStudents(Student* students, int numOfStudents)
{
    char option = '6';
    printSortingOptions();
    getOneValue("\nSelected option: ", " %c", &option);

    switch(atoi(&option))
    {
        case NAME            :    sort(byName, students, numOfStudents);break;
        case SURNAME         :    sort(bySurname, students, numOfStudents);break;
        case AGE             :    sort(byAge, students, numOfStudents);break;
        case DATE_JOINED     :    sort(byJoinedDate, students, numOfStudents);break;
        default              :    printf("\nSelected wrong option!!\n");break;
    }
}

