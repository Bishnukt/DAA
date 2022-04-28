#include"heap_helper.h"

void heapify(int *arr,int index,int size)
{

		int left=index*2+1;
		int right=index*2+2;
		if(left<=size)
		{
			if(arr[left]>arr[index])
			{
				swap(&arr[left],&arr[index]);
				heapify(arr,left,size);
			}
		}
		if(right<=size)
		{
			if(arr[right]>arr[index])
			{
				swap(&arr[right],&arr[index]);
				heapify(arr,right,size);
			}
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
	if(index>=0)
	{
		int left=index*2+1;
		int right=index*2+2;
		if(left<=size)
		{
			if(arr[left]>arr[index])
			{
				swap(&arr[left],&arr[index]);
				max_heap(arr,left,size);
			}
		}
		if(right<=size)
		{
			if(arr[right]>arr[index])
			{
				swap(&arr[right],&arr[index]);
				max_heap(arr,right,size);
			}
		}
		max_heap(arr,index-1,size);
	}
}

