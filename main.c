/*********************************************************
 *  Paul Valdez
 *  CPTS121 Spring 2018: Lab Section 13; BONUS ASSIGNMENT
 *  April 28th 2018
 *  Description: This Program is a copy of the string.h library, designed by me. It also tests each method for working.
 *  Created by Paul Valdez on 4/25/18.
 *
 **********************************************************/

#include "Functions.h"


int main(void) {
    FILE *infile = NULL, *outfile = NULL;
    //Opens the files to write and read from
    infile = fopen("/Users/paul/Desktop/Spring Semester CS Projects/Bonus Project/Bonus Project/input.txt", "r");
    outfile = fopen("/Users/paul/Desktop/Spring Semester CS Projects/Bonus Project/Bonus Project/output.txt", "w");
    
    //Calls the testing functions
    test_my_strlen();
    test_my_strcpy();
    test_my_strncpy();
    test_my_strcat();
    test_my_strncat();
    test_my_strcmp();
    test_my_strncmp();
    test_my_fgetc(infile);
    test_my_fgets(infile);
    test_my_fputc(outfile);
    test_my_fputs(outfile);
    test_my_gets();
    test_my_puts();
    test_my_putchar();
    test_my_getchar();
    
    //Closes the files
    fclose(infile);
    fclose(outfile);
    return 0;
}
