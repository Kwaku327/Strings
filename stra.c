#include "str.h"
#include <assert.h>

/* Returns the length of the string pcSrc (array-based version). */
size_t Str_getLength(const char pcSrc[])
{
    size_t length = 0;
    assert(pcSrc != NULL);
    while (pcSrc[length] != '\0') {
        /* Increment index until end-of-string. */
        length++;
    }
    return length;
}

/* Copies the string from pcSrc to pcDest (array-based version). */
char *Str_copy(char pcDest[], const char pcSrc[])
{
    size_t i = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0') {
        pcDest[i] = pcSrc[i];
        i++;
    }
    pcDest[i] = '\0';  /* Append null terminator. */
    return pcDest;
}

/* Concatenates pcSrc to the end of pcDest (array-based version). */
char *Str_concat(char pcDest[], const char pcSrc[])
{
    size_t destLen = 0;
    size_t i = 0;
    assert(pcDest != NULL && pcSrc != NULL);

    /* Find the end of the destination string */
    while (pcDest[destLen] != '\0') {
        destLen++;
    }
    /* Copy characters from pcSrc to the end of pcDest */
    while (pcSrc[i] != '\0') {
        pcDest[destLen + i] = pcSrc[i];
        i++;
    }
    pcDest[destLen + i] = '\0';  /* Terminate the concatenated string. */
    return pcDest;
}

/* Compares the two strings pcS1 and pcS2 (array-based version). */
int Str_compare(const char pcS1[], const char pcS2[])
{
    size_t i = 0;
    assert(pcS1 != NULL && pcS2 != NULL);
    while (pcS1[i] != '\0' && pcS2[i] != '\0') {
        if (pcS1[i] != pcS2[i]) {
            return (int)((unsigned char)pcS1[i] - (unsigned char)pcS2[i]);
        }
        i++;
    }
    return (int)((unsigned char)pcS1[i] - (unsigned char)pcS2[i]);
}

/* Searches for the first occurrence of pcNeedle in pcHaystack (array-based version). */
char *Str_search(const char pcHaystack[], const char pcNeedle[])
{
    size_t i, j;
    assert(pcHaystack != NULL && pcNeedle != NULL);
    
    /* If the needle is an empty string, return the haystack */
    if (pcNeedle[0] == '\0') {
        return (char *)pcHaystack;
    }
    
    for (i = 0; pcHaystack[i] != '\0'; i++) {
        for (j = 0; pcNeedle[j] != '\0'; j++) {
            if (pcHaystack[i + j] == '\0' || pcHaystack[i + j] != pcNeedle[j]) {
                break;
            }
        }
        if (pcNeedle[j] == '\0') {  /* Entire needle matched. */
            return (char *)&pcHaystack[i];
        }
    }
    return NULL;
}
