#include <stdio.h>
#include <stdlib.h>
typedef struct branch
{
	int n;
	struct branch *left;
	struct branch *right;
}BRANCH;
BRANCH *branch_creat(int down)
{
	BRANCH *p1;
	if(down==1){
		p1=(BRANCH *)malloc(sizeof(BRANCH));
		p1->left=NULL;
		p1->right=NULL;
		p1->n=1;
	}
	else{
		p1=(BRANCH *)malloc(sizeof(BRANCH));
		p1->left=branch_creat(down-1);
		p1->right=branch_creat(down-1);
		p1->n=(p1->left)->n+(p1->right)->n;
	}
	return p1;
}
int main(int argc, char const *argv[])
{
	int step=9;
	BRANCH *root;
	root=branch_creat(step);
	printf("%d\n",root->n);
	return 0;
}