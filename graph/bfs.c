#include <stdio.h>
#include <stdlib.h>
#include"queue.h"
#include"graph_adj_list.h"

//struct node *queue=NULL; 
int *arr=NULL;
int i=0;

struct vertex *bfs(struct vertex *,struct vertex *);
void clear_visit(struct vertex *);
void display(int *);

int main()
{
	int n, key = 0, choice = 0;
	printf("Enter the no. of vertices: ");
	!scanf("%d", &n);
	arr=(int *)calloc(n,sizeof(int));

	struct vertex *vertices = NULL,*start=NULL;
	printf("Enter key values of %d vertices: ", n);
	while (n--)
	{
		scanf("%d", &key);
		vertices = add_vertex(vertices, key);
	}
	printf("Vetices are: ");
	display_vertices(vertices);
	printf("\n");
	printf("Add edges:\n");
	int src = 0, dest = 0;
	while (1)
	{
		printf("Enter the source key(Enter -1 to finish: ");
		scanf("%d", &src);
		if (src == -1)
			break;
		printf("Enter all destination keys of vertex %d(Enter -1 to finish): \n", src);
		scanf("%d", &dest);
		while (dest != -1)
		{
			vertices = add_edge(vertices,src,dest);
			scanf("%d", &dest);
		}
		printf("Add edges of next vertex-");
	}

	while (1)
	{
		printf("1.BFS\n2.Add Vertex.\n3.Add edge.\n4.Show adjacency list.\n5.Exit.\n\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the starting vertex key: ");
			scanf("%d", &key);
			start=find(vertices,key);
			printf("BFS starting from vertex %d: ", key);
			clear_visit(vertices);
			i=0;
			start->visited=1;
			arr[i]=start->key;
			i++;
			vertices=bfs(vertices,start);
			display(arr);
			printf("\n");
			break;

		case 2:
			printf("Enter the vertex key: ");
			scanf("%d", &key);
			vertices = add_vertex(vertices, key);
			printf("\n");
			break;

		case 3: 
			printf("Enter the source key: ");
			scanf("%d", &src);
			printf("Enter all destination keys of %d(Enter -1 to finish):\n", src);
			scanf("%d", &dest);
			while (dest != -1)
			{
				vertices=add_edge(vertices,src,dest);
				scanf("%d",&dest);
			}

		case 4:
			printf("\nAdjacency List of the given graph: \n");
			adjacency_list(vertices);
			printf("\n");
			break;

		case 5:
			exit(0);
		}
	}
}

struct vertex *bfs(struct vertex *head,struct vertex *start)
{
//	struct edge *ptr=start->start_edge;
	if(start==NULL)
		return head; 
//	printf("\nInside bfs, key=%d, %d\n",start->key,i);
	struct edge *ptr=start->start_edge;

	while(ptr!=NULL)
	{
		if(!ptr->dest->visited)
		{
			queue=enqueue(queue,ptr->dest);
			arr[i]=ptr->dest->key;
			i++;
			ptr->dest->visited=1;
		}
		ptr=ptr->next_edge;
	}
	struct vertex *temp=dequeue(queue);
	head=bfs(head,temp);
	return head;
}

void display(int *list)
{
	int j=0;
	while(j<i)
	{
		printf("%d ",arr[j]);
		j++;
	}
}

void clear_visit(struct vertex *vertices)
{
	struct vertex *ptr=vertices;
	while(ptr!=NULL)
	{
		ptr->visited=0;
		ptr=ptr->next_vertex;
	}
}
