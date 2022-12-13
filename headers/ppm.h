#ifndef _PPM_H_
#define _PPM_H_

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// struct to store ppm header information
typedef struct HeaderInfo {
    char ppmType[2];
    int width;
    int height;
    int maxVal;
} HeaderInfo;

// struct to store pixel information
typedef struct Pixel {
    unsigned short red, green, blue;
} Pixel;

// struct for each image
typedef struct Image {
    Pixel **pixels;
    HeaderInfo head;
} Image;


/*
* Parameters: FILE* - file pointer to input file
* Return:     headerInfo - instance of headerInfo
* This function reads the header information of the input ppm file
* and returns an instance of headerInfo.
*/
HeaderInfo readHeader(FILE* fp); 

/*
* Parameters: FILE* - file pointer to input file
*             HeaderInfo - instance of HeaderInfo
* Return:     Image - instance of Image
* This function reads the Image given and stores the header.
*/
Image *readImage(FILE *fp, HeaderInfo head);

/*
* Parameters: FILE* - file pointer to input file
*             Image - instance of Image
* Return:     void - none
* This function writes the Image with header to the
* output ppm.
*/
void writeImage(FILE *fp, Image *img);


/*
* Parameters: Image* - pointer to input image
* Return:     void - none
* Frees allocated data for instance of Image
*/
void freeImage(Image* img);

#endif