#include <iostream>

#include <pthread.h>//线程头文件

using namespace std;

#define MAX_PTHREAD 5

void* say_hello(void* args){
    cout<<"pthread hello"<<endl;
    return 0;
}


int main(){

    pthread_t tids[MAX_PTHREAD];

    for(int i = 0; i < MAX_PTHREAD; ++i){

        int ref = pthread_create(&tids[i],NULL,say_hello,NULL);

        if(ref != 0){
            cout << "pthread_create error: error_code=" << ref << endl;
        }

    }
    
    pthread_exit(NULL);
    return 0;
}