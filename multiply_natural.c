/*
Name- Bishnu Kant Thakur
Program- Write a program to multiply first n natural numbers recursively.
*/

#include <stdio.h>

int multiply(int);

int main()
{
    int n, res;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    res = multiply(n);
    printf("Multiplication of first %d natural numbers = %d.\n", n, res);
    return 0;
}

int multiply(int n)
{
    if (n == 1)
        return 1;
    return n * multiply(n - 1);
}
