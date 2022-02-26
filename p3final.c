/*
Write a program find whether a given number is a prime number.
int input_number();
int is_prime(int n);
void output(int n, int is_prime);
input:
3
output:
3 is a prime number.
*/

#include <stdio.h>

int input_number()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

int is_prime(int n)
{
    int count = 1;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0) count++;
        if (count > 2) return 0;
    }
    return 1;
}

void output(int n, int isPrime)
{
    if (isPrime)
        printf("%d is a prime number\n", n);
    else
        printf("%d is a composite number\n", n);
}

int main()
{
    int num = input_number();
    int res = is_prime(num);
    output(num, res);
    return 0;
}