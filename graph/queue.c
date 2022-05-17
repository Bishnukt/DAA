#include<stdio.h>
#include<stdlib.h>
#include"graph_adj_list.h"

struct node
{
	struct vertex *link;
	struct node *next;
};

struct node *queue=NULL;

struct node *enqueue(struct node *head,struct vertex *val)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->link=val;
	tmp->next=NULL;
	if(head==NULL)
		return tmp;
	struct node *ptr=head;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=tmp;
	return head;
}

struct vertex *dequeue()
{
	if(queue!=NULL)
	{
		struct node *tmp=queue;
		struct vertex *ptr=queue->link;
		queue=queue->next;
		free(tmp);
		return ptr;
	}
	return NULL;
}

int main()
{
	struct vertex *vertices=NULL;
	for(int i=1;i<=5;i++)
		vertices=add_vertex(vertices,i);
	printf("\nVertices are: ");
	display_vertices(vertices);
	for(int i=5;i>=1;i--)
		{
			struct vertex *tmp=find(vertices,i);
			queue=enqueue(queue,tmp);
		}	
	struct vertex *temp=dequeue(queue);
	printf("\nAFter dequeueing: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->key);
		temp=dequeue(queue);
	}
	return 0;
}
