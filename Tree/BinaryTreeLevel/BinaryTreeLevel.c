#include <stdio.h>
#include <stdlib.h>


//定义二叉树节点结构

typedef struct treeNode{

	char data;
	struct treeNode* lchild;
	struct treeNode* rchild;

}treeNode;


//定义队节点
typedef struct queueNode{

	treeNode* data;
	struct queueNode* pre;
	struct queueNode* next;

}queueNode;

//初始化队节点
queueNode* initQueue(){

	queueNode* queue = (queueNode*)malloc(sizeof(queueNode));

	queue -> data = NULL;
	queue -> pre = queue;
	queue -> next = queue;

	return queue;

}

//创建二叉树头结点
void createTree(treeNode** tree, char* data, int* index){

	char element = data[*index];
	*index += 1;
	
	if(element == '#'){

		*tree = NULL;
		
	}else{

		*tree = (treeNode*)malloc(sizeof(treeNode));

		(*tree) -> data = element;

		createTree(&((*tree) -> lchild), data, index);

		createTree(&((*tree) -> rchild), data, index);

	}
}

//入队
void enterQueue(queueNode* queue, treeNode* tree){

	queueNode* node = (queueNode*)malloc(sizeof(queueNode));

	node -> data = tree;
	node -> pre = queue -> pre;
	node -> next = queue;

	queue -> pre -> next = node;
	queue -> pre = node;
}

//判队空
int isEmptyQueue(queueNode* queue){

	if (queue -> next == queue){

		/* code */
		return 1;

	}else{

		return 0;
	}
}


//出队

queueNode* outQueue(queueNode* queue){

	if(isEmptyQueue(queue)){

		return NULL;
	}

	queueNode* node = queue -> next;
	queue -> next -> next -> pre = queue;
	queue -> next = node -> next;

	return node;
}


//遍历二叉树


//先序遍历
void preOrder(treeNode* tree){

	if(tree == NULL){

		return;

	}else{

		printf("%c ", tree -> data);
		preOrder(tree -> lchild);
		preOrder(tree -> rchild);

	}
}

//中序遍历

void middleOrder(treeNode* tree){

	if(tree == NULL){

		return;

	}else{

		middleOrder(tree -> lchild);

		printf("%c ", tree -> data);
		
		middleOrder(tree -> rchild);

	}
}

//后续遍历

void postOrder(treeNode* tree){

	if(tree == NULL){

		return;

	}else{

		postOrder(tree -> lchild);
		
		postOrder(tree -> rchild);

		printf("%c ", tree -> data);

	}

}

//层序遍历

void levelOrder(treeNode* tree, queueNode* queue){

	enterQueue(queue , tree);

	while(!isEmptyQueue(queue)){

		queueNode* node = outQueue(queue);

		printf("%c ", node -> data -> data);

		if(node -> data -> lchild){
			enterQueue( queue, node -> data -> lchild);
		}

		if(node -> data -> rchild){
			enterQueue( queue, node -> data -> rchild);
		}
	}
}



int main(int argc, char* argv[]){

	/* code */

	int index = 0;

	treeNode* tree;

	queueNode* queue = initQueue();

	createTree(&tree, argv[1], &index);
	
	printf("先\n");
	preOrder(tree);
	printf("\n");
	printf("中\n");
	middleOrder(tree);
	printf("\n");
	printf("后\n");
	postOrder(tree);
	printf("\n");
	printf("层\n");
	levelOrder( tree , queue);
	printf("\n");

	return 0;
}











