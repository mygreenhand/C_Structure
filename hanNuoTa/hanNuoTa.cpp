#include <iostream>
 using namespace std;
 
 void move(char a,int n,char c)
{
    cout<<a<<"->"<<c<<endl; // 打印移动步骤
  }
  
  void hanoi(int n,char a,char b,char c)
{
    
    if(n==1){// n==1 递归的出口
      move(a,1,c);
    }else{
      hanoi(n-1,a,c,b);
      move(a,n,c);
      hanoi(n-1,b,a,c); 
    }
 }
  
  
int main()
{
    int n;
    cin>>n;
    hanoi(n,'a','b','c');
    return 0;
  }