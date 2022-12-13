#include "headers/EncodeDecode.h"
#include "headers/ppm.h"
#include "headers/manipulations.h"

int main(int argc, char* argv[])
{ 
    // Check to make sure 3 arguments are passed
    assert(argc == 5);

    // Create file pointer for input file in read mode
    FILE* inFile = fopen(argv[1], "rb");
    FILE* encodeFile = fopen(argv[2], "wb");
    FILE* resizedFile = fopen(argv[3], "wb");
    FILE* negativeFile = fopen(argv[4], "wb");

    // Check that in opened correctly
    assert(inFile != NULL);
    assert(encodeFile != NULL);
    assert(resizedFile != NULL);
    assert(negativeFile != NULL);

    // create image and read it
    Image *image;
    image = readImage(inFile, readHeader(inFile));
    encode(image);
    printf("\n%s\n", decode(image));
    writeImage(encodeFile, image);

    Image *resized = malloc(sizeof(Image));
    resizeImage(image, resized);
    writeImage(resizedFile, resized);
    freeImage(resized);

    Image *negative = malloc(sizeof(Image));
    changeColorImage(image, negative);
    writeImage(negativeFile, negative);
    freeImage(negative);
    
    freeImage(image);

    // Close in: does not work. Causes a core dump.
    //Requires further investigation
    // fclose(inFile);
    fflush(inFile);
    
    // Close out
    fclose(encodeFile);
    fclose(resizedFile);
    fclose(negativeFile);
    return 0;
}