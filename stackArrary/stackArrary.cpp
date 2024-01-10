#include <iostream>

using namespace std;

#define MAXNUM 500

typedef struct stackNode
{
    /* data */

    int dataArr[MAXNUM];
    int top;

}Stack;


Stack* createStack(){

    Stack node;
    node.top = -1;

    return node;
}


bool insertStack(Stack *node){



}



int main(){





    return 0;
}