#ifndef __STUD_TYPES_H__
#define __STUD_TYPES_H__

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

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct Student
{
    char name[16];
    char surname[16];
    unsigned int age;
    Date date_birth;
    Date date_joined;
    char gender;
    void (*print)(struct Student*);
} Student;


#endif
