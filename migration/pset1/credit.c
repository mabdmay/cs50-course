#include<cs50.h>
#include<stdio.h>

int main(void)
{
    long Number = get_long("Number: ");
    int dig;
    int sum_a = 0;
    int sum_b = 0;
    int n = 0;
    int a=0, b=0;
    int f2, f1;
    int z=0, x=0;

    for (int i = 1; Number>0 ; i++)
    {
        dig = Number%10;
        Number = Number / 10;
        //determining and summing the product of every other digit
        if (i % 2 == 0)
        {
            dig = 2 * dig;
            if(dig < 10)
            {
                a = dig + a;
            }
            else
            {
                for (int j = 0; j < 2; j++)
                {
                    int s = dig % 10;
                    dig = dig / 10;
                    b = s + b;
                }
            }
            sum_a = a + b;
        }
        else
        {
            sum_b = dig + sum_b;
        }
        n++;
        //storing the first 2 digits
        if (Number < 100 && z < 1)
        {
            f2 = Number;
            z++;
        }
        //storing the first digit
        if (Number < 10 && x < 1)
        {
            f1 = Number;
            x++;
        }
    }
    // verifying the checksum;
    if ((sum_a + sum_b) % 10 == 0 && n > 12)
    {
        //checking for the number of digits and the type of card
        if (n == 16)
        {
            if (f1 == 4)
            {
                printf("VISA\n");
            }
            else if (f2 == 51 || f2 == 52 || f2 == 53 || f2 == 54 || f2 == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n == 15)
        {
            if (f2 == 34 || f2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (n == 13 && f1 == 4)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}