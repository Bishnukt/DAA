#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *get_prime(int,int *);
void display(int *,int);

int main()
{
    int n,size=0;
    int *res;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Prime numbers betweeen 1 and %d : ", n);
    res=get_prime(n,&size);
    display(res,size);
    return 0;
}

int *get_prime(int n,int *size)
{
    // int arr[100];
    int i, j, k, flag = 1;
    int *arr = (int *)malloc(sizeof(int) * 100);
    arr[0] = 2;
    *size+=1;
    if (n >= 3)
    {
        // int s = sizeof(arr);
        for (i = 3; i <= n; i += 2)
        {
            flag = 1;
            k = 0;
            while (arr[k] <= sqrt((double)i))
            {
                if (i % arr[k] == 0)
                {
                    flag = 0;
                    break;
                }
                k++;
            }
            if (flag)
            {
                arr[*size] = i;
                *size+=1;
            }
        }
    }
    //for (i = 0; i < size; i++)
      //  printf("%d ", arr[i]);
    //printf("\n");
    return arr;
}
void display(int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
