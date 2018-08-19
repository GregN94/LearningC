#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stud_sort.h"
#include "stud_utils.h"
#include "stud_types.h"
#include "stud_console.h"
#include "stud_file.h"

bool isRunning = true;

int main()
{
    Student* students = NULL;
    int numOfStudents = 0;
    char option[2] = "1";
    while (isRunning)
    {
        switch(atoi(option))
        {
            case PRINT_HELP             :   printMenu();break;
            case READ_FROM_FILE         :   students = readStudentsFromFile(students, &numOfStudents); break;
            case WRITE_TO_FILE          :   students = writeStudentsToFile(students, numOfStudents); break;
            case DELETE_ALL_STUDENTS    :   killStudents(students, &numOfStudents); break;
            case PRINT_ONE_STUDENT      :   printOneStudent(students, numOfStudents);break;
            case PRINT_ALL_STUDENTS     :   printAllStudents(students, numOfStudents);break;
            case ADD_NEW_STUDENT        :   students = addNewStudent(students, &numOfStudents);break;
            case DELETE_ONE_STUDENT     :   students = deleteStudent(students, &numOfStudents);break;
            case SORT_STUDENTS          :   sortStudents(students, numOfStudents);break;
            case CLOSE_PROGRAM          :   return 0;
            default                     :   printf("\nSelected wrong option\n");break;
        }
        printf("\nFor help press 1");
        getOneValue("\nSelected option: ", " %s", &option);
    }

    if (numOfStudents != 0)
        free(students);
    return 0;
}
