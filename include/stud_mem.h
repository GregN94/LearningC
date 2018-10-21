#ifndef RUN_STUD_MEM_H
#define RUN_STUD_MEM_H

#include <stddef.h>

void* my_memcpy(void *dest, const void *src, size_t count );
int my_memcmp ( const void * ptr1, const void * ptr2, size_t num );
void* my_memset( void* dest, int ch, size_t count );

#endif //RUN_STUD_MEM_H
