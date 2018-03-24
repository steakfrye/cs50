#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    //ask user for integer until it is between 0 and 23
    do
    {
        height = get_int("Height: ");
    }
    while (height > 23 || height < 0);
    {
        //create height line by line
        for (int h = 0; h < height; h++)
        {

            //print spaces for each line, subtracting 1 each time
            for (int i = height - 1; i > h; i--)
            {
                printf(" ");
            }

            //print hashtags for each line, starting with 2, and adding 1 each time
            for (int k = 0; k < h + 2; k++)
            {
                printf("#");
            }
            //add lines
            printf("\n");
        }
    }
}