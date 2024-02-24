#include <iostream>
using namespace std;

// int main(int argc, char const *argv[])
// {
//     /* code */

//     cout<<"我的名字是杰克";

//     return 0;
// }

typedef struct ListNode
{
    /* data */

    int data;
    struct ListNode *next;
    
}Node;


Node* createList(){

    Node *s = (Node*)malloc(sizeof(Node)); 
    s -> data = 0;
    s -> next = NULL;


    return s;
}

void insertHeadList(Node *L,int num){


    Node *node = (Node*)malloc(sizeof(Node));

    node -> data = num;
        
    node -> next = L -> next;
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
    
}

void deleteByValue(Node *L,int num){

    Node *node = L -> next;
    Node *q;
    while(node -> next != NULL){
        
        if(node -> data == num){

            break;
        }

        q = node;
        node = node -> next;
        
    }

    q -> next = node -> next;

    free(node);

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



int main(){

    Node *node = createList();

    for(int i = 1; i < 10; i++){
        insertHeadList(node,i);
        //insertTailList(node,i);
    }

    ergodicList(node);
    cout<<endl;
    deleteByValue(node,4);
    cout<<endl;
    ergodicList(node);
    return 0;
    
}







