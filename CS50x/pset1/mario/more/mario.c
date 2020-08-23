#include <cs50.h>
#include <stdio.h>

int main(void)
{
    /*variables for storing values*/
    int blocks = 0;
    int half = 0;

    do
    {
        blocks = get_int("Height between 1 and 8: ");
        
        //if value not with in numbers continue loop
        if (blocks < 1 || blocks > 8)
        {
            continue;
        }

        //half of blocks * 2
        half = blocks;
        for (int i = 0; i < blocks; ++i)
        {
            for (int j = 0; j < blocks + (i + 3); ++j)
            {
                //a long if statement because i'm trying 
                //to keep it to the course
                if (j == half || j == half + 1 || j >= half + (i + 3) || j <= half - (i + 2))
                {
                    printf(" ");
                }
                else
                {
                    printf("#");
                }
            }

            printf("\n");
        }
    }
    while (blocks < 1 || blocks > 8);
}
