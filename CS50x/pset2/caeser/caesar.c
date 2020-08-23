#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

char *caesar_cypher(const char *s, const int key);
bool check_str_number(const char *s); /*my own isdigit()*/

int main(int argc, char **argv)
{
    //checking if theres more then
    //one argument
    if (argc < 2 || argc > 2 || (argc == 2 && !check_str_number(argv[1])))
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    const int key = atoi(argv[1]);

    char *s = get_string("Text: ");

    char *encrypt = caesar_cypher(s, key);

    printf("ciphertext: %s\n", encrypt);
    return 0;
}

char *caesar_cypher(const char *s, const int key)
{
    int index = 0;
    static char str[sizeof(s)];

    for (int i = 0; s[i] != '\0'; ++i)
    {
        //adding ACSII value of char to index
        index = (int)s[i];

        //making sure it's a letter
        if (isalpha(s[i]))
        {
            /*yes i completely ignored the c = (p+k)%26
             * formula, just found it easier this way
             */
            for (int j = 0; j < key; ++j)
            {
                ++index;

                //if it's capital
                if (isupper(s[i]))
                {
                    if (index > 90)
                    {
                        index = 65;
                    }
                }
                else
                {
                    //if it's non-capital
                    if (index > 122)
                    {
                        index = 97;
                    }
                }
            }
        }

        str[i] = (char)index;
    }

    return str;
}

/* my own isdigit() function as a small challange*/
bool check_str_number(const char *s)
{
    for (int i = 0; s[i] != '\0'; ++i)
    {
        switch (s[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                continue; /*break;*/
            default:
                return false; /*break;*/
        }

    }

    return true;
}