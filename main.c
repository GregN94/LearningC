#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <stud_temp.h>
#include "stud_sort.h"
#include "stud_utils.h"
#include "stud_types.h"
#include "stud_console.h"
#include "stud_file.h"

bool isRunning = true;

int main()
{

    Student students[MAX_STUD];
    memset(students, 0, sizeof(students));
    int numOfStudents = 0;
    char option[2] = "1";
    createNewTemp();

    printMenu();
    while (isRunning)
    {
        printf("\nFor help press 1");
        getOneValue("\nSelected option: ", " %s", &option);

        switch(atoi(option))
        {
            case PRINT_HELP             :   printMenu(); break;
            case READ_FROM_FILE         :   readStudentsFromFile(students, &numOfStudents); break;
            case WRITE_TO_FILE          :   writeStudentsToFile(students, numOfStudents); break;
            case DELETE_ALL_STUDENTS    :   killStudents(students, &numOfStudents); break;
            case PRINT_ONE_STUDENT      :   printOneStudent(students, numOfStudents); break;
            case PRINT_ALL_STUDENTS     :   printAllStudents(students, numOfStudents); break;
            case ADD_NEW_STUDENT        :   addStudentFromConsole(students, &numOfStudents); break;
            case DELETE_ONE_STUDENT     :   deleteStudent(students, &numOfStudents); break;
            case SORT_STUDENTS          :   sortStudents(students, numOfStudents); break;
            case CLOSE_PROGRAM          :   isRunning = false; break;
            default                     :   printf("\nSelected wrong option\n"); break;
        }
    }

    return 0;
}
