#include<iostream>
#include<vector>
#include<Compute.h>
using namespace std;
/*
class DeptComputer{
//长期数值方法计算集合类
public:int multinomialReduction(vector<int> q,int x);
       int multinomialReduction(int w[],int size,int x);
       //多项式化简迭代：y=ax^n+an-1^x^n-1...
       //先计算v=an,计算anx+b,v=aix+b
       //原计算次数为n^2次，经过迭代变为n次乘法，时间复杂度变小
       double SquareBoot(double a);
       //迭代法求开方值，设定固定迭代初值a0
private:int v,b;
};
int DeptComputer::multinomialReduction(vector<int>q,int x){
    int v=q[0],b;
    for(int i=1;i<q.size();i++){
        v=v*x+q[i];
    }
    return v;
}
int DeptComputer::multinomialReduction(int w[],int size,int x){
    int v=w[0],b;
    for(int i=1;i<size;i++){
        v=v*x+w[i];
    }
    return v;
}
double DeptComputer::SquareBoot(double a){
    double x0=1.0;
    double x1=0.5*(x0+a/x0);
    while(abs(x1-x0)>1e-6){
        x0=x1;
        x1=0.5*(x0+a/x0);
    }
    return x0;
}*/
int main(){
    DeptComputer d;
    cout<<d.SquareBoot(5)<<endl;
    return 0;
}