#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

//互斥锁
mutex mut;
int a = 0;

void func(){
    for(int i = 0; i < 10000; i++){

        //加锁
        mut.lock();
        a += 1;
        //解锁
        mut.unlock();
    }
}

int main(){

    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();

    cout<<a<<endl;

    return 0;
}