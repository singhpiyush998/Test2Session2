/*
Write a program to find nth number in fibonacci sequence.
Fibonacci sequence consists of 0,1,1,2,3,5,8,13,21........
int input();
int find_fibo(int n);
void output(int n, int fibo);
*/
#include <stdio.h>

int input()
{
    int num;
    printf("Enter n for Fibo(n): ");
    scanf("%d", &num);
    return num;
}

int find_fibo(int n)
{
    int num1 = 1;
    int num2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int temp = num1;
        num1 += num2;
        num2 = temp;
    }
    return num2;
}

void output(int n, int fibo)
{
    printf("Fibo(%d) is %d\n", n, fibo);
}

int main()
{
    int num = input();
    int res = find_fibo(num);
    output(num, res);
    return 0;
}
