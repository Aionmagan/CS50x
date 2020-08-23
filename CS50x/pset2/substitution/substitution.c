#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

char *subtitution_cypher(const char *s, const char *key);
bool check_key_valid(const char *key);

int main(int argc, char **argv)
{

    //checking if theres more then
    //one argument
    if (argc < 2 || argc > 2 || (argc == 2 && !check_key_valid(argv[1])))
    {
        printf("Usage: ./subtitution key\n");
        return 1;
    }

    //expecting a 26 char long key
    const char *key = argv[1];

    char *s = get_string("Text: ");

    char *encrypt = subtitution_cypher(s, key);

    printf("ciphertext: %s\n", encrypt);
    return 0;
}

char *subtitution_cypher(const char *s, const char *key)
{
    //static to it sends a proper point
    static char str[sizeof(s)];

    //subtitution sequence
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
            {
                str[i] = toupper(key[(int)s[i] - 65]);
            }
            else
            {
                str[i] = tolower(key[(int)s[i] - 97]);
            }
        }
        else
        {
            str[i] = s[i];
        }
    }

    return str;
}

bool check_key_valid(const char *key)
{
    char lch[27];
    int length = 0;

    //getting length of key
    for (length = 0; key[length] != '\0'; ++length);

    if (length != 26)
    {
        return false;
    }

    //key verification
    for (int i = 0; i < length; ++i)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }
        else
        {
            lch[i] = toupper(key[i]);

            //checking for duplicates
            for (int j = 0; j < i; ++j)
            {
                if (lch[j] == toupper(key[i]))
                {
                    return false;
                }
            }
        }

    }

    return true;
}