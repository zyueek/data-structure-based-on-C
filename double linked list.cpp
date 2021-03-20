#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode
{
	int data;
	struct Lnode *prior;
	struct Lnode *next;
}Lnode;
Lnode* create(Lnode *head,int i)
{
	head = (Lnode*)malloc(sizeof(Lnode));
	Lnode *temp = head;
	for (int h = 0; h < i; h++)
	{
		Lnode *node = (Lnode*)malloc(sizeof(Lnode));
		node->data = h;
		node->next = NULL;
		node->prior = temp;
		temp->next = node;
		temp = temp->next;
	}
	return head;
}
void insert(Lnode *head, int i, int e)
{
	Lnode *q = head;
	for (int h = 0; h < i; h++)
	{
		q = q->next;
	}
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->prior = q->prior;
	q->prior->next = s;
	s->next = q;
	q->prior = s;
}
void out(Lnode *head, int i)
{
	Lnode *q = head;
	for (int h = 0; h < i - 1; h++)
	{
		q = q->next;
	}
	q->prior->next = q->next;
	q->next->prior = q->prior;
	free(q);
}
void refer(Lnode *head)
{
	Lnode *q = head;
	while (q->next != NULL)
	{
		q = q->next;
		printf("%d ", q->data);
	}
}
int main()
{
	Lnode *L = NULL;
	L = create(L, 5);
	refer(L);
	insert(L, 3, 8);
	refer(L);
	return 0;
}