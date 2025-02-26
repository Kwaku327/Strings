#include "str.h"
#include <assert.h>

/*
 * Str_getLength
 * -------------
 * Returns the length of the null-terminated string pcSrc, not counting
 * the terminating '\0'.
 *
 * Parameters:
 *   pcSrc - pointer to a null-terminated string.
 *
 * Returns:
 *   The number of characters in pcSrc.
 */
size_t Str_getLength(const char pcSrc[])
{
    size_t length = 0;
    assert(pcSrc != NULL);
    while (pcSrc[length] != '\0') {
        length++;  // Increment index until end-of-string.
    }
    return length;
}

/*
 * Str_copy
 * --------
 * Copies the string from pcSrc to pcDest (including the terminating '\0').
 *
 * Parameters:
 *   pcDest - pointer to the destination array (must be large enough).
 *   pcSrc  - pointer to the source string.
 *
 * Returns:
 *   The pointer to pcDest.
 */
char *Str_copy(char pcDest[], const char pcSrc[])
{
    size_t i = 0;
    assert(pcDest != NULL && pcSrc != NULL);
    while (pcSrc[i] != '\0') {
        pcDest[i] = pcSrc[i];
        i++;
    }
    pcDest[i] = '\0';  // Append null terminator.
    return pcDest;
}

/*
 * Str_concat
 * ----------
 * Appends the string pcSrc to the end of the string in pcDest.
 *
 * Parameters:
 *   pcDest - pointer to the destination array (must have enough space).
 *   pcSrc  - pointer to the source string.
 *
 * Returns:
 *   The pointer to pcDest.
 */
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
    pcDest[destLen + i] = '\0';  // Terminate the concatenated string.
    return pcDest;
}

/*
 * Str_compare
 * -----------
 * Compares the two strings pcS1 and pcS2.
 *
 * Parameters:
 *   pcS1 - pointer to the first string.
 *   pcS2 - pointer to the second string.
 *
 * Returns:
 *   0 if the strings are equal;
 *   a negative value if pcS1 is less than pcS2;
 *   a positive value if pcS1 is greater than pcS2.
 */
int Str_compare(const char pcS1[], const char pcS2[])
{
    size_t i = 0;
    assert(pcS1 != NULL && pcS2 != NULL);
    while (pcS1[i] != '\0' && pcS2[i] != '\0') {
        if (pcS1[i] != pcS2[i]) {
            return (unsigned char)pcS1[i] - (unsigned char)pcS2[i];
        }
        i++;
    }
    /* Compare terminating characters (or differences in length) */
    return (unsigned char)pcS1[i] - (unsigned char)pcS2[i];
}

/*
 * Str_search
 * ----------
 * Searches for the first occurrence of the substring pcNeedle in pcHaystack.
 *
 * Parameters:
 *   pcHaystack - pointer to the string to be searched.
 *   pcNeedle   - pointer to the substring to search for.
 *
 * Returns:
 *   A pointer to the beginning of the first occurrence of pcNeedle in
 *   pcHaystack, or NULL if not found. If pcNeedle is empty, returns pcHaystack.
 */
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
            /* Break if end of haystack reached or characters do not match */
            if (pcHaystack[i + j] == '\0' || pcHaystack[i + j] != pcNeedle[j]) {
                break;
            }
        }
        if (pcNeedle[j] == '\0') {  // Entire needle matched.
            return (char *)&pcHaystack[i];
        }
    }
    return NULL;  // No match found.
}
