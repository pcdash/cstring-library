/*********************************************************
 *  Paul Valdez
 *  CPTS121 Spring 2018: Lab Section 13; BONUS ASSIGNMENT
 *  April 28th 2018
 *  Description: This Program is a copy of the string.h library, designed by me. It also tests each method for working.
 *  Created by Paul Valdez on 4/25/18.
 *
 **********************************************************/

#include "mystring.h"

/*********************************************
 * Function: int my_strlen (const char *s);
 * Date Created: April 28th 2018
 * Description: Finds the length of an inputted string, without counting the null character.
 * Input Parameters: const char *s
 * Returns: An integer value
 * Pre-condition: An inputted string
 * Post-condition: The length of the string is found.
 *********************************************/
int my_strlen (const char *s){
    //Initialize the length
    int length = 0;
    //Run so long as a null character is not hit
    while (*(s + length) != '\0'){
        //Updates the length
        length++;
    }
    return length;
}

/*********************************************
 * Function: int my_strncmp (const char *s1, const char *s2, int n);
 * Date Created: April 28th 2018
 * Description: Compares the two strings n characters, returning -1 if s1 is greater then s2, 0 if equal, and 1 otherwise
 * Input Parameters: const char *s1, const char *s2, int n
 * Returns: An integer value
 * Pre-condition: two inputted strings, and an integer value of characters to compare
 * Post-condition: The two strings are compared, up to n characters
 *********************************************/
int my_strncmp (const char *s1, const char *s2, int n){
    //Initializes the trackers and index
    int cmp = 0, index = 0;
    //Runs while the index count is less than n and neither string hits a null character
    while (index <= n && (*(s1 + index + 1) != '\0' || *(s2 + index + 1) != '\0') && cmp == 0){
        if (*(s1 + index) > *(s2 + index)){
            //Updates the compare tracker
            cmp = 1;
        } else if (*(s1 + index) < *(s2 + index)){
            cmp = -1;
        }
        //Increments index
        index++;
    }
    return cmp;
}

/*********************************************
 * Function: int my_strcmp (const char *s1, const char *s2);
 * Date Created: April 28th 2018
 * Description: Compares the two strings, returning -1 if s1 is greater then s2, 0 if equal, and 1 otherwise
 * Input Parameters: const char *s1, const char *s2
 * Returns: An integer value
 * Pre-condition: two inputted strings
 * Post-condition: The two strings are compared
 *********************************************/
int my_strcmp (const char *s1, const char *s2){
    //Initializes the trackers and index
    int cmp = 0, index = 0;
    //Runs while one string is not greater than the other and the end of the strings has not been reached
    while (cmp == 0 && (*(s1 + index + 1) != '\0' || *(s2 + index + 1) != '\0')){
        //Checks if one is greater than the other
        if (*(s1 + index) > *(s2 + index)){
            cmp = 1;
        } else if (*(s1 + index) < *(s2 + index)){
            cmp = -1;
        }
        //Increments the index
        index++;
    }
    return cmp;
}

/*********************************************
 * Function: char *my_strcat (char *destination, const char *source);
 * Date Created: April 28th 2018
 * Description: Concatenates the source onto destination
 * Input Parameters: char *destination, const char *source
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Destination has source at the end
 *********************************************/
char *my_strcat(char *destination, const char *source){
    //Checks to make sure that the end of destination has been reached
    if (*destination != '\0'  && *source != '\0'){
        return my_strcat((destination + 1), source) - 1;
    }
    else if (*source != '\0' && *destination == '\0'){
        //Sets the source onto the destination and puts a null space at the end of destination
        *destination = *source;
        *(destination + 1) = '\0';
        //Calls the function again with the next position
        return my_strcat(destination + 1, source + 1) - 1;
    }
    
    else{
        //If the source is ended, returns destination
        return destination;
    }
}

/*********************************************
 * Function: char *my_strncat (char *destination, const char *source, int n);
 * Date Created: April 28th 2018
 * Description: Concatenates the n characters of source onto destination
 * Input Parameters: char *destination, const char *source, int n
 * Returns: An integer value
 * Pre-condition: two inputted strings, and an integer value of characters to concatenate
 * Post-condition: Destination has source at the end
 *********************************************/
char *my_strncat(char *destination, const char *source, int n){
    //Checks to make sure that the end of destination has been reached
    if (*destination != '\0'  && *source != '\0'){
        return my_strncat((destination + 1), source, n) - 1;
    }
    else if (*source != '\0' && *destination == '\0' && n != 0){
        //Sets the source onto the destination and puts a null space at the end of destination
        *destination = *source;
        *(destination + 1) = '\0';
        //Calls the function again with the next position
        return my_strncat(destination + 1, source + 1, n - 1) - 1;
    }
    
    else{
        //If the source is ended, returns destination
        return destination;
    }
}

/*********************************************
 * Function: char *my_strcpy (char *destination, const char *source);
 * Date Created: April 28th 2018
 * Description: Copies the source into destination
 * Input Parameters: char *destination, const char *source
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Source is copied into destination
 *********************************************/
char *my_strcpy (char *destination, const char *source){
    //Checks if the source sent is empty, to which it sets destination to empty
    if (*source == '\0'){
        *destination = '\0';
    }
    //Runs through source calling itself recursively
    if (*source != '\0'){
        //Sets each position in destination to source
        *destination = *source;
        *(destination + 1) = '\0';
        //Recursively runs through the string, while using pointer arithmetic to keep track of the front
        return my_strcpy(destination + 1, source + 1) - 1;
    } else{
        return destination;
    }
}

/*********************************************
 * Function: char *my_strncpy (char *destination, const char *source, int n);
 * Date Created: April 28th 2018
 * Description: Copies the n characters of source into destination
 * Input Parameters: char *destination, const char *source, int n
 * Returns: char string
 * Pre-condition: two inputted strings
 * Post-condition: Source is copied into destination
 *********************************************/
char *my_strncpy (char *destination, const char *source, int n){
    int index = 0, index2 = 0;
    //Runs through and sets the destination to empty if the source is empty
    if (*source == '\0'){
        while (index2 < n){
            *(destination + index2) = '\0';
            index2++;
        }
    }
    //Runs through and sets the destination to source so long as the index is less than n characters
    while (*(source + index) != '\0' && index < n){
        *(destination + index) = *(source + index);
        //Updates the index
        index++;
    }
    return destination;
}

/*********************************************
 * Function: char *my_fgets (char *s, int n, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Reads at most one less than the number of characters specified by n, into the array pointed to by s, from the input pointed to by stream.
 * Input Parameters: char *s, int n, FILE *stream
 * Returns: char string
 * Pre-condition:
 * Post-condition: n characters are read into s, or null is returned
 *********************************************/
char *my_fgets (char *s, int n, FILE *stream){
    //Initializes the variables
    char temp = '\0';
    int index = 0, success = 0;
    //Runs assuming the stream is not null, and the end of the file has not been reached, and a new line has not been encountered
    while (stream != NULL && index < n && !feof(stream) && temp != '\n'){
        //Sets success to the return character
        success = fscanf(stream, "%c", &temp);
        if (success)
        {
            //Updates the string
            *(s + index) = temp;
            //Inserts a null character to the end of the array
            *(s + index + 1) = '\0';
        } else
        {
            //If it wasnt successful in reading from the file, a null pointer is returned
            return NULL;
        }
        index++;
    }
    //If the stream was null, or it was at the end of the file, a null character is returned
    if (success){
        return s;
    } else{
        return NULL;
    }
}

/*********************************************
 * Function: int my_fputc (int c, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Writes c to the output specified by stream. Returns the ascii value of the character or -1 if unsuccessful
 * Input Parameters: int c, FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fputc (int c, FILE *stream){
    //If unsuccessful to print to the stream, the function returns -1
    if (stream == NULL || fprintf(stream, "%c",(char) c) < 0){
        return MY_EOF;
    } else{
        return c;
    }
}

/*********************************************
 * Function: int my_fputs (const char *s, FILE *stream);
 * Date Created: April 28th 2018
 * Description: Writes s to the output specified by stream. Returns the number of characters written or -1 if unsuccessful
 * Input Parameters: const char *s, FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fputs (const char *s, FILE *stream){
    //If unsuccessful to print to the string, the function returns -1
    if (stream == NULL || fprintf(stream, "%s", s) < 0){
        return MY_EOF;
    }
    return my_strlen(s);
}

/*********************************************
 * Function: int my_fgetc (FILE *stream);
 * Date Created: April 28th 2018
 * Description: Reads the next character from the input pointed to by stream.
 * Input Parameters: FILE *stream
 * Returns: int
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_fgetc (FILE *stream){
    char temp = '\0';
    //Returns MY_EOF if the stream is null, or the end of the file has been reached, or its unsuccessful to read from the stream.
    if (stream == NULL || feof(stream) || fscanf(stream, "%c", &temp) < 0)
    {
        return MY_EOF;
    }
    else
    {
        //Otherwise returns the ascii value of c
        return (int) temp;
    }
}

/*********************************************
 * Function: char *my_gets (char *s);
 * Date Created: April 28th 2018
 * Description: Reads characters from stdin into the array pointed to by s until a newline is encountered.
 * Input Parameters: char *s
 * Returns: char string
 * Pre-condition:
 * Post-condition:
 *********************************************/
char *my_gets (char *s){
    char temp = '\0';
    int index = 0;
    //Scans the first character in to temp
    scanf("%c", &temp);
    //Runs while temp is not a new line character
    while (temp != '\n'){
        *(s + index) = temp;
        scanf("%c", &temp);
        index++;
    }
    //Puts a null character at the end of the string
    *(s + index) = '\0';
    return s;
}

/*********************************************
 * Function: int my_puts (const char *s);
 * Date Created: April 28th 2018
 * Description: Writes the string pointed to by s to stdout.
 * Input Parameters: const char *s
 * Returns: char string
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_puts (const char *s){
    int index = 0;
    //Runs through the string and write it to stdout
    while (*(s + index) != '\0'){
        printf("%c", *(s + index));
        index++;
    }
    //Appends a new line to stdout
    printf("\n");
    return index;
}

/*********************************************
 * Function: int my_getchar(void);
 * Date Created: April 28th 2018
 * Description: Returns the ascii value of the next character read from stdin.
 * Input Parameters: void
 * Returns: int value
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_getchar (void){
    char temp = '\0';
    //Reads in a character from stdin
    scanf(" %c", &temp);
    //Returns the ascii value
    return (int) temp;
}

/*********************************************
 * Function: int my_putchar (int c);
 * Date Created: April 28th 2018
 * Description: The function writes character c to stdout. The character c is returned.
 * Input Parameters: int c
 * Returns: int value
 * Pre-condition:
 * Post-condition:
 *********************************************/
int my_putchar (int c){
    //Writes the character c to stdout
    printf("%c", c);
    //Returns the ascii value of c
    return c;
}

/**********************************
 ********** TEST STRINGS **********
 */

/*********************************************
 * Function: void test_my_strlen(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strlen(void){
    printf("TEST MY_STRLEN:\n");
    //initializes the strings
    char *str1 = "washington";
    char *str2 = "state";
    char *str3 = "r";
    char *str4 = "\0";
    //Tests the function
    printf("STRING 1, SHOULD BE 10: LENGTH %d\n", my_strlen(str1));
    printf("STRING 2, SHOULD BE 5: LENGTH %d\n", my_strlen(str2));
    printf("STRING 3, SHOULD BE 1: LENGTH %d\n", my_strlen(str3));
    printf("STRING 4, SHOULD BE 0: LENGTH %d\n", my_strlen(str4));
}

/*********************************************
 * Function: void test_my_strcmp(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcmp(void){
    printf("TEST MY_STRCMP:\n");
    //Initializes the strings
    char *str1 = "xyz";
    char *str2 = "abc";
    //Tests the function
    printf("SHOULD RETURN 0: RETURNS %d\n", my_strcmp(str1, str1));
    printf("SHOULD RETURN 1: RETURNS %d\n", my_strcmp(str1, str2));
    printf("SHOULD RETURN -1: RETURNS %d\n", my_strcmp(str2, str1));
}

/*********************************************
 * Function: void test_my_strncmp(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncmp(void){
    printf("TEST MY_STRNCMP:\n");
    //Initializes the strings
    char *str1 = "washington";
    char *str2 = "water";
    //Tests the function
    printf("SHOULD RETURN 0: RETURNS %d\n", my_strncmp(str1, str1, 5));
    printf("SHOULD RETURN -1: RETURNS %d\n", my_strncmp(str1, str2, 2));
    printf("SHOULD RETURN 1: RETURNS %d\n", my_strncmp(str2, str1, 3));
    printf("SHOULD RETURN -1: RETURNS %d\n", my_strncmp(str1, str2, 7));
}

/*********************************************
 * Function: void test_my_strcat(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcat(void){
    printf("TEST MY_STRCAT:\n");
    //Initializes the string
    char str1[50] = "Washington ";
    char str2[50] = "State ";
    char str3[50] = "University";
    //Tests the function
    printf("SHOULD RETURN 'Washington State': RETURNS %s\n", my_strcat(str1, str2));
    printf("SHOULD RETURN 'Washington State University': RETURNS %s\n", my_strcat(str1, str3));
}

/*********************************************
 * Function: void test_my_strncat(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncat(void){
    printf("TEST MY_STRNCAT:\n");
    //Initializes strings
    char str1[50] = "Washington ";
    char str2[50] = "State ";
    char str3[50] = "University";
    //Tests the function
    printf("SHOULD RETURN 'Washington State': RETURNS %s\n", my_strncat(str1, str2, 6));
    printf("SHOULD RETURN 'Washington State Univ': RETURNS %s\n", my_strncat(str1, str3, 4));
    printf("SHOULD RETURN 'State ': RETURNS %s\n", my_strncat(str2, str3, 0));
}

/*********************************************
 * Function: void test_my_strcpy(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strcpy(void){
    printf("TEST MY_STRCPY:\n");
    //Initializes Strings
    char str1[50] = {'\0'};
    char str2[50] = "Apple";
    char str3[50] = "State University";
    char str4[50] = "Apple";
    //Tests the function
    my_strcpy(str4, str1);
    my_strcpy(str1, str2);
    my_strcpy(str3, str2);
    printf("COPY 'Apple' INTO AN EMPTY STRING: PRINTS %s\n", str1);
    printf("COPY AN EMPTY STRING TO 'Apple': PRINTS NOTHING %s\n", str4);
    printf("COPY 'Apple' INTO A STRING OF 'State University': PRINTS %s\n", str3);
}

/*********************************************
 * Function: void test_my_strncpy(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_strncpy(void){
    printf("TEST MY_STRNCPY:\n");
    //Initializes strings
    char str1[50] = {'\0'};
    char str2[50] = "Apple";
    char str3[50] = "State University";
    char str4[50] = "Apple";
    //Tests the function
    my_strncpy(str4, str1, 3);
    my_strncpy(str1, str2, 3);
    my_strncpy(str3, str2, 3);
    printf("COPY THREE CHARACTERS OF 'Apple' INTO AN EMPTY STRING: PRINTS %s\n", str1);
    printf("COPY THREE CHARACTERS OF AN EMPTY STRING TO 'Apple': PRINTS NOTHING %s\n", str4);
    printf("COPY THREE CHARACTERS 'Apple' INTO 'State University', SHOULD BE APPTE UNIVERSITY: PRINTS %s\n", str3);
}

/*********************************************
 * Function: void test_my_fgets(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fgets(FILE *stream){
    //Initializes the Null function
    FILE *testfile = NULL;
    printf("TEST MY_FGETS:\n");
    char str1[50] = {'\0'}, str2[50] = {'\0'};
    int num = 15;
    //Tests the function with getting more than one string out as well as with a null file
    printf("SHOULD PRINT 'Washington' with a new line character afterward: PRINTS %s\n", my_fgets(str1, num, stream));
    printf("SHOULD PRINT 'State' with a new line character afterward: PRINTS %s\n", my_fgets(str2, num, stream));
    printf("SHOULD PRINT 'University' with a new line character afterward: PRINTS %s\n", my_fgets(str2, num, stream));
    printf("SHOULD PRINT 'GO COUGS' with a new line character afterward: PRINTS %s\n", my_fgets(str2, num, stream));
    printf("SHOULD PRINT '(null)': PRINTS %s\n", my_fgets(str1, num, testfile));
}

/*********************************************
 * Function: void test_my_fputc(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fputc(FILE *stream){
    FILE *testfile = NULL;
    printf("TEST MY_FPUTC:\n");
    char char_name = 'W', char_name2 = 'S', char_name3 = 'U';
    //Tests the function with a NULL file and a full file, as well as testing putting more than one character in
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) char_name, my_fputc(char_name, stream));
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) char_name2, my_fputc(char_name2, stream));
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) char_name3, my_fputc(char_name3, stream));
    printf("SHOULD PRINT '-1': PRINTS %d\n", my_fputc(char_name, testfile));
}
////////////////////////////////SEE IF IT CAN READ MORE THAN ONE THING FROM THE STREAM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*********************************************
 * Function: void test_my_fputs(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fputs(FILE *stream){
    FILE *testfile = NULL;
    printf("TEST MY_FPUTS:\n");
    char *str1 = "Washington ", *str2 = "State ";
    //Tests the function with a NULL and full file, as well as testing putting more than one string in
    printf("SHOULD PRINT '%d': PRINTS %d\n", my_strlen(str1), my_fputs(str1, stream));
    printf("SHOULD PRINT '%d': PRINTS %d\n", my_strlen(str2), my_fputs(str2, stream));
    printf("SHOULD PRINT '-1': PRINTS %d\n", my_fputs(str1, testfile));
}

/*********************************************
 * Function: void test_my_fgetc(FILE *stream);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_fgetc(FILE *stream){
    FILE *testfile = NULL;
    printf("TEST MY_FGETC:\n");
    //Tests the function with a NULL file and an initialized file, as well as testing for more than one output
    printf("SHOULD PRINT '%c': PRINTS %c\n",'W', my_fgetc(stream));
    printf("SHOULD PRINT '%c': PRINTS %c\n",'a', my_fgetc(stream));
    printf("SHOULD PRINT '%c': PRINTS %c\n",'s', my_fgetc(stream));
    printf("SHOULD PRINT '%c': PRINTS %c\n",'h', my_fgetc(stream));
    printf("SHOULD PRINT 1 IF IT GETS A NEW LINE: PRINTS %d\n",'\n' == my_fgetc(stream));
    printf("SHOULD PRINT '-1': PRINTS %d\n", my_fgetc(testfile));
}

/*********************************************
 * Function: void test_my_gets(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_gets(void){
    printf("TEST MY_GETS:\n");
    char str[200] = { '\0' };
    //Tests the function with user input
    printf("Enter a sentence of 200 characters or less. Press Enter to stop: ");
    printf("PRINTS %s\n", my_gets(str));
}

/*********************************************
 * Function: void test_my_puts(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_puts(void){
    printf("TEST MY_PUTS:\n");
    //Tests the function with a string
    char *str = "Washington State University";
    printf("SHOULD PRINT '%d': PRINTS %d\n", my_strlen("Washington State University"), my_puts(str));
}

/*********************************************
 * Function: void test_my_getchar(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_getchar(void){
    printf("TEST MY_GETCHAR:\n");
    //Tests the function with three characters
    printf("Enter 'A': ");
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) 'A', my_getchar());
    printf("Enter 'a': ");
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) 'a', my_getchar());
    printf("Enter 'R': ");
    printf("SHOULD PRINT '%d': PRINTS %d\n", (int) 'R', my_getchar());
}

/*********************************************
 * Function: void test_my_putchar(void);
 * Date Created: April 28th 2018
 * Description: Tests the function.
 * Input Parameters: void
 * Returns: void
 * Pre-condition:
 * Post-condition:
 *********************************************/
void test_my_putchar(void){
    printf("TEST MY_PUTCHAR:\n");
    //Tests the function with three characters
    printf(" SHOULD PRINT '%c' and return '%d': PRINTS %d\n", 'A', (int) 'A', my_putchar('A'));
    printf(" SHOULD PRINT '%c' and return '%d': PRINTS %d\n", 'c', (int) 'c', my_putchar('c'));
    printf(" SHOULD PRINT '%c' and return '%d': PRINTS %d\n", '0', (int) '0', my_putchar('0'));
}
