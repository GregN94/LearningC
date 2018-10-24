#include "stud_file.h"
#include "stud_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printFileSize(const char *fileName)
{
    DEBUG("");
    FILE* file = fopen(fileName, "rt");
    fseek(file, 0, SEEK_END);
    printf( "Size of file: %lu Bytes", ftell(file) );
}

void writeStudentToFile(FILE* file, const Student* student)
{
    DEBUG("");
    fprintf(file, "%s %s %d-%d-%d %d-%d-%d %c\n",
            student->name,
            student->surname,
            student->date_birth.day,
            student->date_birth.month,
            student->date_birth.year,
            student->date_joined.day,
            student->date_joined.month,
            student->date_joined.year,
            student->gender);
}

void txtWrite(const char* fileName, const Student* students, const int numOfStudents)
{
    DEBUG("");
    FILE* file = fopen(fileName, "w+t");
    for (int i = 0; i < numOfStudents; ++i)
    {
        writeStudentToFile(file, &students[i]);
    }
    fclose(file);
}

void binWrite(const char* fileName, const Student* students, const int numOfStudents)
{
    DEBUG("");
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
    DEBUG("");
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
    DEBUG("");
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
    DEBUG("");
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
    DEBUG("");
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

void operationOnFile(const char* fileName,
                         const char* option,
                         Student* students,
                         int* numOfStudents,
                         void operation(FILE*, Student*, int*))
{
    DEBUG("");
    FILE* file = fopen(fileName, option);

    if ( file != NULL )
    {
        printFileSize(fileName);
        operation(file, students, numOfStudents);
        printf("\nNum of students after reading: %d\n", *numOfStudents);
        fclose(file);
    }
    else
    {
        printf("ERROR: Couldn't open file!!!\n");
    }
}

void readFromTxt(FILE* file, Student* students, int* numOfStudents)
{
    DEBUG("");
    char line[110] = "";
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Student tempStudent = getStudentFromLine(line);
        addNewStudent(students, numOfStudents, tempStudent);
    }
}

void readFromBin(FILE* file, Student* students, int* numOfStudents)
{
    DEBUG("");
    while (true)
    {
        Student tempStudent = readStudentFromBin(file);
        if (strlen(tempStudent.name) == 0) break;

        addNewStudent(students, numOfStudents, tempStudent);
    }
}

void readStudentsFromFile(Student* students, int* numOfStudents)
{
    DEBUG("");
    char fileName[30] = "";
    getOneValue("\nPut file name to read from: ", " %s", fileName);
    char option = '1';
    printf("\nRead from txt option 1, form binary 2");
    getOneValue("\nPut option to read from: ", " %c", &option);

    switch(option)
    {
        case '1'  :
            operationOnFile(fileName, "rt", students, numOfStudents, readFromTxt);
            break;
        case '2'  :
            operationOnFile(fileName, "rb", students, numOfStudents, readFromBin);
            break;
        default:
            printf("\nThere in no such option");
            break;
    }
}

