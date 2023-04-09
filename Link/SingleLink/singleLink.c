#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0


//定义链表结构
typedef struct Node{
    int data;
    struct Node* next;

} Node;


//是否为空链表
int isEmptyLink(Node* link){
    if(link -> data == 0){
        return 1;
    }
    return 0;
}

//初始化头结点
Node* initLink(){
    Node* head = (Node*)malloc(sizeof(Node));
    head -> data = 0;
    head -> next = NULL;
    return head;
}

//进行链表的头插法
void headInsertNode(Node* link,int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = link -> next;
    link -> next = node;
    link -> data ++ ;
}

//进行链表的尾插法
void tailInsertNode(Node* link,int data){
    Node* first = link;
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    if(!(link -> next == NULL)){
        link = link -> next;
    }
    while(link -> next){
        link = link -> next;
    }
    link -> next = node;
    first -> data ++;
}

//删除对应值得节点
int deleteNode(Node* link, int data){
    Node* pre = link;
    Node* current = link -> next;
    while(current){
        if(current -> data == data){
            pre -> next = current -> next;
            free(current);
            return TRUE;
        }
        pre = current;
        current = current -> next;
    }
    link -> data --;

    return FALSE；
}

//遍历整个链表节点
void printNode(Node* link){
    link = link -> next;
    while(link){
        printf("%d ",link -> data);
        link = link -> next;
    }
    printf("\n");
}

//按照值查找节点
void findNode(Node* link,int data){
    if(isEmptyLink(link) != 1){
        link = link -> next;
        while(link){
            if(link -> data == data){
                printf("%d ",link -> data);
                printf("\n");
                break;
            }
            link = link -> next;
        }
        if(link == NULL)
            printf("未找到\n");
    }else{
        printf("链表为空\n");
    }
   
}


//主函数
int main(){
    Node* link = initLink();
    
    // int i;
    // for(i = 1; i <= 20; i++){
    //     //headInsetNode(link,i);
    //     tailInsertNode(link,i); 
    // }
    
    printNode(link);
    findNode(link, 10);
    return 0;

}







