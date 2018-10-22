#ifndef RUN_STUD_TEMP_H
#define RUN_STUD_TEMP_H

#include "stud_types.h"
#include <stdbool.h>

void createNewTemp();
void appendToTemp(const Student student);
void printFromTemp();
bool isNewInTemp(const Student *newStudent); //TODO fix it

#endif //RUN_STUD_TEMP_H