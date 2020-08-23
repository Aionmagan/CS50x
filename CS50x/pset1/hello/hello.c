#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*this is a comment just to get a better style50 :)*/

    //another comment just for style50 points :)

    /*here we can use a char * (i prefer a char array) to collect a string input*/
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
}
