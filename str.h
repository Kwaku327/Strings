#ifndef STR_H
#define STR_H

#include <stddef.h>
#include <assert.h>

/*
 * Str_getLength:
 *   Returns the length of the null-terminated string pcSrc, not counting the terminating '\0'.
 *
 *   Parameters:
 *     pcSrc - pointer to a null-terminated string.
 *
 *   Returns:
 *     The number of characters in pcSrc.
 */
size_t Str_getLength(const char pcSrc[]);

/*
 * Str_copy:
 *   Copies the string from pcSrc (including the terminating null byte) into pcDest.
 *
 *   Parameters:
 *     pcDest - pointer to the destination array (which must be large enough).
 *     pcSrc  - pointer to the source string.
 *
 *   Returns:
 *     The pointer to pcDest.
 */
char *Str_copy(char pcDest[], const char pcSrc[]);

/*
 * Str_concat:
 *   Appends the string pcSrc to the end of the string in pcDest.
 *
 *   Parameters:
 *     pcDest - pointer to the destination array (should have enough space for the result).
 *     pcSrc  - pointer to the source string.
 *
 *   Returns:
 *     The pointer to pcDest.
 */
char *Str_concat(char pcDest[], const char pcSrc[]);

/*
 * Str_compare:
 *   Compares the two strings pcS1 and pcS2.
 *
 *   Parameters:
 *     pcS1 - pointer to the first string.
 *     pcS2 - pointer to the second string.
 *
 *   Returns:
 *     An integer that is less than, equal to, or greater than zero if pcS1 is found,
 *     respectively, to be less than, equal to, or greater than pcS2.
 */
int Str_compare(const char pcS1[], const char pcS2[]);

/*
 * Str_search:
 *   Searches for the first occurrence of the substring pcNeedle in pcHaystack.
 *
 *   Parameters:
 *     pcHaystack - pointer to the string to be searched.
 *     pcNeedle   - pointer to the substring to search for.
 *
 *   Returns:
 *     A pointer to the beginning of the found substring or NULL if the substring is not found.
 *     If pcNeedle is an empty string, returns pcHaystack.
 */
char *Str_search(const char pcHaystack[], const char pcNeedle[]);

#endif /* STR_H */


