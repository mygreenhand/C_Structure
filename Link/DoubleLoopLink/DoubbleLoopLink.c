#include <stdio.h>
#include <stdlib.h>

//定义节点结构
typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;
}Node;

//链表初始化
Node* initLink(){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = 0;
	node -> pre = node;
	node -> next = node;

	return node;
}


//链表头插法
void headInsert(Node* doubbleLoopLink, int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;

	node -> pre = doubbleLoopLink;
	node -> next = doubbleLoopLink -> next;

	if(doubbleLoopLink -> data == 0){

		doubbleLoopLink -> pre = node;

	}else{

		doubbleLoopLink -> next -> pre = node;

	}

	doubbleLoopLink -> next = node;

	doubbleLoopLink -> data ++;

}

//链表尾插法
void tailInsert(Node* doubbleLoopLink, int data){
	Node* dLink = doubbleLoopLink;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	while(dLink -> next != doubbleLoopLink){
		dLink = dLink -> next;
	}

	node -> pre = dLink;
	node -> next = dLink -> next;
	dLink -> next -> pre = node;
	dLink -> next = node;

	doubbleLoopLink -> data ++;

}

//链表删除节点
int deleteNode(Node* doubbleLoopLink, int data){

	Node* dLink = doubbleLoopLink -> next;
	while(dLink != doubbleLoopLink){
		if(dLink -> data == data){
			dLink -> next -> pre = dLink -> pre;
			dLink -> pre -> next = dLink -> next;
			free(dLink);
			doubbleLoopLink -> data --;
			return 1;
		}
		dLink = dLink -> next;
	}

	return 0;
}


//链表遍历
void printLink(Node* doubbleLoopLink){
	Node* node = doubbleLoopLink -> next;
	while(node != doubbleLoopLink){
		printf("%d \n", node -> data);
		node = node -> next;
	}

}


int main(){
	Node* doubbleLoopLink = initLink();

	int i;
	for (i = 0; i <= 10; ++i){
		/* code */
		//headInsert(doubbleLoopLink, i);
		tailInsert(doubbleLoopLink, i);
	}

	printLink(doubbleLoopLink);
	int deleteNum = 10;
	if(deleteNode(doubbleLoopLink, deleteNum) == 1){
		printf("删除成功：%d\n",deleteNum);
	}
	return 0;
}





