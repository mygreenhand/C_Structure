#include <iostream>
#include <thread>
#include <memory>

using namespace std;

//线程需要访问的是全局，不然会报错
// thread t;
// int a = 1;

// void foo(int& x){
//     x += 1;
// }

// void foo(int* x){
//     x += 1;
// }

// void test(){
//     int a = 1;
//     t = thread(foo,ref(a));
// }



// class MyClass{
//     public:
//     void foo(){
//         cout<<"Hello"<<endl;
//     }
// };

class MyClass{
    private:
    friend void thread_foo();
    void foo(){
        cout<<"Hello"<<endl;
    }
};

void thread_foo(){

    shared_ptr<MyClass> a = make_shared<MyClass>();//创建智能指针，如果a不在需要就会自己释放内存
    thread t(&MyClass::foo,a);
    t.join();
}


int main(){

    thread_foo();

    // shared_ptr<MyClass> a = make_shared<MyClass>();//创建智能指针，如果a不在需要就会自己释放内存
    // thread t(&MyClass::foo,a);
    
    //int a = 1;
    //ref可以把变量转化为自己的引用类型
    // thread t(foo,ref(a));
    // t.join();
    // cout<<a<<endl;

    //test();

    // int* ptr = new int(1);
    // thread t(foo,ptr);
    // delete ptr;

    //t.join();

    return 0;
}