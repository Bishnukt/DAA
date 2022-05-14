#include<stdio.h>
#include<stdlib.h>
void create_edge(int **,int,int);
void display_mat(int **,int);
int main()
{
	int v,e=0,src,dest;
	printf("Enter the no. of vertices: ");
	scanf("%d",&v);

	int **adj_mat=(int **)calloc(v+1,sizeof(int *));
	for(int i=0;i<=v;i++)
		adj_mat[i]=(int *)calloc(v+1,sizeof(int));

	//printf("Enter the no. of edges: ");
	//scanf("%d",&e);
	printf("Enter the source and destination of edges:\n");
	printf("To finish enter greater source or destination\n");

	scanf("%d%d",&src,&dest);
	while(src<=v && dest<=v)
	{
		if(adj_mat[src][dest]==0)
			e++;
		create_edge(adj_mat,src,dest);
		scanf("%d%d",&src,&dest);
	}
	printf("\nTotal %d edges.\n",e);
	display_mat(adj_mat,v+1);
	return 0;
}

void create_edge(int **mat,int src,int dest)
{
	mat[src][dest]=1;
	mat[dest][src]=1;
}

void display_mat(int **arr,int n)
{
	printf("\n");
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
		printf("%5d",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


