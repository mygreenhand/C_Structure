#include <iostream>

using namespace std;

int main(){
    int b;
    cin>>b;

    while(b != 1){
        if(b % 2 == 0){
           b = b / 2;
        }else{
            b = b * 3 + 1;
        }
         cout<<b<<"  ";
    }
    return 0;
}