#include "stud_file.h"
#include "stud_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printSizeOfFile(char* fileName)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");
    fseek(file, 0, SEEK_END);
    printf("Size of file: %lu Bytes", ftell(file));
}

void txtWrite(char* fileName, Student* students, int numOfStudents)
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

void binWrite(char* fileName, Student* students, int numOfStudents)
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

Student* writeStudentsToFile(Student* students, int numOfStudents)
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
    return students;
}

int getNumOfLines(char* fileName)
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

void getStudentFromLine(char* line, Student* student)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    sscanf(line, "%s %s %d-%d-%d, %d-%d-%d, %c",
                student->name,
                student->surname,
                &student->date_birth.year,
                &student->date_birth.month,
                &student->date_birth.day,
                &student->date_joined.year,
                &student->date_joined.month,
                &student->date_joined.day,
                &student->gender);

    size_t length = strlen(student->surname) - 1;
    char * end = student->surname + length;
    *end = '\0';
    student->age = getAge(&student->date_birth);
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

Student* readFromTxt(char* fileName, Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");

    if (file != NULL)
    {
        printSizeOfFile(fileName);

        int allocationNumber = (*numOfStudents) + getNumOfLines(fileName);
        students = (Student*) realloc(students, sizeof(Student) * allocationNumber );

        char line[110] = {""};
        while (fgets(line, sizeof(line), file) != NULL)
        {
            getStudentFromLine(line, &students[*numOfStudents]);
            (*numOfStudents)++;
        }
        fclose(file);
    }
    else
    {
        printf("ERROR: Couldn't open file!!!\n");
    }
    return students;
}

Student* readFromBin(char* fileName, Student* students, int* numOfStudents)
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
            if (strlen(tempStudent.name) == 0) break;
            (*numOfStudents)++;
            students = (Student*) realloc(students, sizeof(Student) * (*numOfStudents) );
            copyStudents(&students[*numOfStudents - 1], &tempStudent);
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

