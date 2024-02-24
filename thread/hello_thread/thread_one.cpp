#include <iostream>
#include <thread>
#include <string>

using namespace std;

void printHelloWorld(string msg){

    cout<<msg<<endl;

    return;
}



int main()
{
    
    //创建线程
    thread threadl (printHelloWorld,"Hello C++");

    //等待线程结束，join是阻塞的，只有线程完成后才会全部退出
    //threadl.join();

    //分离主从线程
    //threadl.detach();

    //判断线程是否能够被调用,join或者detach，如果不判断就会出现系统错误
    bool isJoin = threadl.joinable();

    if(isJoin){
        threadl.join();
    }

    return 0;
}
