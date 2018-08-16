#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char name[30];
    char surname[30];
    unsigned int age;
    Date date_birth;
    Date date_joined;
    char gender;
} Student;

typedef enum
{
    PRINT_HELP = 1,
    READ_FROM_FILE,
    WRITE_TO_FILE,
    DELETE_ALL_STUDENTS,
    PRINT_ONE_STUDENT,
    PRINT_ALL_STUDENTS,
    ADD_NEW_STUDENT,
    DELETE_ONE_STUDENT,
    SORT_STUDENTS,
    CLOSE_PROGRAM
} Options;

typedef enum
{
    NAME = 1,
    SURNAME,
    AGE,
    DATE_JOINED,
} SortingOptions;

bool isRunning = true;
Date today = {6, 8, 2018};
Student * students = NULL;
int numOfStudents = 0;

void getOneValue(char* textToPrint, char* format, void* mem);
void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3);
void copyStudents(Student* destination, Student* source);
void swapStudents(Student* left, Student* right);
void printStudentByIndex(int index);
void printAllStudents();
void printOneStudent();
void addNewStudent();
void deleteStudent();
Student* killStudents();
void readStudentsFromFile();
void writeStudentsToFile();
void printSizeOfFile(char* fileName);
int getNumOfLines(char* fileName);
void txtWrite(char* fileName);
void binWrite(char* fileName);
int getAge(Date* birthDate);
void printMenu();
void sortStudents();
void sort(bool checkFunc(Student left, Student right));

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
            case DELETE_ALL_STUDENTS    :   killStudents(); break;
            case PRINT_ONE_STUDENT      :   printOneStudent();break;
            case PRINT_ALL_STUDENTS     :   printAllStudents();break;
            case ADD_NEW_STUDENT        :   addNewStudent();break;
            case DELETE_ONE_STUDENT     :   deleteStudent();break;
            case SORT_STUDENTS          :   sortStudents();break;
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

void printStudentByIndex(int index)
{
        printf("Name: %s, surname: %s, Age: %d, Day_joined: %d %d %d, Gender: %c\n",
                               students[index].name,
                               students[index].surname,
                               students[index].age,
                               students[index].date_joined.day,
                               students[index].date_joined.month,
                               students[index].date_joined.year,
                               students[index].gender);
}

void printAllStudents()
{
    printf("\nPrinting all stuents:\n");
    for (int index = 0; index < numOfStudents; ++index)
    {
        printStudentByIndex(index);
    }
}

void printOneStudent()
{
    int index = -1;
    getOneValue("\nPut student index to print: ", " %d", &index);
    printf("\n");
    if (index < numOfStudents && index > -1)
    {
        printStudentByIndex(index);
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

int getAge(Date* birthDate)
{
    if (birthDate->month < today.month)
        birthDate->year--;
    else if (birthDate->month == today.month)
    {
        if (birthDate->day <= today.day)
            birthDate->year--;
    }
    int age = today.year - birthDate->year -1;
    if (age < 0) age = 0;
    return age;
}

void addNewStudent()
{
    students = (Student*) realloc(students,sizeof(Student) * ++numOfStudents);
    Date birthDate;

    getOneValue("\nName: ", " %s", students[numOfStudents-1].name);
    getOneValue("\nSurname: ", " %s", students[numOfStudents-1].surname);
    getThreeValues("\nDate of birth: ", " %d %d %d", &birthDate.day,
                                                     &birthDate.month,
                                                     &birthDate.year);
    getThreeValues("\nDate joined: ", " %d %d %d", &students[numOfStudents-1].date_joined.day,
                                                   &students[numOfStudents-1].date_joined.month,
                                                   &students[numOfStudents-1].date_joined.year);
    getOneValue("\nGender: ", " %c", &students[numOfStudents-1].gender);

    students[numOfStudents - 1].age = getAge(&birthDate);
}

void getThreeValues(char* textToPrint, char* format, void* mem,
                                                     void* mem2,
                                                     void* mem3)
{
    printf("%s", textToPrint);
    scanf(format, mem, mem2, mem3);
}

void getOneValue(char* textToPrint, char* format, void* mem)
{
    printf("%s", textToPrint);
    scanf(format, mem);
}

void copyStudents(Student* destination, Student* source)
{
    strcpy(destination->name, source->name);
    strcpy(destination->surname, source->surname);
    destination->age = source->age;
    destination->date_joined = source->date_joined;
    destination->gender = source->gender;
}

void deleteStudent()
{
    int index = -1;
    getOneValue("\nPut student index to delete: ", " %d", &index);
    printf("\n");
    if (index < numOfStudents && index > -1)
    {
        for (int i = index; i < numOfStudents -1; i++)
        {
            copyStudents(&students[i], &students[i + 1]);
        }
        numOfStudents--;
        students = (Student*) realloc(students, sizeof(Student) * numOfStudents);
    }
    else
    {
        printf("Incorrect index\n");
    }
}


Student* killStudents()
{
    numOfStudents = 0;
    return realloc(students, sizeof(Student) * numOfStudents);
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

void printMenu()
{
    printf("\nAvaiable options:");
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

void printSortingOptions()
{
    printf("\nAvaiable options:");
    printf("\n1. Name");
    printf("\n2. Surname");
    printf("\n3. Age");
    printf("\n4. Date joined");
}

bool byName(Student left, Student right)
{
    return *left.name > *right.name;
}

bool bySurname(Student left, Student right)
{
    return *left.surname > *right.surname;
}

bool byAge(Student left, Student right)
{
    return left.age > right.age;
}

bool byJoinedDate(Student left, Student right)
{
    bool isBigger = false;
    if ( left.date_joined.year > right.date_joined.year)
    {
        isBigger = true;
    }
    else if ( left.date_joined.year == right.date_joined.year)
    {
        if ( left.date_joined.month > right.date_joined.month)
        {
            isBigger = true;
        }
        else if ( left.date_joined.month == right.date_joined.month)
        {
            if ( left.date_joined.day > right.date_joined.day)
            {
                isBigger = true;
            }
        }
    }
    return isBigger;
}

void sort(bool checkFunc(Student left, Student right))
{
    for (int i = 1; i <= numOfStudents; ++i)
    {
        for (int j = 0; j < numOfStudents - i; ++j)
        {
            if (checkFunc(students[j], students[j + 1]))
                swapStudents(&students[j], &students[j + 1]);
        }
    }
}

void swapStudents(Student* left, Student* right)
{
    Student tempStudent;
    copyStudents(&tempStudent, left);
    copyStudents(left, right);
    copyStudents(right, &tempStudent);
}

void sortStudents()
{
    char option = '6';
    printSortingOptions();
    getOneValue("\nSelected option: ", " %c", &option);

    switch(atoi(&option))
    {
        case NAME            :    sort(byName);break;
        case SURNAME         :    sort(bySurname);break;
        case AGE             :    sort(byAge);break;
        case DATE_JOINED     :    sort(byJoinedDate);break;
        default              :    printf("\nSelected wrong option!!\n");break;
    }

}
