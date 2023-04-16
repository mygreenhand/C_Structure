#include <stdio.h>
#include <stdlib.h>

/**
 * 
 * 实现为链栈，基本的栈是通过数组即可实现
 * 
 */  


//定义栈节点
typedef struct Node{

	int data;
	struct Node* next;

}Node;

//初始化栈
Node* initStack(){

	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = 0;
	node -> next = NULL;

	return node;
}

//判空
int isEmpty(Node* stack){

	if(stack -> data == 0 || stack -> next == NULL){

		return 1;

	}else{

		return 0;

	}
}

//获取栈顶元素
int getTop(Node* stack){

	if(isEmpty(stack)){

		return -1;
		
	}

	return stack -> next -> data;
}

//出栈
int pop(Node* stack){

	if(isEmpty(stack)){
		return -1;
	}
	Node* node = stack -> next;

	int data = node -> data;

	stack -> next = node -> next;

	free(node);

	stack -> data --;

	return data;
}


//进栈
void push(Node* stack, int data){

	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = data;
	node -> next = stack -> next;
	stack -> next = node;
	stack -> data ++;
}

//遍历栈
void printStack(Node* stack){

	Node* node = stack -> next;

	while(node){

		printf("%d\n", node -> data);
		node = node -> next;

	}
}

int main()
{
	/* code */

	Node* stack = initStack();

	int i;
	for(i = 1; i <= 10; i++){
		push(stack, i);
	}

	printStack(stack);
	//printf("%d\n",pop(stack));

	return 0;
}















