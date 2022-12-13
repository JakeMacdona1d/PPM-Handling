/*************************
* Thomas Finnegan
* Jake Macdonald
* CPSC 2310 Section 003
* Emails: gtfinne@clemson.edu 
          jpmacdo@clemson.edu
*************************/

#include "ppm.h"
#include "EncodeDecode.h"


int main(int argc, char* argv[])
{ 
    // Check to make sure 3 arguments are passed
    assert(argc == 3);

    // Create file pointer for input file in read mode
    FILE* inFile = fopen(argv[1], "rb");

    // Create file pointer for output file in write mode
    FILE* outFile = fopen(argv[2], "wb");

    // Check that in opened correctly
    assert(inFile != NULL);

    // Check that out opened correctly
    assert(outFile != NULL);

    // create image and read it
    Image *image;
    image = readImage(inFile, readHeader(inFile));



    encode(image);
    printf("\n%s\n", decode(image));

// The next point is the color of the mature caterpillars, some of which are brown. This probably makes the caterpillar even more conspicuous among the green leaves than would otherwise be the case. Let us see, then, whether the habits of the    
// write image out
    writeImage(outFile, image);


    // Close in

    // fclose(inFile);

    // Close out

    // fclose(outFile);



    return 0;
}