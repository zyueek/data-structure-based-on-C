#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int rotation = 0;
typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode;
Lnode* create(int n)
{
	Lnode *p = (Lnode*)malloc(sizeof(Lnode));
	Lnode *temp = p;
	for (int i = n; i > 0; i--)
	{
		Lnode *node = (Lnode*)malloc(sizeof(Lnode));
		if (node)
		{
			node->data = i;
			node->next = NULL;
			temp->next = node;
			temp = temp->next;
		}
	}
	return p;
}
void insert(Lnode *L, int i, int e)
{
	Lnode *p = L;
	for (int j = 0; j < i - 1;j++)
		p = p->next;
	Lnode *s = (Lnode*)malloc(sizeof(Lnode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
void out(Lnode *L, int e)
{
	int i = 0;
	Lnode *p = L;
	Lnode *q = L;
	while (p->data != e)
	{
		p = p->next;
		i++;
	}
	printf("%d\n", i);
	for (int h = 0; h < i-1; h++)
	{
		q = q->next;
	}
	Lnode *m = q->next;
	q->next = m->next;
	free(m);
}
void find(Lnode *L, int i)
{
	Lnode *p = L;
	int h = 0;
	while (p->data != i)
	{
		p = p->next;
		h++;
	}
	printf("%d", h);
}
void refer(Lnode *L)
{
	Lnode *p = L;
	while (p->next != NULL)
	{
		if (rotation == 1)
		{
			printf("%d ", p->data);
			p = p->next;
		}
		else
		{
			p = p->next;
			printf("%d ", p->data);
		}
	}
}
void pure(Lnode *L)
{
	Lnode *prior = L->next;
	Lnode *rear = L;
	while (prior != NULL)
	{
		if (rear->data!=prior->data)
		{
			rear = rear->next;
			rear->data = prior->data;
		}prior = prior->next;
	}
	rear->next = NULL;
}
Lnode *reverse(Lnode *L)
{
	rotation = 1;
	Lnode *pre = NULL;
	Lnode *cur = L;
	while (cur != NULL)
	{
		Lnode *tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	return pre;
}
int main()
{
	Lnode *L;
	L=create(5);
	L = reverse(L);
	refer(L);
	return 0;
}