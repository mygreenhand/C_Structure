#include <iostream>

using namespace std;

//创建链栈结构体
typedef struct sLink
{
    /* data */
    int data;
    sLink *top; //将后面的top想成next就一目了然
}Link;

//初始化链栈头节点
Link* createSLink(){

    Link* s  = (Link*)malloc(sizeof(Link));
    s -> data = 0;
    s -> top = nullptr;

    return s;
}

//判空，链栈不需要判满
bool isEmpty(Link *s){
    if(s -> top == nullptr)
        return true;
    else
        return false;
}

//入链栈
void push(Link *s,int num){

    Link *node = (Link*)malloc(sizeof(Link));

    node -> data = num;
    node -> top = s -> top;
    s -> top = node;
    
}

//出链栈
void pop(Link *s){
    if(isEmpty(s))
        return;

    Link * p = s -> top;
    
    cout<<"栈顶出战数为："<<p->data<<endl;

    s -> top = p -> top;
    
    free(p);
}

//遍历链栈
void printStack(Link *s){

    Link* p = s -> top;

    while (p != nullptr){
        /* code */
        cout<<p -> data<<endl;

        p = p -> top;
    }

}


int main(){

    Link* s = createSLink();

    for (int i = 1; i <= 10; i++)
    {
        /* code */
        push(s,i);
    }
    
    printStack(s);

    pop(s);
    pop(s);

    printStack(s);

    return 0;
}