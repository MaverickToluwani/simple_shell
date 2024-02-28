#include <stdio.h>
#include <stdlib.h>

void _strock(char *str, char *lis)
{
    while (*str != '\0')
    {
        char *temp = lis; // Store the original pointer to str
        int found = 0;

        while (*temp != '\0')
        {
            if (*str == *temp)
            {
                found = 1;
                break;
            }
            temp++;
        }

        if (*str == ' ') // Print newline for space in str2
        {
            printf("\n");
        }
        else if (!found) // Print character from str2 only if it's not found in str
        {
            printf("%c", *str);
        }

        str++;
    }
    printf("\n");
}
int main(void)
{
    char *str1 = "Hello, world! How are you?";
    char *str2 = " *,!?";

    _strock(str1, str2);
}

