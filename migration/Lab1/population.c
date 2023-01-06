#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int sp;
    do
    {
        sp = get_int("Enter starting population size: ");
    }
    while (sp < 9);
    // TODO: Prompt for end size
    int ep;
    do
    {
        ep = get_int("Enter starting population size: ");
    }
    while (ep < sp);
    // TODO: Calculate number of years until we reach threshold
    int n = 0;
    for (int i = 0; sp < ep; i++)
    {

        sp = sp + sp / 3 - sp / 4;
        n++;
    }
    // TODO: Print number of years
    printf("Years: %i \n", n);

}
