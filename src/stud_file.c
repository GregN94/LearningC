#include "stud_file.h"
#include "stud_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#if OWN_MEM_FUNC
#define memset(dest, ch, count) my_memset(dest, ch, count)
#endif

extern void* my_memset( void* dest, int ch, size_t count );

void printFileSize(const char *fileName)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, "rt");
    fseek(file, 0, SEEK_END);
    printf( "Size of file: %lu Bytes", ftell(file) );
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
    char fileName[30] = "";
    getOneValue("\nPut file name to write to: ", " %s", &fileName);

    char option = '1';
    printf("\nT write to txt format put 1, to write to binary write 2");
    getOneValue("\nPut option: ", " %c", &option);
    switch(option)
    {
        case '1':
            txtWrite(fileName, students, numOfStudents);
            printFileSize(fileName);
            break;
        case '2':
            binWrite(fileName, students, numOfStudents);
            printFileSize(fileName);
            break;
        default:
            printf("\nSelected wrong option!!!\n");
    }
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
    char* end = tempStudent.surname + length;
    *end = '\0';
    tempStudent.age = getAge(tempStudent.date_birth);

    if (tempStudent.gender == 'M')
        tempStudent.print = printMan;
    else
        tempStudent.print = printWoman;
    return tempStudent;
}

void readStringFromBin(FILE* file, char* string)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    int length = 0;
    unsigned char buf;
    while(fread(&buf, sizeof(buf), 1, file))
    {
        if(buf == ' ') break;
        string[length] = buf;
        length++;
    }
    string[length] = '\0';
}

Student readStudentFromBin(FILE* file)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    Student tempStudent;
    memset(&tempStudent, 0, sizeof(Student));
    readStringFromBin(file, tempStudent.name);
    readStringFromBin(file, tempStudent.surname);
    fread(&tempStudent.date_birth.year, sizeof(int), 1, file);
    fread(&tempStudent.date_birth.month, sizeof(int), 1, file);
    fread(&tempStudent.date_birth.day, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.year, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.month, sizeof(int), 1, file);
    fread(&tempStudent.date_joined.day, sizeof(int), 1, file);
    fread(&tempStudent.gender, sizeof(char), 1, file);
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

Student* operationOnFile(const char* fileName,
                         const char* option,
                         Student* students,
                         int* numOfStudents,
                         Student* operation(FILE*, Student*, int*))
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    FILE* file = fopen(fileName, option);

    if ( file != NULL )
    {
        printFileSize(fileName);
        students = operation(file, students, numOfStudents);
        fclose(file);
    }
    else
    {
        printf("ERROR: Couldn't open file!!!\n");
    }
    return students;
}

Student* readFromTxt(FILE* file, Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    char line[110] = "";
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Student tempStudent = getStudentFromLine(line);
        students = addNewStudent(students, numOfStudents, tempStudent);
    }
    return students;
}

Student* readFromBin(FILE* file, Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    while (true)
    {
        Student tempStudent = readStudentFromBin(file);
        if (strlen(tempStudent.name) == 0) break;

        students = addNewStudent(students, numOfStudents, tempStudent);
    }
    return students;
}

Student* readStudentsFromFile(Student* students, int* numOfStudents)
{
#ifdef DEBUG
    printf ("\nDEBUG: at %s, line %d.", __FILE__, __LINE__);
#endif
    char fileName[30] = "";
    getOneValue("\nPut file name to read from: ", " %s", fileName);
    char option = '1';
    printf("\nRead from txt option 1, form binary 2");
    getOneValue("\nPut option to read from: ", " %c", &option);

    switch(option)
    {
        case '1'  :
            students = operationOnFile(fileName, "rt", students, numOfStudents, readFromTxt);
            break;
        case '2'  :
            students = operationOnFile(fileName, "rb", students, numOfStudents, readFromBin);
            break;
        default:
            printf("\nThere in no such option");
            break;
    }
    return students;
}

