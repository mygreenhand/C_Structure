#include <iostream>

using namespace std;

#define MAXVLAUE 999
#define MAXARR 100

typedef char VertexType;
typedef int SideType;

typedef struct Grap
{
    VertexType vertex[MAXARR];     //顶点的数组
    SideType side[MAXARR][MAXARR]; //边的数组，一个顶点到另一个顶点，也有另一个到这个顶点
    int vertexNum,sideNum;          //顶点和边的总数
}MyGrap;


//进行顶点的索引，顶点是否存在
int location(MyGrap g, VertexType v){

    for(int i = 0; i < g.vertexNum; i++){
        if(g.vertex[i] == v)
            return i;
    }

    return -1;
}

//初始化图
void create_my_grap(MyGrap &g){
    cout<<"请输入顶点总数: ";
    cin>>g.vertexNum;
    cout<<"请输入边总数：";
    cin>>g.sideNum;

    cout<<"输入各个顶点：";
    for(int i = 0; i < g.vertexNum; i++){
        cin>>g.vertex[i]; 
    }

    for(int i = 0; i < g.vertexNum; i++){
        for(int j = 0; j < g.vertexNum; j++){
            g.side[i][j] = MAXVLAUE;
        }
    }

    VertexType strat,end;

    for(int i = 0; i < g.sideNum; i ++){

        cout<<"输入第"<<i+1<<"条边的起点：";
        cin>>strat;

        cout<<"输入第"<<i+1<<"条边的终点：";
        cin>>end;

        //利用location函数获取到从那个点到那个点
        int strat_int = location(g,strat);
        int end_int = location(g,end);

        cout<<"输入第"<<i+1<<"条边的权值：";
        cin>>g.side[strat_int][end_int];

    }

}

//测试函数
void TestFun(MyGrap g){
    cout<<"邻接矩阵如下："<<endl;

    for(int i = 0; i < g.vertexNum; i++){
        for(int j = 0; j < g.vertexNum; j++){
            cout<<g.side[i][j]<<"\t ";
        }
        cout<<endl;
    }
}

int main()
{
    MyGrap* g = new MyGrap;
    create_my_grap(*g);
    TestFun(*g);
    delete g;
    return 0;
}
