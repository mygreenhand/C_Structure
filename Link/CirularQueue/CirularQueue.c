#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

//定义循环队列节点结构
typedef struct Queue{

	int data[MAXSIZE];
	int front;
	int rear;
}Queue;


//初始化循环队列
Queue* initCircularQueue(){

	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue -> front = queue -> rear = 0;

	return queue;

}

//判满
int isFull(Queue* queue){
	if((queue -> front + 1) % MAXSIZE == queue -> front){
		return 1;	
	}else{
		return 0;
	}
}

//判空
int isEmpty(Queue* queue){
	if(queue -> front == queue -> rear ){
		return 1;	
	}else{
		return 0;
	}
}


//入队
int enQueue(Queue* queue, int data){

	if(isFull(queue)){

		return 0;
	}

	queue -> data[queue -> rear] = data;
	queue -> rear = (queue -> rear + 1) % MAXSIZE;

	return 1;
}

//出队
int deQueue(Queue* queue){

	if(isEmpty(queue)){

		return -1;
	}

	int data = queue -> data[queue -> front];
	queue -> front = (queue -> front + 1) % MAXSIZE;

	return data;
}

//遍历队列
void pintCirularQueue(Queue* queue){
	int queueLength = (queue -> rear - queue -> front + MAXSIZE) % MAXSIZE;
	int first = queue -> front;
	int i;
	for(i = 0; i < queueLength; i++){
		printf("%d \n", queue -> data[first]);
		first = (first + 1) % MAXSIZE;
	}
}

int main(){

	Queue* queue = initCircularQueue();

	pintCirularQueue(queue);

	int i;

	//因为要牺牲一个空间，用来判断是否为空，所以只能存放数组长度-1个元素
	for(i = 1; i < MAXSIZE; i++){
		enQueue(queue, i);
	}

	pintCirularQueue(queue);

	printf("将队列中%d 出队\n", deQueue(queue));

	pintCirularQueue(queue);

	return 0;
}
















