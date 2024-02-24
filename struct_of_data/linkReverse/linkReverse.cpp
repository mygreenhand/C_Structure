#include <iostream>

using namespace std;

//定义链表
typedef struct List
{
    /* data */
    int data;
    struct List *next;

}Node;

//创建链表
Node* createList(){

    Node *s = (Node*)malloc(sizeof(Node)); 
    s -> data = 0;
    s -> next = NULL;


    return s;
}


//头插法入链表
void insertHeadList(Node *L,int num){


    Node *node = (Node*)malloc(sizeof(Node));

    node -> data = num;
        
    node -> next = L -> next;
    L -> next = node;
    
}


//遍历链表
void ergodicList(Node *L){

    int count = 0;
    

    if(L->next == NULL){
        cout<<count;
    }

    while(L->next != NULL){

        cout<<L -> next -> data <<" -> ";
        L = L -> next;
        count++;
    }

    cout<<"共"<<count<<"完毕";

}


//链表反转
Node* reverseLink(Node *L){

    //如果链表为空，或者链表只有一个数值，那么就直接返回
    if(L->next == nullptr || L->next->next == nullptr){
        return L;
    }

    //定义一个新指针来接收链表头
    Node *head = L;

    //定义一个新指针来接收前一个指针
    Node *pre = nullptr;

    //定义一个新指针来接收第一个数据
    Node *now = L->next;

    //如果指针不为空则继续反转
    while (now !=nullptr) {

        //定义辅助指针接收链表第一个指针
        Node *temp = now -> next;

        //类似尾插法
        now -> next = pre;

        //将前一个指针往后面移动一个
        pre = now;

        //将当前指针往后移动
        now = temp;

    }
    
    //将新的指针放到新的指针接收
    head -> next = pre;

    //返回反转的链表
    return head;
}

int main(){

    Node *node = createList();

    for(int i = 1; i < 10; i++){
        insertHeadList(node,i);
        //insertTailList(node,i);
    }

    ergodicList(node);

    node = reverseLink(node);

    ergodicList(node);

    return 0;
}