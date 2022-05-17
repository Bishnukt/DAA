#include"heap_helper.h"
#define left (index*2+1)
#define right (index*2+2)

void max_heapify(int *arr,int index,int size)
{
	int max_val=0;
	if(right<=size)
		max_val=max(arr,left,right);
	else if(left<=size)
		max_val=left;
	else return;

	if(arr[max_val]>arr[index])
	{
		swap(&arr[max_val],&arr[index]);
		max_heapify(arr,max_val,size);
	}


//		if(left<=size)
//		{
//			if(arr[left]>arr[index])
//			{
//				swap(&arr[left],&arr[index]);
//				heapify(arr,left,size);
//			}
//		}
//		if(right<=size)
//		{
//			if(arr[right]>arr[index])
//			{
//				swap(&arr[right],&arr[index]);
//				heapify(arr,right,size);
//			}
//		}

}

void min_heapify(int *arr,int index,int size)
{
        int min_val=0;
        if(right<=size)
                min_val=min(arr,left,right);
        else if(left<=size)
                min_val=left;
        else return;

        if(arr[min_val]<arr[index])
        {
                swap(&arr[min_val],&arr[index]);
                min_heapify(arr,min_val,size);
        }
}


void swap(int *a,int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
}

void max_heap(int *arr,int index,int size)
{
	for(int i=size;i>=0;i--)
		max_heapify(arr,i,size);
}

void min_heap(int *arr,int index,int size)
{
	for(int i=size;i>=0;i--)
		min_heapify(arr,i,size);
}

int max(int *arr,int a,int b)
{
	if(arr[a]>arr[b])
		return a;
	return b;
}

int min(int *arr,int a,int b)
{
	if(arr[a]<arr[b])
		return a;
	return b;
}
