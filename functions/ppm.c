/*************************
* Thomas Finnegan
* Jake Macdonald
* CPSC 2310 Section 003
* Emails: gtfinne@clemson.edu 
          jpmacdo@clemson.edu
*************************/

#include "ppm.h"


int headVal(int *i, char *arr)
{
  int end = 0;
  char *cValue =calloc(5,sizeof(char));

  while (arr[*i] == ' ' || arr[*i] == '\n') (*i)++;
  for (*i = *i; 1; (*i)++) {

    if (arr[*i] == '\n' || arr[*i] == ' ') {

      return atoi(cValue);
    }

    cValue[end++] = arr[*i];
  }
}

HeaderInfo readHeader(FILE* fp)
{
    HeaderInfo head;
    char *arr = malloc(500 * sizeof(char));

    int inComment = 0;
    char x = 0;
    int size = 0;
    int pos = 0;
    int lastHead = 0;

    while (x != EOF) {
        pos++;
        x = fgetc(fp);
        if (x == '#')
            inComment = 1;
        
        if ((x == '\n' || x == ' ') && 1000 > size) { 
            lastHead = pos;
        }

        if (inComment && x == '\n') {
            inComment = 0;
            arr[size++] = ' ';
            continue;
        }

        if (!inComment) {
            arr[size++] = x;
        }
    }

    int i = 0;
    char type[2];
    short tsize = 0;

    while (arr[i] == '\n' || arr[i++] == ' ');
    for (i -= 1; 1; i++) {
    if (arr[i] == '\n' || arr[i] == ' ') {
        printf("%s\n", type);
        break;
    }
    head.ppmType[tsize++] = arr[i];
    }

    head.width = headVal(&i,arr);
    head.height = headVal(&i,arr);
    head.maxVal = headVal(&i,arr);

    fseek(fp,lastHead,SEEK_SET);
    return head;
}

Image *readImage(FILE *fp, HeaderInfo head)
{
    Image *img = malloc(sizeof(Image));
    img->head = head;

    img->pixels = malloc(img->head.height * sizeof(Pixel*));

    for (int i = 0; img->head.height > i; i++) {
        (img->pixels)[i] = malloc(img->head.width * sizeof(Pixel));
        fread(img->pixels[i], sizeof(Pixel) , img->head.width, fp);
    }

    return img;
}

void writeImage(FILE *fp, Image *img)
{
    //image details
    fprintf(fp, "%c%c\n", img->head.ppmType[0], img->head.ppmType[1]);

    //image dimensions
    fprintf(fp, "%d %d\n",img->head.width, img->head.height);

    // rgb value
    fprintf(fp, "%d\n", img->head.maxVal);

    // pixel data
    for (int i = 0; img->head.height > i; i++) {
        fwrite(img->pixels[i], sizeof(Pixel), img->head.width, fp);
    }
}
