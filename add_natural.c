/*
Name- Bishnu Kant Thakur
Program- Write a program to add first n natural numbers recursively.
*/
#include <stdio.h>
int add_natural(int);
int main()
{
    int n, sum = 0;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    sum = add_natural(n);
    printf("Sum of first %d natural numbers = %d.\n", n, sum);
    return 0;
}
int add_natural(int n)
{
    if (n == 1)
        return 1;
    return n + add_natural(n - 1);
}
