/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Matthew Nyarko                                                        */
/*--------------------------------------------------------------------*/
#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
 * replaceAndWrite:
 * ----------------
 * If pcFrom is the empty string, writes pcLine to stdout and returns 0.
 * Otherwise, writes pcLine to stdout with every distinct occurrence of pcFrom
 * replaced with pcTo, and returns the count of how many replacements were made.
 *
 * Parameters:
 *   pcLine - a null-terminated input line.
 *   pcFrom - the substring to be replaced (must not be empty).
 *   pcTo   - the replacement substring.
 *
 * Returns:
 *   The number of replacements performed.
 */
static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo)
{
   size_t count = 0;
   
   /* If pcFrom is empty, output pcLine unchanged and return 0 replacements */
   if (pcFrom[0] == '\0') {
      fputs(pcLine, stdout);
      return 0;
   }
   
   const char *current = pcLine;
   char *pos;
   size_t fromLen = Str_getLength(pcFrom);
   
   while (*current != '\0') {
      /* Find the next occurrence of pcFrom in the current portion of the line */
      pos = Str_search(current, pcFrom);
      
      if (pos == NULL) {
         /* No further occurrence found; output the rest of the line */
         fputs(current, stdout);
         break;
      }
      
      /* Output characters from current up to the found occurrence */
      for (const char *p = current; p < pos; p++) {
         putchar(*p);
      }
      
      /* Output the replacement string */
      fputs(pcTo, stdout);
      
      count++;  /* Increment the replacement count */
      
      /* Advance current pointer past the replaced segment */
      current = pos + fromLen;
   }
   
   return count;
}

/*
 * main:
 * -----
 * If the argument count is not 3, writes an error message to stderr and returns
 * EXIT_FAILURE. Otherwise, for each line read from stdin, replaces every occurrence
 * of argv[1] with argv[2] and writes the modified line to stdout. After processing
 * all input, writes the total number of replacements to stderr.
 */
int main(int argc, char *argv[])
{
   enum { MAX_LINE_SIZE = 4096 };
   enum { PROPER_ARG_COUNT = 3 };

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT) {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   /* Process each line from stdin and accumulate the replacement count */
   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {
      uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);
   }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
