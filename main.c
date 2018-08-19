#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stud_sort.h"
#include "stud_utils.h"
#include "stud_types.h"
#include "stud_console.h"

bool isRunning = true;
Student* students = NULL;
int numOfStudents = 0;

void readStudentsFromFile();
void writeStudentsToFile();
void printSizeOfFile(char* fileName);
int getNumOfLines(char* fileName);
void txtWrite(char* fileName);
void binWrite(char* fileName);

int main()
{
    char option[2] = "1";
    while (isRunning)
    {
        switch(atoi(option))
        {
            case PRINT_HELP             :   printMenu();break;
            case READ_FROM_FILE         :   readStudentsFromFile(); break;
            case WRITE_TO_FILE          :   writeStudentsToFile(); break;
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

void writeStudentsToFile()
{
    char * fileName = (char*) malloc(sizeof(char) * 30);
    getOneValue("\nPut file name to write to: ", " %s", fileName);

    char option = '1';
    printf("\nT write to txt format put 1, to write to binary write 2");
    getOneValue("\nPut option: ", " %c", &option);
    switch(option)
    {
        case '1':
            txtWrite(fileName);
            printSizeOfFile(fileName);
            break;
        case '2':
            binWrite(fileName);
            printSizeOfFile(fileName);
            break;
        default:
            printf("\nSelected wrong option!!!\n");
    }

    free(fileName);
}

void binWrite(char* fileName)
{
    FILE* file = fopen(fileName, "w+b");
    for (int i = 0; i < numOfStudents; ++i)
    {
        fwrite(students[i].name, sizeof(char), strlen(students[i].name), file);
        fwrite(" ", sizeof(char), 1, file);
        fwrite(students[i].surname, sizeof(char), strlen(students[i].surname), file);
        fwrite(" ", sizeof(char), 1, file);
        fwrite(&students[i].date_birth.year, sizeof(int), 1, file);
        fwrite(&students[i].date_birth.month, sizeof(int), 1, file);
        fwrite(&students[i].date_birth.day, sizeof(int), 1, file);
        fwrite(&students[i].date_joined.year, sizeof(int), 1, file);
        fwrite(&students[i].date_joined.month, sizeof(int), 1, file);
        fwrite(&students[i].date_joined.day, sizeof(int), 1, file);
        fwrite(&students[i].gender, sizeof(char), 1, file);
    }
    fclose(file);
}

void txtWrite(char* fileName)
{
    FILE* file = fopen(fileName, "w+t");
    for (int i = 0; i < numOfStudents; ++i)
    {
        fprintf(file, "%s %s %d-%d-%d %d-%d-%d %c\n",
                students[i].name,
                students[i].surname,
                students[i].date_birth.day,
                students[i].date_birth.month,
                students[i].date_birth.year,
                students[i].date_joined.day,
                students[i].date_joined.month,
                students[i].date_joined.year,
                students[i].gender);
    }
    fclose(file);
}

void printSizeOfFile(char* fileName)
{
    FILE* file = fopen(fileName, "rt");
    fseek(file, 0, SEEK_END);
    printf("Size of file: %lu Bytes", ftell(file));
}

int getNumOfLines(char* fileName)
{
    FILE* file = fopen(fileName, "rt");
    char line[110] = {""};
    int numOfLines = 0;
    while (fgets(line, sizeof(line), file) != NULL)
        numOfLines++;
    return numOfLines;
}

void getStudentFromLine(char* line)
{
    sscanf(line, "%s %s %d-%d-%d, %d-%d-%d, %c",
                students[numOfStudents].name,
                students[numOfStudents].surname,
                &students[numOfStudents].date_birth.year,
                &students[numOfStudents].date_birth.month,
                &students[numOfStudents].date_birth.day,
                &students[numOfStudents].date_joined.year,
                &students[numOfStudents].date_joined.month,
                &students[numOfStudents].date_joined.day,
                &students[numOfStudents].gender);

    size_t length = strlen(students[numOfStudents].surname) - 1;
    char * end = students[numOfStudents].surname + length;
    *end = '\0';
    students[numOfStudents].age = getAge(&students[numOfStudents].date_birth);
}

char* readStringFromBinary(FILE* file)
{
    char* string = malloc(sizeof(char) * 20);
    int length = 0;
    unsigned char buf;
    while(fread(&buf, sizeof(buf), 1, file))
    {
        if(buf == ' ') break;
        string[length] = buf;
        length++;
    }
    string[length] = '\0';
    if (length == 0) return "";
    return string;
}

Student readStudentFromBin(FILE* file)
{
    Student temp;
    char* name = readStringFromBinary(file);
    strcpy(temp.name, name);
    strcpy(temp.surname, readStringFromBinary(file));
    fread(&temp.date_birth.year, sizeof(int), 1, file);
    fread(&temp.date_birth.month, sizeof(int), 1, file);
    fread(&temp.date_birth.day, sizeof(int), 1, file);
    fread(&temp.date_joined.year, sizeof(int), 1, file);
    fread(&temp.date_joined.month, sizeof(int), 1, file);
    fread(&temp.date_joined.day, sizeof(int), 1, file);
    fread(&temp.gender, sizeof(char), 1, file);
    return temp;
}

void readFromBin(char* fileName)
{
    FILE* file = fopen(fileName, "rb");

    if (file != NULL)
    {
        while (true)
        {
            Student tempStudent = readStudentFromBin(file);
            if (strlen(tempStudent.name) == 0) break;
            numOfStudents++;
            students = (Student*)realloc(students,sizeof(Student) * numOfStudents );
            copyStudents(&students[numOfStudents -1], &tempStudent);
        }
    }
}

void readFromTxt(char* fileName)
{
    FILE* file = fopen(fileName, "rt");

    if (file != NULL)
    {
        printSizeOfFile(fileName);

        int allocationNumber = numOfStudents + getNumOfLines(fileName);
        students = (Student*)realloc(students,sizeof(Student) * allocationNumber );

        char line[110] = {""};
        while (fgets(line, sizeof(line), file) != NULL)
        {
            getStudentFromLine(line);
            (numOfStudents)++;
        }
        fclose(file);
    }
    else
    {
        printf("ERROR: Couldn't open file!!!\n");
    }
}

void readStudentsFromFile()
{
    char * fileName = (char*)malloc(sizeof(char) * 30);
    getOneValue("\nPut file name to read from: ", " %s", fileName);
    char option = '1';
    printf("\nRead from txt option 1, form binary 2");
    getOneValue("\nPut option to read from: ", " %c", &option);

    switch(option)
    {
        case '1'     :    readFromTxt(fileName);break;
        case '2'     :    readFromBin(fileName);break;
    }
    free(fileName);
}

