#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}Tree;
void create(Tree **t,int i)
{
	(*t)->data = i;
	(*t)->left = NULL;
	(*t)->right = NULL;
}
void insert(Tree *t,int e)
{
	int j = 0;
	int n = 0;
	int *h;
	h = (int*)malloc(e*sizeof(int));
	for (int m = 0; m < e; m++)
		scanf_s("%d", &h[m]);
	while (n<e){
		if (h[n] <= t->data)
		{
			j++;
			if (j > 0) {
				t = t->left;				
				create(&t, h[n]);
			}
		}
		else
		{
			j--;
			if (j <= 0) {
				t = t->right;
				create(&t, h[n]);
			}
		}
		n++;
	}
}
int deep(Tree *t)
{
	if (t == NULL){
		return 0;
	}
	int dep1 = deep(t->left);
	int dep2 = deep(t->right);
	if (dep1 > dep2){
		return dep1 + 1;
	}
	else{
		return dep2 + 1;
	}
}
int nodenum(Tree *t)
{
	if (t == NULL)
	{
		return 0;
	}
	else if (t->left==NULL&&t->right == NULL)
	{
		return 1;
	}
	int node1 = nodenum(t->left);
	int node2 = nodenum(t->right);
	return 1+node1 + node2;
}
void pre(Tree *t)
{
	if (t == NULL)
	{
		return;
	}
	printf("%d ", t->data);
	pre(t->left);
	pre(t->right);
}
int all_node(Tree *t){
	if (t->left == NULL&&t->right == NULL)
	{
		return 1;
	}
	else if (t == NULL){
		return 0;
	}
	return 1+all_node(t->left) + all_node(t->right);
}
int main()
{
	Tree *t;
	t = (Tree*)malloc(sizeof(Tree));
	int e;
	create(&t, 5);
	printf("the amount of number you'd like to input\n");
	scanf_s("%d", &e);
	insert(t,e);
	printf("%d", t->right->data);
	printf("deep is %d\n", deep(t));
	printf("the num of node is %d\n", nodenum(t));
	return 0;
}