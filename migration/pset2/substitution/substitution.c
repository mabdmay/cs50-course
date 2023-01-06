#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = toupper(key[i]);
    }

    if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (key[i] > 90 || key[i] < 65)
        {
            return 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26 - i ; j++)
        {
            if (key[i] == key[j])
            {
                printf("Invalid key\n");
                return 1;
            }
        }
    }

    string plain_text = get_string("Plain Text: ");
    string cipher = plain_text;

    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        if (plain_text[i] < 91 && plain_text[i] > 64)
        {
            int value = plain_text[i];
            cipher[i] = key[value - 65];
        }

        if (plain_text[i] < 123 && plain_text[i] > 96)
        {
            int value = plain_text[i];
            cipher[i] = key[value - 97];
            cipher[i] = tolower(cipher[i]);
        }
    }
    printf("ciphertext: %s\n", cipher);
    return 0;
}