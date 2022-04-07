#include<stdio.h>
#include<stdlib.h>

void merge(int *,int,int,int,int);
void merge_sort(int *,int ,int);

int main()
{
	int n,i,j;
	int *arr;
	printf("Enter the no. of elements: ");
	scanf("%d",&n);
	arr=(int *)malloc(n*sizeof(int));
	printf("Enter %d elements to sort:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	merge_sort(arr,0,n-1);
	printf("Elements after sorting are: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}

void merge_sort(int *arr,int low,int up)
{
	if(low>=up)
		return ;
	int x,y;
	x=(low+up)/3;
	printf("low=%d, up=%d\n",low,up);
	y=(x+up+1)/2;
	printf("x=%d,y=%d\n",x,y);
	merge_sort(arr,low,x);
	merge_sort(arr,x+1,y);
	merge_sort(arr,y+1,up);
	printf("going to call merge : \n");
	getchar();
	merge(arr,low,x,y,up);
}

void merge(int *arr,int low,int x,int y,int up)
{
	int i=low,j=x+1,k=y+1,temp,c=0;
	int *newarr=(int *)malloc((up+1)*sizeof(int ));
	
	while(i<=x && j<=y && k<=up)
	{
		if(arr[i]>arr[j])
		{
			if(arr[j]>arr[k])
			{
				newarr[c]=arr[k];
				k++;
			}
			else
			{
				newarr[c]=arr[j];
				j++;
			}
		}
		else
		{
			if(arr[i]>arr[k])
			{
				newarr[c]=arr[k];
				k++;
			}
			else
			{
				newarr[c]=arr[i];
				i++;
			}
		}
		c++;
	}
	
	if(i>x)
	{
		i=j;
		j=k;
		x=y;
		y=up;
	}
	else if(j>y)
	{
		j=k;
		y=up;
	}

	while(i<=x && j<=y)
	{
		if(arr[i]>arr[j])
		{
			newarr[c]=arr[j];
			j++;
		}
		else
		{
			newarr[c]=arr[i];
			i++;
		}
		c++;
	}

	while(i<=x)
	{
		newarr[c]=arr[i];
		i++;
		c++;
	}
	while(j<=y)
	{
		newarr[c]=arr[j];
		j++;
		c++;
	}
	printf("I am here ");
	c=0;
	for(i=low;i<=up;i++)
	{
		arr[i]=newarr[c];
	c++;
	}

}
