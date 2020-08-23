#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long cc = -1;
    while (cc < 0)
    {
        cc = get_long("Credit Card Please: ");

        /*getting length of long*/
        int length = 1;
        for (long i = 1; (10 * i) < cc; i *= 10, ++length);
        
        /*creating an array to carry each digit
         *putting each digit in reverse from last digit to first
         */
        int digits[length];
        long j = 1;
        for (int i = 0 ; i < length; ++i)
        {
            digits[i] = (cc / j) % 10;
            j *= 10;
        }

        //visa is 4 hence the if 
        //for anything else it will be two digits collected
        int firstCCdigit = (digits[length - 1] * 10) + digits[length - 2];
        if (digits[length - 1] == 4) 
        {
            if (length >= 13)
            {
                firstCCdigit = 4;
            }
            else
            {
                firstCCdigit = 0;
            }
        }
        /*start Luhn's Algorithm */
        for (int i = 0; i < length; ++i)
        {
            if (i % 2 == 1)
            {
                digits[i] *= 2;

                if (digits[i] > 9)
                {
                    //adding digits that have two digits in one
                    //index (00)
                    digits[i] = (digits[i] % 10) + (digits[i] / 10);
                }
            }
        }

        /*adding the remainding numbers here*/
        for (int i = length - 2; i >= 0; --i)
        { 
            digits[length - 1] += digits[i];
        }
        /*if the last outcome has 0 in it then 
         *then we are good
         */
        if ((digits[length - 1] % 10) == 0)
        {
            /*prefered doing it this way
             *so i didn't have four different printf
             */
            string prnt = "";
            switch (firstCCdigit)
            {
                case 34:
                case 37:
                    prnt = "AMEX";
                    break;
                case 4 : 
                    prnt = "VISA";
                    break;
                case 51:
                case 52:
                case 53:
                case 54:
                case 55: 
                    prnt = "MASTERCARD";
                    break;
                default:
                    prnt = "INVALID";
                    break;
            }

            printf("%s\n", prnt);
        }
        else
        {
            printf("INVALID\n");
        }

    }
}
