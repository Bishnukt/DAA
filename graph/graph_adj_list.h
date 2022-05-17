#include<stdio.h>
#include<stdlib.h>

struct vertex{
        int key;
	int visited;
        struct vertex *next_vertex;
        struct edge *start_edge;
};

struct edge{
        int weight;
        struct vertex *dest;
	struct edge *next_edge;
};

struct vertex *add_vertex(struct vertex *,int);
struct vertex *add_edge(struct vertex *,int,int);
struct vertex *find(struct vertex *,int);
void display_vertices(struct vertex *);
void adjacency_list(struct vertex *);

/*int main()
{
	struct vertex *vertices=NULL;	
	struct edge *edges=NULL;
	int n;

	printf("Enter no. of vertices: ");
	scanf("%d",&n);
	printf("Enter %d vertices: ",n);	
	while(n--)
	{
		int val;
		scanf("%d",&val);
		vertices=add_vertex(vertices,val);
	}
	printf("\nVertices are: ");
	display_vertices(vertices);
	printf("\n");

	int src=0,dest=0;
	while(1)
	{
	printf("Enter source key(Enter -1 to finish): ");
	scanf("%d",&src);
	if(src==-1)
		break;
	printf("No. of edges: ");
	scanf("%d",&n);
	printf("Enter all destination keys(Enter -1 to finish):\n");
	scanf("%d",&dest);
	while(dest!=-1)
	{
		vertices=add_edge(vertices,src,dest);
		scanf("%d",&dest);
	}
	}	
	printf("\nAdjacency List:\n\n");
	adjacency_list(vertices);
}*/

struct vertex *add_vertex(struct vertex *start,int value)
{
	struct vertex *tmp=(struct vertex *)malloc(sizeof(struct vertex));
	tmp->key=value;
	tmp->visited=0;
	tmp->next_vertex=NULL;
	tmp->start_edge=NULL;
	if(start==NULL)
		start=tmp;
	else
	{
		struct vertex *ptr=start;
		while(ptr->next_vertex!=NULL)
			ptr=ptr->next_vertex;
		ptr->next_vertex=tmp;
	}
	return start;
}

struct vertex *add_edge(struct vertex *start,int a ,int b)
{
	struct vertex *src=find(start,a);
	struct vertex *dest=find(start,b);
	if(dest!=NULL && src!=NULL)
	{
		struct edge *temp=(struct edge *)calloc(1,sizeof(struct edge));
		temp->dest=dest;
		temp->next_edge=NULL;
		if(src->start_edge==NULL)
		{
			src->start_edge=temp;
			return start;
		}
		struct edge *ptr=src->start_edge;
		while(ptr->next_edge!=NULL)
			ptr=ptr->next_edge;
		ptr->next_edge=temp;
		return start;
	}
	printf("Either source or destination doesn't exist.\n");
	return start;
}
	

void display_vertices(struct vertex *start)
{
	if(start==NULL)
	{
		printf("\nVertices list is empty.\n");
		return ;
	}
	struct vertex *ptr=start;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->key);
		ptr=ptr->next_vertex;
	}
}

void adjacency_list(struct vertex *start)
{
	if(start!=NULL)
	{
		struct vertex *ptr=start;
		while(ptr!=NULL)
		{
			printf("%d->",ptr->key);
			struct edge *edges=ptr->start_edge;
			if(edges==NULL)
				printf("NULL\n");
			while(edges!=NULL)
			{
				printf("%d ",edges->dest->key);
				edges=edges->next_edge;
			}
			printf("\n");
			ptr=ptr->next_vertex;
		}
		printf("\n");
	}
	else
		printf("List doesn't exists.\n");
}
struct vertex *find(struct vertex *start,int val)
{
	struct vertex *ptr=start;
	while(ptr!=NULL && ptr->key!=val)
		ptr=ptr->next_vertex;
	return ptr;
}
