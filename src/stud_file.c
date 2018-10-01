#include "stud_file.h"
#include "stud_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printSizeOfFile(const char* fileName)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");
    fseek(file, 0, SEEK_END);
    printf("Size of file: %lu Bytes", ftell(file));
}

void txtWrite(const char* fileName, const Student* students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
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

void binWrite(const char* fileName, const Student* students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
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

void writeStudentsToFile(const Student* students, const int numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    char * fileName = (char*) malloc(sizeof(char) * 30);
    getOneValue("\nPut file name to write to: ", " %s", fileName);

    char option = '1';
    printf("\nT write to txt format put 1, to write to binary write 2");
    getOneValue("\nPut option: ", " %c", &option);
    switch(option)
    {
        case '1':
            txtWrite(fileName, students, numOfStudents);
            printSizeOfFile(fileName);
            break;
        case '2':
            binWrite(fileName, students, numOfStudents);
            printSizeOfFile(fileName);
            break;
        default:
            printf("\nSelected wrong option!!!\n");
    }

    free(fileName);
}

int getNumOfLines(const char* fileName)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");
    char line[110] = {""};
    int numOfLines = 0;
    while (fgets(line, sizeof(line), file) != NULL)
        numOfLines++;
    return numOfLines;
}

Student getStudentFromLine(const char* line)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    Student tempStudent;
    memset(&tempStudent, 0, sizeof(Student));
    sscanf(line, "%s %s %d-%d-%d, %d-%d-%d, %c",
                tempStudent.name,
                tempStudent.surname,
                &tempStudent.date_birth.year,
                &tempStudent.date_birth.month,
                &tempStudent.date_birth.day,
                &tempStudent.date_joined.year,
                &tempStudent.date_joined.month,
                &tempStudent.date_joined.day,
                &tempStudent.gender);

    size_t length = strlen(tempStudent.surname) - 1;
    char * end = tempStudent.surname + length;
    *end = '\0';
    tempStudent.age = getAge(tempStudent.date_birth);
    return tempStudent;
}

char* readStringFromBinary(FILE* file)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    char* string = (char*) malloc(sizeof(char) * 20);
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
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    Student tempStudent;
    memset(&tempStudent, 0, sizeof(Student));
    char* name = readStringFromBinary(file);
    strcpy(tempStudent.name, name);
    strcpy(tempStudent.surname, readStringFromBinary(file));
    fread(&tempStudent.date_birth.year, sizeof(int), 1, file);
    fread(&tempStudent.date_birth.month, sizeof(int), 1, file);
    fread(&tempStudent.date_birth.day, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.year, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.month, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.day, sizeof(int), 1, file);
    fread(&tempStudent.gender, sizeof(char), 1, file);
    return tempStudent;
}

bool checkIfStudentExist(const Student* tempStudent, Student* students, const int numOfStudents)
{
    for (int i = 0; i < numOfStudents; ++i)
    {
        if (0 == memcmp(tempStudent, &students[i], sizeof(Student)))
            return true;
    }
    return false;
}

Student* readFromTxt(const char* fileName, Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");

    if (file != NULL)
    {
        printSizeOfFile(fileName);

        char line[110] = {""};
        while (fgets(line, sizeof(line), file) != NULL)
        {
            Student tempStudent = getStudentFromLine(line);
            if ( false == checkIfStudentExist(&tempStudent, students, *numOfStudents))
            {
                students = (Student*) realloc(students, sizeof(Student) * ( ++(*numOfStudents) ) );
                memcpy(&students[*numOfStudents - 1], &tempStudent, sizeof(Student));
            }
        }
        fclose(file);
    }
    else
    {
        printf("ERROR: Couldn't open file!!!\n");
    }
    return students;
}

Student* readFromBin(const char* fileName, Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rb");

    if (file != NULL)
    {
        while (true)
        {
            Student tempStudent = readStudentFromBin(file);
            if ( false == checkIfStudentExist(&tempStudent, students, *numOfStudents))
            {
                if (strlen(tempStudent.name) == 0) break;
                (*numOfStudents)++;
                students = (Student*) realloc(students, sizeof(Student) * (*numOfStudents) );
                copyStudents(&students[*numOfStudents - 1], &tempStudent);
            }
        }
    }
    return students;
}

Student* readStudentsFromFile(Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    char* fileName = (char*)malloc(sizeof(char) * 30);
    getOneValue("\nPut file name to read from: ", " %s", fileName);
    char option = '1';
    printf("\nRead from txt option 1, form binary 2");
    getOneValue("\nPut option to read from: ", " %c", &option);

    switch(option)
    {
        case '1'  :   students = readFromTxt(fileName, students, numOfStudents);break;
        case '2'  :   students = readFromBin(fileName, students, numOfStudents);break;
    }
    free(fileName);
    return students;
}

