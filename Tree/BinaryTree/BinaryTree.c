#include <stdio.h>
#include <stdlib.h>


//定义二叉树节点结构

typedef struct treeNode{

	char data;
	struct treeNode* lchild;
	struct treeNode* rchild;

}treeNode;


//创建二叉树头结点
void createTree(treeNode** tree, char* data, int* index){

	char element = data[*index];
	*index += 1;
	
	if(element == '#'){

		*tree = NULL;
		
	}else{

		*tree = (treeNode*)malloc(sizeof(treeNode));

		(*tree) -> data = element;

		createTree(&(*tree) -> lchild, data, index);

		createTree(&(*tree) -> rchild, data, index);

	}
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


int main(int argc, char* argv[]){

	/* code */

	int index = 0;

	treeNode* tree;

	createTree(&tree, argv[1], &index);
	
	printf("先\n");
	preOrder(tree);
	printf("中\n");
	middleOrder(tree);
	printf("后\n");
	postOrder(tree);
	printf("\n");

	return 0;
}











