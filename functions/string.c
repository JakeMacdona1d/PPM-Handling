/*************************
* Thomas Finnegan
* Jake Macdonald
* CPSC 2310 Section 003
* Emails: gtfinne@clemson.edu 
          jpmacdo@clemson.edu
*************************/

#include "../headers/string.h"

void resizeString(String *text) {
    text->max *= 2;
    text->text = realloc(text->text, text->max);
}

char appendString(String *text, char input) {
    if ((text->size + 2) > text->max) 
        resizeString(text);
    text->text[text->size++] = input;
    return input;
}

void concatString(String *text, char *input) {
    for (int i = 0; strlen(input) > i; i++) 
        appendString(text,input[i]);    
}

char *getString(String *text) {
    char *out = calloc(text->size, sizeof(char));

    for (int i = 0; text->size > i; i++) 
        out[i] = text->text[i];
    
    return out; 
}
 
char getStringChar(String *text, int pos) {
    return text->text[pos];
}

void setString(String *text, char *input) {
    free(text->text);

    INIT_STRING(new);

    *text = new;

    for (int i = 0; strlen(input) > i; i++)
        appendString(text, input[i]);

}


