/********************************************************************************************

    Reads the hex values of a given file and recovers any JPEG images found within.

*********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    //
    if (argc != 2)
    {
        fprintf(stderr, "Specify the name of the file you want to recover from.\n");
        return 1;
    }

    //file to be opened will be called rfile
    char *rfile = argv[1];

    FILE *inptr = fopen(rfile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Cannot read file.\n");
        return 2;
    }

    //declare whether file is found or not
    int found = 0;

    //create buffer
    unsigned char buffer[512];

    //file counter
    int count = 0;

    //jpegs will be stored here
    FILE *img = NULL;

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        //check for JPEG header
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            //you found a JPEG!
            found = 1;

            //close previous image if exists
            if (count > 0)
            {
                fclose(img);
            }
            // create image and name
            char filename[8];
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;

            if (img == NULL)
            {
                fclose(img);
                fprintf(stderr, "Could not create image.\n");
                return 3;
            }

            //write each block of 512 bytes to new JPEG file
            fwrite(buffer, 512, 1, img);
        }
    else if (found == 1)
        {
            //continue to write into it
            fwrite(buffer, 512, 1, img);
        }
    }
    //close files
    fclose(inptr);
    //all done!
    return 0;
}