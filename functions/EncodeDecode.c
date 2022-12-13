#include "../headers/EncodeDecode.h"
#include "../headers/string.h"


int Pow(int b, int e) {
    if (e == 0) return 1;
    int output = b;

    for (int i = 0; e - 1 > i; i++) 
        output *= b;
    
    return output;
}

char *decode(Image *img) {
    INIT_STRING(text);
    int pos = 0;

    short value, c;
    while (1) {
        value = 0;
        // This gets value at each color channel
        for (int i = 0; 9 > i; i++) {            
            c = *(&(img->pixels[((pos + i) / 3) / img->head.width]
                [((pos + i) / 3) % img->head.width].red) + (i % 3)) % 10;
            if (c != 0) {
                value += (Pow(2, 9 - i -1));
                if (c > 1 ) value += 252;
            }
        }
        pos += 9;
        if (value > 251) break;
       appendString(&text, (char)(value));
    }

    return getString(&text);
}

char *chartobin (char c)
{
    int size = 8;

     char *bin = malloc(sizeof(char) * size);
     char curchar;

    for (int i = size - 1; i >= 0; i--)
    {
        // use of bitewise operator to convert to binary
        curchar = (char)(((c & (1 << i)) ? '1' : '0'));
        strncat(bin, &curchar, 1);
    }

    return bin;
}

void encode (Image *img)
{
    int choice = 0;

    INIT_STRING(input);

    // ask user for their choice
    printf("Please enter either 1 or 2 for the following options: \n");
    printf("1. Use a provided message to encode\n");
    printf("2. Enter your own message to encode\n");
    
    scanf("%d", &choice);

    // verify they made a valid choice
    while (choice != 1 && choice != 2)
    {
        printf("Please enter 1 or 2\n");
        choice = getchar();
    }

    // get userInput based on their choice
    if (choice == 1)
    {
        setString(&input, "beans");
    }
    else
    {
        char val = 0;
        char set = 0;
        printf("Please enter your message: ");
        while (!set) 
            while((val = getchar()) != 10) { 
                set = 1;
                appendString(&input,val);
            }
    }

    INIT_STRING(bin);

    // concatenate all binary characters together
    for (int i = 0; i < input.size * 3; i++)
    {
        concatString(&bin, chartobin(getStringChar(&input,i)));
    }

    // find length of entire binary

    // use j variable to see if it is rgb
    int j = 0;

   // go down one row if row is filled
        // int w = 0;

    // main for loop that edits pixels
    for (int i = 0; i < ((input.size) * 3); i++)
    {


        // if (j/3 > img->head.width && !w)
        if (i > img->head.width)
        {
            // w += 1;
        }

        // check if on first red value
        if (i % 3 == 0)
        {
            // if so, set to 0
            img->pixels[i / img->head.width][i % img->head.width].red = (img->pixels[i / img->head.width][i % img->head.width].red / 10) * 10;
        }
        else
        {
            // 1 denotes the red value
            if (getStringChar(&bin, j) == '1')
            {
                img->pixels[i / img->head.width][i % img->head.width].red = (img->pixels[i / img->head.width][i % img->head.width].red / 10) * 10;
                img->pixels[i / img->head.width][i % img->head.width].red += 1;

                j += 1;
            }
            else
            {
                img->pixels[i / img->head.width][i % img->head.width].red = (img->pixels[i / img->head.width][i % img->head.width].red / 10) * 10;

                j += 1;
            }
        }

        // green
        if (getStringChar(&bin, j) == '1')
        {
            img->pixels[i / img->head.width][i % img->head.width].green = (img->pixels[i / img->head.width][i % img->head.width].green / 10) * 10;
            img->pixels[i / img->head.width][i % img->head.width].green += 1;

            j += 1;
        }
        else
        {
            img->pixels[i / img->head.width][i % img->head.width].green = (img->pixels[i / img->head.width][i % img->head.width].green / 10) * 10;

            j += 1;
        }

        // blue
       
        if (getStringChar(&bin, j) == '1')
        {
            img->pixels[i / img->head.width][i % img->head.width].blue = (img->pixels[i / img->head.width][i % img->head.width].blue / 10) * 10;
            img->pixels[i / img->head.width][i % img->head.width].blue += 1;

            j += 1;
        }
        else
        {
            img->pixels[i / img->head.width][i % img->head.width].blue = (img->pixels[i / img->head.width][i % img->head.width].blue / 10) * 10;

            j += 1;
        }

    }

    // free memory
    free(bin.text);
    free(input.text);
}


