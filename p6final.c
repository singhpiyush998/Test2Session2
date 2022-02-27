/*
Write a program to find the index of a substring of a string.
void input_string(char *a);
int str_reverse(char *string, char *substring);
void output(char *string, char *substring, int index);
input:
helloworldhello
world
output:
The index of world in helloworldhello is 5
*/
#include <stdio.h>

void input_string(char* a, char* b)
{
    printf("Enter two string within 255 characters each:\n");
    scanf("%255s%255s", a, b);
}

/*
    index of substring in string - If substing is found
    -1 - If substring is not found
*/

int subStrPosn(char* string, char* substring)
{
    int substr_index = 0;
    int str_index = 0;
    while (*substring && *string)
    {
        if (*string == *substring)
        {
            substring++;
            substr_index++;
        }
        else if (substr_index)
        {
            substring -= substr_index;
            substr_index = 0;
        }
        string++;
        str_index++;
    }
    if (substr_index) return str_index - substr_index;
    return -1;
}

void output(char* string, char* substring, int index)
{
    if (index >= 0)
        printf("The index of %s in %s is %d\n", substring, string, index);
    else
        printf("%s is not found in %s\n", substring, string);
}

int main()
{
    char str[256];
    char substr[256];
    input_string(str, substr);
    int index = subStrPosn(str, substr);
    output(str, substr, index);
    return 0;
}