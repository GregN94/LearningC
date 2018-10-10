#include "stud_console.h"
#include "stud_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu()
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
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
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    students[index].print((void*)&students[index]);
}

void printAllStudents(const Student* students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    printf("\nPrinting all students:\n");
    for (int index = 0; index < numOfStudents; ++index)
    {
        printStudentByIndex(students, index);
    }
}

void printOneStudent(const Student* students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
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
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
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

Student* addStudentFromConsole(Student *students, int *numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    Student tempStudent = getStudentFromConsole();
    students = addNewStudent(students, numOfStudents, tempStudent);
    return students;
}

Student* deleteStudent(Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    int index = -1;
    getOneValue("\nPut student index to delete: ", " %d", &index);
    printf("\n");
    if (index < *numOfStudents && index > -1)
    {
        for (int i = index; i < (*numOfStudents) -1; i++)
        {
            memcpy(&students[i], &students[i + 1], sizeof(Student));
        }
        students = (Student*) realloc(students, sizeof(Student) * --(*numOfStudents));
    }
    else
    {
        printf("Incorrect index\n");
    }
    return students;
}

Student* killStudents(Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    *numOfStudents = 0;
    return realloc(students, sizeof(Student) * (*numOfStudents));
}