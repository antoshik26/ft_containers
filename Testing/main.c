#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct str
{
	int a;
	struct str *right;
	struct str *left;
	struct str *root;
}				t_str;


int main()
{
	
	t_str *a;
	a = (t_str *)malloc(sizeof(t_str));
	a->a = 12;
	a->right = NULL;
	a->left = NULL;
	a->root = NULL;
	
	t_str *b;
	b = (t_str *)malloc(sizeof(t_str));
	b->right = NULL;
	b->left = NULL;
	b->root = a;
	
	a->left = b;
	return (0);
}