#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int number;
	struct node *next;	
}NODE;
/*链表的结构单元，关键是存在一个自己的指针变量，指向下一个同类结构，在不少其他语言中，类似C语言的数组由这种形式存在*/
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
	/*malloc申请一个存储空间，参数为空间大小，返回值为一个void类型指针，使用强制类型转化变为制定的链表指针*/
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
	/*创建循环链表，也就是闭环的链表结构*/
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
		/*free()为释放存储空间*/
		p1=p2->next;
	}
	printf("last one is number%d\n",p1->number);
	return 0;
}
