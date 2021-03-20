#include<stdio.h>
#include<stdlib.h>
typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode;
typedef struct{
	Qnode *head;
	Qnode *rear;
	int len;
}Que;
void create(Que &q)
{
	q.head=q.rear=(Qnode*)malloc(sizeof(Qnode));
	q.head->next = NULL;
	q.len = 0;
}
void insert(Que &q, int e)
{
	Qnode *p;
	p = (Qnode*)malloc(sizeof(Qnode));
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear=p;
	q.len++;
}
void out(Que &q)
{
	Qnode *p;
	p = q.head->next;
	q.head->next = p->next;
	free(p);
	q.len--;
}
void display(Que &q)
{
	while (q.head != q.rear)
	{
		printf("%d ", q.head->next->data);
		q.head = q.head->next;
	}
}
int main()
{
	Que q;
	create(q);
	insert(q, 5);
	insert(q, 6);
	out(q);
	display(q);
}


