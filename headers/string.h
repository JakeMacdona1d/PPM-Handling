/*************************
* Thomas Finnegan
* Jake Macdonald
* CPSC 2310 Section 003
* Emails: gtfinne@clemson.edu 
          jpmacdo@clemson.edu
*************************/

#ifndef _STRING_H_
#define _STRING_H_
#include "ppm.h"

typedef struct String {
    char *text;
    int size;
    int max;
} String;

#define INIT_STRING(X) String X = {.text = calloc(sizeof(char), 2), .size = 0, .max = 2}

char appendString(String *text, char input);

void resizeString(String *text);

char *getString(String *text);

void concatString(String *text, char *input);


char getStringChar(String *text, int pos);

void setString(String *string, char *input);

#endif