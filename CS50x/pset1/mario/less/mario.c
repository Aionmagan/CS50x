#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //created variable 
    int blocks = 0;

    //loop around atleast once
    do
    {
        blocks = get_int("Height between 1 and 8: ");

        if (blocks < 1 || blocks > 8)
        {
            continue;
        }

        for (int i = 0; i < blocks; ++i)
        {
            for (int j = 0; j < blocks; ++j)
            {
                /*add hash when block - i-1*/
                if (j >= (blocks - (i + 1)))
                {
                    printf("#");
                }
                else
                {
                    printf(" ");
                }
            }
            
            /*adding new line every time the j loop
             *finishes
             */
            printf("\n");
        }

    } 
    while (blocks < 1 || blocks > 8);
}
