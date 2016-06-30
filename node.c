#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int number;
	struct node *next;	
}NODE;
int main()
{
	int all=0,ring=0,i;
	NODE *head,*p1,*p2;
	printf("please input number of students:" );
	scanf("%d",&all);
	printf("please input ring:");
	scanf("%d",&ring);
	i=all-1;
	head=(NODE *)malloc(sizeof(NODE));
	head->next=head;
	head->number=1;
	p1=head;
	while(i!=0){
		i=i-1;
		p2=(NODE *)malloc(sizeof(NODE));
		p2->next=p1->next;
		p2->number=(all-i);
		p1->next=p2;
		p1=p2;
	}
	p1=head;
	while(1){
		if(p1==p1->next)
			break;
		for(i=0;i<ring;i++){
			p2=p1;
			p1=p1->next;
		}
		p2->next=p1->next;
		free(p1);
		p1=p2->next;
	}
	printf("last one is number%d\n",p1->number);
	return 0;
}
