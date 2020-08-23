#include <cs50.h>
#include <stdio.h>
#include <math.h>

float check_sentences(int length, string str);
float check_letter(int length, string str);
bool check_table(char ch, bool is_sentence);

int main(void)
{
    string text = get_string("Text: ");
    
    //getting length of string
    //setting up l and s (L, S)
    int length = 0;
    float l = 0.0f, s = 0.0f;
    
    //length
    for (length = 0; text[length] != '\0'; ++length);
    
    l = check_letter(length, text);
    s = check_sentences(length, text);
    
    float index = ((0.0588 * l) - (0.296 * s) - 15.8);
    
    //making sure that the grade is atlest 1
    index = index < 1 ? 1 : index;
    
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 2)
    {
        printf("Before Grade 1\n");
    }
    else 
    {
        printf("Grade %i\n", (int) round(index));
    }
}

float check_sentences(int length, string str)
{
    /*getting sentence
     *getting words
     *period_check is to make sure double .(U.S.)
     */
    int sentence = 0;
    int words = 1;
    int period_check = -1;
    
    for (int i = 0; i < length; ++ i)
    {
        if (str[i] == ' ')
        {
            ++words;
        }
        else if (check_table(str[i], true))
        {
            /*period_checking here*/
            if (str[i] == '.' && str[i + 2] == '.')
            {
                period_check  = i + 2;
            }
            
            if (period_check < i)
            {
                sentence ++;
            }

        }
    }
    return ((float)sentence / words * 100);
}

float check_letter(int length, string str)
{
    //letters and words
    int letters = 0;
    int words = 1;
    
    //adding to letters and word
    for (int i = 0; i < length; ++ i)
    {
        if (str[i] == ' ')
        {
            ++words;
        }
        else if (!check_table(str[i], false))
        {
            ++letters;
        }
    }

    return ((float) letters / words * 100);
}

bool check_table(char ch, bool is_sentence)
{
    //switch case that for some reason 
    //fixed many of my bugs after 
    //looking at the example to check through a sentence counter
    switch (ch)
    {
        case '!':
        case '?':
        case '.':
            if (is_sentence)
            {
                return true;
            }
        case ',':
        case ':':
        case ';':
        case '\'':
        case '\0':
            if (!is_sentence)
            {
                return true;
            }
    }
    
    return false;
}