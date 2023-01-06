#include<cs50.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>

int main(void)
{
    string text = get_string("Text: \n");
    int counter = 0;
    int n = strlen(text);

    int wordcount = 1;
    int sentences = 0;
    for(int i = 0; i < n; i++)
    {
        if( (text[i] < 123 && text[i] > 96) || (text[i] < 91 && text[i] > 64) )
        {
            counter++;
        }

        if(text[i] == 32)
        {
            wordcount++;
        }

        if(text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    float L = ((float)counter / wordcount) * 100;
    float S = ((float)sentences / wordcount) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int grade = index;

    /*printf("letters: %i\n", counter);
    printf("Words: %i\n", wordcount);
    printf("Sentences: %i\n", sentences);
    printf("L: %f\n", L);
    printf("S: %f\n", S);
    printf("index: %f\n", index);*/

    if(index > 15)
    {
        printf("Grade 16+\n");
    }
    else if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}