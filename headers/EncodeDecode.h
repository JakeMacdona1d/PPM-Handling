#ifndef _ENCODEDECODE_H_
#define _ENCODEDECODE_H_

#include "ppm.h"

char *chartobin (char c);

void encode(Image *img);

int Pow(int b, int e);

char *decode(Image *img);

#endif