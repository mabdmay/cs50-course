#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (1 > n || n > 8);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1 ; j > i; j--)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        
        printf("  ");
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}