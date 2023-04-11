#include <stdio.h>
#include <stdlib.h>

//定义队列结构
typedef struct Node{
	
	int data;
	struct Node* next;
}Node;

//应该准确的说，会有指向头结点和为节点的指针
//但是也可以不用设置，如果说有要求要访问尾结点，那就可以设置一下

// typedef struct QueueLinke{
// 	Node* front;
// 	Node* tail;
// }QLinke;


//初始化队列
Node* initQueue(){
	Node* node = (Node*)malloc(sizeof(Node));
	node -> data = 0;
	node -> next = NULL;

	return node;
}

//出队
int  outQueue(Node* queue){

	if(queue -> data != 0){

		Node* q = queue -> next;

		int data = q -> data;
		
		queue -> next = q -> next;

		free(q);

		queue -> data --;

		return data;

	}

	return -1;
}



//入队

void insertQueue(Node* queue, int data){

	Node* node = (Node*)malloc(sizeof(Node));

	node -> data = data;

	Node* q = queue;

	while(q -> next != NULL){
		q = q -> next;
	}

	node -> next = q -> next;
	q -> next = node;

	queue -> data ++;

}

//遍历队列
void printQueue(Node* queue){

	if (queue -> data != 0){
		/* code */
		Node* q = queue -> next;

		while(q){

			printf("%d \n", q -> data);
			q = q -> next;

		}
	}else{
		printf("队列为空，没有任何值0000\n");
	}
	
}




int main()
{
	/* code */
	Node* queue = initQueue();

	printQueue(queue);

	int i;
	for(i = 1; i <= 10; i++){
		insertQueue(queue, i);
	}

	printQueue(queue);

	printf("将队列中%d 出队\n", outQueue(queue));

	printQueue(queue);

	return 0;
}