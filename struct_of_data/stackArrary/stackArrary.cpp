#include <iostream>

using namespace std;

const int MAXNUM = 500;

typedef struct stackNode
{
    /* data */

    int dataArr[MAXNUM];
    int top;

}Stack;


void createStack(Stack &s){

    s.top = -1;
}

//对栈进行判满
int isFull(Stack s){

    if(s.top >= MAXNUM - 1)
        return 1;
    else
        return 0;

}

//对栈进行判空
int isEmpty(Stack s){

    if(s.top == -1)
        return 1;
    else 
        return 0;

}

//入栈
void push(Stack &s,int num){

    if(isFull(s)){

        cout<<"栈已经满了"<<endl;

        return ;
    }

    //入栈
    s.dataArr[++s.top] = num; 

}


//出栈
void pop(Stack &s){

    if(isEmpty(s)){

        cout<<"栈已经空了"<<endl;
        return;
    }

    //出栈
    s.dataArr[s.top--];

}

void printStack(Stack s){

    if(isEmpty(s)) 
        return;
    
    for(int i = 0; i <= s.top; i++){
        cout<<"栈的第"<<i+1<<"数是："<<s.dataArr[i]<<endl;
    }

}


void topStack(Stack s){

    if(isEmpty(s)){
        cout<<1<<endl;
        return;
    }

    cout<<"栈顶数是"<<s.dataArr[s.top]<<endl;
}


int main(){

    Stack s;

    createStack(s);

    for(int i = 1; i <= 10;i++){

        push(s,i);

    }

    printStack(s);

    pop(s);
    pop(s);
    printStack(s);
    
    return 0;
}