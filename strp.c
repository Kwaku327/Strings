#include "str.h"
#include <assert.h>

/* Returns the length of the string pcSrc using pointer arithmetic. */
size_t Str_getLength(const char *pcSrc)
{
    const char *ptr = pcSrc;
    assert(pcSrc != NULL);
    while (*ptr != '\0') {
        /* Advance pointer until the null terminator. */
        ptr++;
    }
    return (size_t)(ptr - pcSrc);
}

/* Copies the string from pcSrc to pcDest using pointer arithmetic. */
char *Str_copy(char *pcDest, const char *pcSrc)
{
    char *destStart = pcDest;
    assert(pcDest != NULL && pcSrc != NULL);
    while ((*pcDest = *pcSrc) != '\0') {
        pcDest++;
        pcSrc++;
    }
    return destStart;
}

/* Concatenates pcSrc onto the end of pcDest using pointer arithmetic. */
char *Str_concat(char *pcDest, const char *pcSrc)
{
    char *destStart = pcDest;
    assert(pcDest != NULL && pcSrc != NULL);
    
    /* Move pcDest to the end of the string. */
    while (*pcDest != '\0') {
        pcDest++;
    }
    /* Copy pcSrc to pcDest. */
    while ((*pcDest = *pcSrc) != '\0') {
        pcDest++;
        pcSrc++;
    }
    return destStart;
}

/* Compares two strings using pointer arithmetic.
   Returns 0 if they match, or the difference between mismatched characters. */
int Str_compare(const char *pcS1, const char *pcS2)
{
    assert(pcS1 != NULL && pcS2 != NULL);
    while (*pcS1 && *pcS2 && (*pcS1 == *pcS2)) {
        pcS1++;
        pcS2++;
    }
    return (int)((unsigned char)*pcS1 - (unsigned char)*pcS2);
}

/* Searches for the first occurrence of pcNeedle in pcHaystack using pointer arithmetic.
   Returns a pointer to the beginning of the found substring or NULL if not found.
   If pcNeedle is empty, returns pcHaystack. */
char *Str_search(const char *pcHaystack, const char *pcNeedle)
{
    const char *h, *n;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    if (*pcNeedle == '\0') {
        return (char *)pcHaystack;
    }
    while (*pcHaystack != '\0') {
        h = pcHaystack;
        n = pcNeedle;
        while (*h != '\0' && *n != '\0' && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0') {  /* Entire needle matched. */
            return (char *)pcHaystack;
        }
        pcHaystack++;
    }
    return NULL;
}
