/*********************************************************
 *  Paul Valdez
 *  CPTS121 Spring 2018: Lab Section 13; BONUS ASSIGNMENT
 *  April 28th 2018
 *  Description: This Program is a copy of the string.h library, designed by me. It also tests each method for working.
 *  Created by Paul Valdez on 4/25/18.
 *
 **********************************************************/

#ifndef Functions_h
#define Functions_h

#include <stdio.h>
#define MY_EOF -1

/*********************************************
 * Function: int my_strlen (const char *s);
 * Date Created: April 28th 2018
 * Description: Finds the length of an inputted string, without counting the null character.
 * Input Parameters: const char *s
 * Returns: An integer value
 * Pre-condition: An inputted string
 * Post-condition: The length of the string is found.
 *********************************************/
int my_strlen (const char *s);

/*********************************************
 * Function: int my_strcmp (const char *s1, const char *s2);
 * Date Created: April 28th 2018
 * Description: Compares the two strings, returning -1 if s1 is greater then s2, 0 if equal, and 1 otherwise
 * Input Parameters: const char *s1, const char *s2
 * Returns: An integer value
 * Pre-condition: two inputted strings
 * Post-condition: The two strings are compared
 *********************************************/
int my_strcmp (const char *s1, const char *s2);

/*********************************************
 * Function: int my_strncmp (const char *s1, const char *s2, int n);
 * Date Created: April 28th 2018
 * Description: Compares the two strings n characters, returning -1 if s1 is greater then s2, 0 if equal, and 1 otherwise
 * Input Parameters: const char *s1, const char *s2, int n
 * Returns: An integer value
 * Pre-condition: two inputted strings, and an integer value of characters to compare
 * Post-condition: The two strings are compared, up to n characters
 *********************************************/
int my_strncmp (const char *s1, const char *s2, int n);

/*********************************************
 * Function: char *my_strcat (char *destination, const char *source);
 * Date Created: April 28th 2018
 * Description: Concatenates the source onto destination
 * Input Parameters: char *destination, const char *source
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Destination has source at the end
 *********************************************/
char *my_strcat (char *destination, const char *source);

/*********************************************
 * Function: char *my_strncat (char *destination, const char *source, int n);
 * Date Created: April 28th 2018
 * Description: Concatenates the n characters of source onto destination
 * Input Parameters: char *destination, const char *source, int n
 * Returns: An integer value
 * Pre-condition: two inputted strings, and an integer value of characters to concatenate
 * Post-condition: Destination has source at the end
 *********************************************/
char *my_strncat (char *destination, const char *source, int n);

/*********************************************
 * Function: char *my_strcpy (char *destination, const char *source);
 * Date Created: April 28th 2018
 * Description: Copies the source into destination
 * Input Parameters: char *destination, const char *source
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Source is copied into destination
 *********************************************/
char *my_strcpy (char *destination, const char *source);

/*********************************************
 * Function: char *my_strncpy (char *destination, const char *source, int n);
 * Date Created: April 28th 2018
 * Description: Copies the n characters of source into destination
 * Input Parameters: char *destination, const char *source, int n
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Source is copied into destination
 *********************************************/
char *my_strncpy (char *destination, const char *source, int n);

/*********************************************
 * Function: char *my_fgets (char *s, int n, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Reads at most one less than the number of characters specified by n, into the array pointed to by s, from the input pointed to by stream.
 * Input Parameters: char *s, int n, FILE *stream
 * Returns: char string
 * Pre-condition:
 * Post-condition: n characters are read into s, or null is returned
 *********************************************/
char *my_fgets (char *s, int n, FILE *stream);

/*********************************************
 * Function: int my_fputc (int c, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Writes c to the output specified by stream. Returns the ascii value of the character or -1 if unsuccessful
 * Input Parameters: int c, FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fputc (int c, FILE *stream);

/*********************************************
 * Function: int my_fputs (const char *s, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Writes s to the output specified by stream. Returns the number of characters written or -1 if unsuccessful
 * Input Parameters: const char *s, FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fputs (const char *s, FILE *stream);

/*********************************************
 * Function: int my_fgetc (FILE *stream);
 * Date Created: April 28th 2018
 * Description: Reads the next character from the input pointed to by stream.
 * Input Parameters: FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fgetc (FILE *stream);

/*********************************************
 * Function: char *my_gets (char *s);
 * Date Created: April 28th 2018
 * Description: Reads characters from stdin into the array pointed to by s until a newline is encountered.
 * Input Parameters: char *s
 * Returns: char string
 * Pre-condition:
 * Post-condition:
 *********************************************/
char *my_gets (char *s);

/*********************************************
 * Function: int my_puts (const char *s);
 * Date Created: April 28th 2018
 * Description: Writes the string pointed to by s to stdout.
 * Input Parameters: const char *s
 * Returns: char string
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_puts (const char *s);

/*********************************************
 * Function: int my_getchar(void);
 * Date Created: April 28th 2018
 * Description: Returns the ascii value of the next character read from stdin.
 * Input Parameters: void
 * Returns: int value
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_getchar (void);

/*********************************************
 * Function: int my_putchar (int c);
 * Date Created: April 28th 2018
 * Description: The function writes character c to stdout. The character c is returned.
 * Input Parameters: int c
 * Returns: int value
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_putchar (int c);

//TEST FUNCTIONS
/*********************************************
 * Function: void test_my_strlen(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strlen(void);

/*********************************************
 * Function: void test_my_strcmp(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcmp(void);

/*********************************************
 * Function: void test_my_strncmp(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncmp(void);

/*********************************************
 * Function: void test_my_strcat(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcat(void);

/*********************************************
 * Function: void test_my_strncat(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncat(void);

/*********************************************
 * Function: void test_my_strcpy(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcpy(void);

/*********************************************
 * Function: void test_my_strncpy(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncpy(void);

/*********************************************
 * Function: void test_my_fgets(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fgets(FILE *stream);

/*********************************************
 * Function: void test_my_fputc(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fputc(FILE *stream);

/*********************************************
 * Function: void test_my_fputs(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fputs(FILE *stream);

/*********************************************
 * Function: void test_my_fgetc(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fgetc(FILE *stream);

/*********************************************
 * Function: void test_my_gets(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_gets(void);

/*********************************************
 * Function: void test_my_puts(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_puts(void);

/*********************************************
 * Function: void test_my_getchar(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_getchar(void);

/*********************************************
 * Function: void test_my_putchar(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_putchar(void);
#endif /* Functions_h */
