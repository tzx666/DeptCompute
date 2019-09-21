#include<Compute.h>
#include<cmath>
using namespace std;
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
}