#include <stdio.h>
#include <stdlib.h>



#define TRUE 1
#define FALSE 0

//定义节点结构
typedef struct Node{
	int data;
	struct Node* pre;
	struct Node* next;

}Node;

//初始化双链表
Node* initDoubbleLink(){
	Node* doubbleLink = (Node*)malloc(sizeof(Node));
	doubbleLink -> data = 0;
	doubbleLink -> pre = NULL;
	doubbleLink -> next = NULL;

	return doubbleLink;
}

//经典的头插法
void headInsert(Node* doubbleLink, int data){

	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;

	if(doubbleLink -> data == 0){
		node -> next = doubbleLink -> next;
		node -> pre = doubbleLink;
		doubbleLink -> next = node;
	}else{
		node -> pre = doubbleLink;
		node -> next = doubbleLink -> next;
		doubbleLink -> next -> pre = node;
		doubbleLink -> next = node;
	}

	doubbleLink -> data ++;
	
}

//经典的尾插法
void tailInsert(Node* doubbleLink, int data){

	Node* otherNode = doubbleLink;
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	while(otherNode -> next){
		otherNode = otherNode -> next;
	}
	node -> next = otherNode -> next;
	node -> pre = otherNode;
	otherNode -> next = node;

	doubbleLink -> data ++;
}


//遍历链表
void printLink(Node* doubbleLink){
	Node* node = doubbleLink -> next;
	while(node){
		printf("%d \n", node -> data );
		node = node -> next;
	}
	printf("\n");
}

//删除节点
int delete(Node* doubbleLink, int data){

	Node* node = doubbleLink -> next;

	while(node){
		if(node -> data == data){
			node -> pre -> next = node -> next;

			//如果删除的是最后一个节点，那么就可能会出现指针异常情况，
			//因为最后一个节点是没有后继节点的，也就没有后继节点的前驱指针
			if(node -> next != NULL){ 
				node -> next -> pre = node -> pre;
			}
			
			free(node);
			return TRUE;
		}
		node = node -> next;
	}
	doubbleLink -> data --;
	return FALSE;

}


int main()
{
	/* code */
	Node* doubbleLink = initDoubbleLink();

	int i;
	for(i = 1; i<= 10; i++){
		//headInsert(doubbleLink, i);
		tailInsert(doubbleLink, i);
	}

	printLink(doubbleLink);

	int deleteNum = 10;
	if(delete(doubbleLink, deleteNum) == 1){
		printf("删除成功\n");
	}

	printLink(doubbleLink);

	return 0;
}




