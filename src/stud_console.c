#include "stud_console.h"
#include "stud_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stud_temp.h>

void printMenu()
{
    DEBUG("");
    printf("\nAvailable options:");
    printf("\n1. Print help");
    printf("\n2. Read students from file");
    printf("\n3. Write students to file");
    printf("\n4. Delete all students");
    printf("\n5. Print student by index");
    printf("\n6. Print all students");
    printf("\n7. Add student");
    printf("\n8. Delete one student");
    printf("\n9. Sort students");
    printf("\n10. Close program\n");
}

void printStudentByIndex(const Student* students, const int index)
{
    DEBUG("");
    students[index].print((void*)&students[index]);
}

void printAllStudents(const Student* students, const int numOfStudents)
{
    DEBUG("");
    printf("\nPrinting all students:\n");
    for (int index = 0; index < numOfStudents; ++index)
    {
        if (index < MAX_STUD)
            printStudentByIndex(students, index);
        else
        {
            printFromTemp();
            break;
        }
    }
}

void printOneStudent(const Student* students, const int numOfStudents)
{
    DEBUG("");
    int index = -1;
    getOneValue("\nPut student index to print: ", " %d", &index);
    printf("\n");
    if (index < numOfStudents && index > -1)
    {
        printStudentByIndex(students, index);
    }
    else
    {
        printf("Incorrect index! ");
        if (numOfStudents > 0)
            printf("There are %d students, min index is %d, max index: %d\n",
                    numOfStudents,
                    0,
                    numOfStudents - 1);
    }
}

Student getStudentFromConsole()
{
    DEBUG("");
    Student tempStudent;
    memset(&tempStudent, 0, sizeof(Student));

    getOneValue("\nName: ", " %s", tempStudent.name);
    getOneValue("\nSurname: ", " %s", tempStudent.surname);
    getThreeValues("\nDate of birth: ", " %d %d %d", &tempStudent.date_birth.day,
                   &tempStudent.date_birth.month,
                   &tempStudent.date_birth.year);
    getThreeValues("\nDate joined: ", " %d %d %d", &tempStudent.date_joined.day,
                   &tempStudent.date_joined.month,
                   &tempStudent.date_joined.year);
    getOneValue("\nGender: ", " %c", &tempStudent.gender);

    tempStudent.age = getAge(tempStudent.date_birth);

    if (tempStudent.gender == 'M')
    {
        tempStudent.print = printMan;
    }
    else
    {
        tempStudent.print = printWoman;
    }
    return tempStudent;
}

void addStudentFromConsole(Student *students, int *numOfStudents)
{
    DEBUG("");
    Student tempStudent = getStudentFromConsole();
    addNewStudent(students, numOfStudents, tempStudent);
}

void deleteStudent(Student* students, int* numOfStudents)
{
    DEBUG("");
    int index = -1;
    getOneValue("\nPut student index to delete: ", " %d", &index);
    printf("\n");
    if (index < *numOfStudents && index > -1)
    {
        for (int i = index; i < (*numOfStudents) -1; i++)
        {
            memcpy(&students[i], &students[i + 1], sizeof(Student));
        }
        memset(&students[*numOfStudents], 0, sizeof(Student));
        (*numOfStudents)--;
    }
    else
    {
        printf("Incorrect index\n");
    }
}

void killStudents(Student* students, int* numOfStudents)
{
    DEBUG("");
    memset(&students[*numOfStudents], 0, sizeof(Student) * (*numOfStudents));
    *numOfStudents = 0;
}