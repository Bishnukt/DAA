/*
Name- Bishnu Kant Thakur
Program- Write a program to implement bubble sort.
*/

#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *, int);
void display(int *, int);
void input(int *, int);
int main()
{
    int *arr;
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    printf("Enter %d elements: ", n);
    input(arr, n);
    bubble_sort(arr, n);
    printf("Elements after sorting: ");
    display(arr, n);
    return 0;
}
void bubble_sort(int *arr, int n)
{
    int i, j, swapped, temp;
    for (i = n - 1; i >= 0; i--)
    {
        swapped = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped++;
            }
        }
        if (swapped == 0)
            break;
    }
}
void input(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}
void display(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
