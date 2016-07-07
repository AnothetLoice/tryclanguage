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
	int numberOfStudents=0,ring=0,iteration;
	NODE *nodeHead,*nodePoint_1,*nodePoint_2;
	printf("please input number of students:" );
	scanf("%d",&numberOfStudents);
	printf("please input ring:");
	scanf("%d",&ring);
	iteration=numberOfStudents-1;
	nodeHead=(NODE *)malloc(sizeof(NODE));
	/*malloc申请一个存储空间，参数为空间大小，返回值为一个void类型指针，使用强制类型转化变为制定的链表指针*/
	nodeHead->next=nodeHead;
	nodeHead->number=1;
	nodePoint_1=nodeHead;
	while(iteration!=0){
		iteration=iteration-1;
		nodePoint_2=(NODE *)malloc(sizeof(NODE));
		nodePoint_2->next=nodePoint_1->next;
		nodePoint_2->number=(numberOfStudents-iteration);
		nodePoint_1->next=nodePoint_2;
		nodePoint_1=nodePoint_2;
	}
	/*创建循环链表，也就是闭环的链表结构*/
	nodePoint_1=nodeHead;
	while(1){
		if(nodePoint_1==nodePoint_1->next)
			break;
		for(iteration=0;iteration<ring;iteration++){
			nodePoint_2=nodePoint_1;
			nodePoint_1=nodePoint_1->next;
		}
		nodePoint_2->next=nodePoint_1->next;
		free(nodePoint_1);
		/*free()为释放存储空间*/
		nodePoint_1=nodePoint_2->next;
	}
	printf("last one is number%d\n",nodePoint_1->number);
	return 0;
}
