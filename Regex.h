/*  Regex.h
    Description: Interface functions for my Regex Engine
    Author:      Joshua Morton
    Date:        11/11/14
*/

//#ifndef REGEX_H
//#define REGEX_H

/* Returns 1 if string matches the pattern and 0 otherwise */
int match(char *pattern, char *string);

/* Returns the first match in string or a NULL pointer if no match */
char *search(char *pattern, char *string);

/* Returns an array of all matches in string and stores the number of matches in n */
char **findall(char *pattern, char *string, int *n);

//#endif
