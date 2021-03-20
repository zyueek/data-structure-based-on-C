#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	int lenth;
	struct node *next;
}Node;
typedef struct Stack
{
	int stacksize;
	int *top;
	int *base;
}stack;
Node *createlist(int p)
{
	Node *head = (Node*)malloc(sizeof(Node));
	Node *tmp=head;
	head->lenth = 0;
	for (int i = 0; i < p; i++)
	{
		Node *node = (Node*)malloc(sizeof(Node));
		scanf_s("%d", &node->data);
		node->next = NULL;
		tmp->next = node;
		tmp = tmp->next;
		head->lenth++;
	}
	return head;
}
stack *create()
{
	stack *s;
	s = (stack*)malloc(sizeof(stack));
	s->base = (int*)malloc(100*sizeof(int));
	s->top = s->base;
	s->stacksize = 100;
	return s;
}
int get(stack *s)
{
	return *s->top;
}
int empty(stack *s)
{
	if (s->top == s->base)
		return 0;
	else 
		return 1;
}
void push(stack *s, int e)
{
	s->top++;
	*s->top = e;
}
bool judge(Node *M,stack *s)
{
	int indicator;
	indicator = M->lenth / 2;
	Node *M1 = M;
	int timer = 0;
	for (int i = 0; i < indicator; i++)
	{
		M = M->next;
		push(s, M->data);
	}
	if (M1->lenth % 2 == 0)
	{
		M = M->next;
		while (M!=NULL)
		{
			printf("%d", M->data);
			if ((M->data) == get(s))
			{
				M = M->next;
				s->top--;
				timer++;
			}
			else
				break;
		}
	}
	else
	{
		M = M->next->next;
		for (int i = 0; i < indicator; i++)
		{
			get(s);
			if (M->data == get(s))
			{
				M = M->next;
				s->top--;
				timer++;
			}
		}
	}
	if (timer == indicator)
		return true;
	else
		return false;
}
void display(Node *L)
{
	while (L->next != NULL)
	{
		L = L->next;
		printf("%d", L->data);
	}
}
int main()
{
	Node *L;
	L=createlist(5);
	stack *s;
	s = create();
	if (judge(L,s))
		printf("right");
	else
		printf("wrong");
	return 0;
}
