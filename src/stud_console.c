#include "stud_console.h"
#include "stud_utils.h"
#include <stdio.h>
#include <stdlib.h>

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
        printf("Name: %s, surname: %s, Age: %d, Day_joined: %d %d %d, Gender: %c\n",
                               students[index].name,
                               students[index].surname,
                               students[index].age,
                               students[index].date_joined.day,
                               students[index].date_joined.month,
                               students[index].date_joined.year,
                               students[index].gender);
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

Student* addNewStudent(Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    students = (Student*) realloc(students, sizeof(Student) * ++(*numOfStudents));
    Date birthDate;

    getOneValue("\nName: ", " %s", students[*numOfStudents-1].name);
    getOneValue("\nSurname: ", " %s", students[*numOfStudents-1].surname);
    getThreeValues("\nDate of birth: ", " %d %d %d", &birthDate.day,
                                                     &birthDate.month,
                                                     &birthDate.year);
    getThreeValues("\nDate joined: ", " %d %d %d", &students[*numOfStudents-1].date_joined.day,
                                                   &students[*numOfStudents-1].date_joined.month,
                                                   &students[*numOfStudents-1].date_joined.year);
    getOneValue("\nGender: ", " %c", &students[*numOfStudents-1].gender);

    students[*numOfStudents - 1].age = getAge(birthDate);
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
            copyStudents(&students[i], &students[i + 1]);
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
