#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0


//定义节点结构
typedef struct Node
{
	int data;
	struct Node* next;
}Node;


//实现初始化循环单链表
Node* initLink(){
	Node* link = (Node*)malloc(sizeof(Node));
	link -> data = 0;
	link -> next = link;

	return link;
}

//进行循环单链表的头插法
void headInsert(Node* link, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = link -> next;
	link -> next = node;
	link -> data ++;
}

//进行循环单链表的尾插法
void tailInsert(Node* link, int data){
	Node* pre = link;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	while(pre -> next != link){
		pre = pre -> next;
	}
	node -> next = link;
	pre -> next = node;
	link -> data ++;
}


//进行循环单链表的节点遍历
void printLink(Node* link){
	Node* node = link -> next;
	while(node != link){
		printf("%d\n", node -> data);
		node = node -> next;
	}
}

int delete(Node* link, int data){
	Node* preNode = link;
	Node* node = link -> next;
	while(node != link){
		if(node -> data == data){
			preNode -> next = node -> next;
			free(node);
			return TRUE;
		}
		preNode = node;
		node = node -> next;
	}
	link -> data --;
	return FALSE;
}


int main(){

	Node* link = initLink();
	int i;
	//循环添加节点
	for (i = 1; i <= 10; ++i)
	{
		/* code */
		//headInsert(link, i);
		tailInsert(link, i);
	}
	printLink(link);

	int deleteNum = 10;

	if(delete(link, deleteNum) == 1){

		printf("%d值删除成功\n", deleteNum);

	}

	printLink(link);
	

	return 0;

}



