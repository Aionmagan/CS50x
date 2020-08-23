#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    /*
     *coins is the return int
     *centadded is for the evaluation
     */
    int coins = 0;
    float money = 0;
    float centAdded = 0;

    /*cents are a const float to use for adding
     *this way i don't have to worry about float imprecision
     */
    const float cents[4] = 
    {
        0.25f, 
        0.10f, 
        0.05f,
        0.01f
    };

    do
    {
        money = get_float("how much owd: ");

        //makes sure to continue loop 
        //to the next iteration if negative value
        if (money < 0.0f)
        {
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            /*this float is to add coins*/
            for (; ; ++coins)
            {
                //if less add if more subtract and break
                //if equal break
                if (centAdded < money)
                {
                    centAdded += cents[i];
                }
                else if (centAdded > money)
                {
                    centAdded -= cents[i];
                    coins --;
                    break;
                }
                else //if centAdded equal to money
                {
                    break;
                }

            }
        }
    }
    while (money < 0.00f);

    //output how many coins
    printf("%i\n", coins);
}
