//#include<stdio.h>
//#include<stdlib.h>
struct node
{
	struct vertex *link;
	struct node *next;
};
struct node *queue=NULL;
struct node *enqueue(struct node *,struct vertex *);
struct vertex *dequeue(struct node *);

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

struct vertex *dequeue(struct node *head)
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


