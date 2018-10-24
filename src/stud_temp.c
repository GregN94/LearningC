#include <memory.h>
#include "stud_temp.h"
#include "stud_file.h"
#include "stud_utils.h"

#define FILE_TEMP "temp.txt"

void createNewTemp()
{
    DEBUG("");
    fopen(FILE_TEMP, "w");
}

void appendToTemp(const Student student)
{
    DEBUG("");
    FILE* file = fopen(FILE_TEMP, "a");
    writeStudentToFile(file, &student);
    fclose(file);
}

void printFromTemp()
{
    DEBUG("");
    FILE* file = fopen(FILE_TEMP, "r+t");
    char line[110] = "";
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Student tempStudent = getStudentFromLine(line);
        tempStudent.print(&tempStudent);
    }
    fclose(file);
}

bool isNewInTemp(const Student *newStudent)
{
    DEBUG("");
    FILE* file = fopen(FILE_TEMP, "r+t");
    char line[110] = "";

    bool status = true;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        Student tempStudent = getStudentFromLine(line);
        if ( 0 == memcmp(newStudent, &tempStudent, sizeof(Student)) )
            status =  false;
    }
    fclose(file);
    return status;
}
