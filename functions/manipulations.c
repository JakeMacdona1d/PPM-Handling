#include "EncodeDecode.h"

void changeColorImage(Image *img)
{
    for(int i = 0; i < img->head.height; i++){
        for (int j = 0; j < img->head.width; j++) {
            img->pixels[j][i].red = img->head.maxVal - img->pixels[j][i].red;
            img->pixels[j][i].green = img->head.maxVal - img->pixels[j][i].green;
            img->pixels[j][i].blue = img->head.maxVal - img->pixels[j][i].blue;
        }
    }
}

void resizeImage(Image *input, Image *output) 
{
    int userHeight;
    int userWidth;

    output->head.ppmType[0] = input->head.ppmType[0];
    output->head.ppmType[1] = input->head.ppmType[1];

    output->head.maxVal = input->head.maxVal;

    printf("Please enter desired change in width: ");
    scanf("%d", &userWidth);

    while ((input->head.width + userWidth) < 0)
    {
        printf("Please enter an acceptable change: ");
        scanf("%d", &userWidth);
    }

    output->head.width = input->head.width + userWidth;

    printf("Please enter desired change in height: ");
    scanf("%d", &userHeight);

    while ((input->head.height + userHeight) < 0)
    {
        printf("Please enter an acceptable change: ");
        scanf("%d", &userHeight);
    }

    output->pixels = malloc(output->head.height * sizeof(Pixel*));
    for (int i = 0; output->head.height > i; i++ ) {
        (output->pixels)[i] = malloc(output->head.width * sizeof(Pixel));
    }

    double wRatio = (double)input->head.width / output->head.width;
    double hRatio = (double)input->head.height / output->head.height;

    for (int height = 0; height < output->head.height; height++)
    {
        for (int width = 0; width < output->head.width; width++)
        {
            output->pixels[height][width] = input->pixels[(int)(height * hRatio)][(int)(width * wRatio)];
        }
    }
}