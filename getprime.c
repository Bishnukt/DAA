/*
Name- Bishnu Kant Thakur
Program- Write a program to find all prime numbers between 1 to n.
*/
#include <stdio.h>
#include <math.h>

void getprime(int);
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    getprime(n);
    return 0;
}

void getprime(int n)
{
    int i, j, flag;
    if (n >= 3)
    {
        printf("1 2 ");
        for (i = 3; i <= n; i += 2)
        {
            flag = 1;
            for (j = 3; j * j <= i; j++)
            {
                if (i % j == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                printf("%d ", i);
        }
    }
    else
    {
        printf("1 ");
        if (n == 2)
            printf("2\n");
    }
}