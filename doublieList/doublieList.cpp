#include <iostream>
using namespace std;

typedef struct DNodeList
{
    /* data */

    int data;
    struct DNodeList *pre;
    struct DNodeList *next;

}Node;



Node* createList(){

    Node *s = (Node*)malloc(sizeof(Node));
    s -> pre = NULL;
    s -> next = NULL;
    s -> data = 0;

    return s;
}


void insertHeadList(Node *L,int num){

    Node *node = (Node*)malloc(sizeof(Node));

    node -> data = num;
    node -> next = L -> next;
    
    if(L -> next == NULL){
        node -> pre = L;
    }else{
        node -> pre = L -> next -> pre;
    }

    L -> next = node;


}


void insertTailList(Node *L,int num){

    Node *node = (Node*)malloc(sizeof(Node));

    node -> data = num;
    
    while(L -> next != NULL){
        L = L -> next;
    }

    node -> next = L -> next;
    L -> next = node;
    node -> pre = L;

}

void ergodicByValueBackward(Node *L,int num){

    Node *node = L -> next;

    while(node -> next != NULL){
        if(node -> data == num){
            break;
        }
        node = node -> next;
    }

    while(node != NULL){
        cout<<node -> data << "->";
        node = node -> next;
    }

    cout<<"完毕";

}


void ergodicByValueForward(Node *L,int num){

    Node *node = L -> next;

    while(node -> next != NULL){
        if(node -> data == num){
            break;
        }
        node = node -> next;
    }

    while(node -> data != 0){
        cout<<node -> data << "->";
        node = node -> pre;
    }

    cout<<"完毕";

}


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


void deleteByValue(Node *L,int num){

    while(L -> next != NULL){
        
        if(L -> data == num){

            break;
        }
        
        L = L -> next;
        
    }
    
    L -> pre -> next = L -> next;
    L -> next -> pre = L -> pre;

    free(L);

}


int main(){

    Node *L = createList();

    for(int i = 1; i < 10; i++){
        //insertHeadList(L,i);
        insertTailList(L,i);
    }

    //ergodicByValueBackward(L,5);
    ergodicByValueForward(L,5);
    cout<<endl;
    deleteByValue(L,4);
    cout<<endl;
    ergodicList(L);
    return 0;
}