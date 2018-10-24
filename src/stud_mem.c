#include <stdio.h>
#include "stud_utils.h"

void* my_memcpy( void *dest, const void *src, size_t count )
{
    DEBUG();
    unsigned char* dest_ptr = (unsigned char*) dest;
    unsigned char* src_ptr = (unsigned char*) src;
    for (size_t i = 0; i < count; ++i)
    {
        *(dest_ptr++) = *(src_ptr++);
    }
    return dest;
}

int my_memcmp ( const void * ptr1, const void * ptr2, size_t num )
{
    DEBUG();
    unsigned char* ptr1_chr = (unsigned char*) ptr1;
    unsigned char* ptr2_chr = (unsigned char*) ptr2;

    for (size_t i = 0; i < num; ++i)
    {
        if ( *ptr1_chr < * ptr2_chr ) return -1;
        else if ( *ptr1_chr > * ptr2_chr ) return 1;
        ptr1_chr++;
        ptr2_chr++;
    }
    return 0;
}

void* my_memset( void* dest, int ch, size_t count )
{
    DEBUG();
    unsigned char* dest_chr = (unsigned char*) dest;

    for (size_t i = 0; i < count; ++i)
    {
        *dest_chr = (unsigned char) ch;
        dest_chr++;
    }
    return dest;
}
