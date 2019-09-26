#include<vector>
using namespace std;
#ifndef Compute_H
#define Compute_H
class DeptComputer{
//长期数值方法计算集合类
public:int multinomialReduction(vector<int> q,int x);
       int multinomialReduction(int w[],int size,int x);
       //多项式化简迭代：y=ax^n+an-1^x^n-1...
       //先计算v=an,计算anx+b,v=aix+b
       //原计算次数为n^2次，经过迭代变为n次乘法，时间复杂度变小
       double SquareBoot(double a);
       //迭代法求开方值，设定固定迭代初值a0
       double ranglari(double X,vector<double>Xi,vector<double>Yi);//迭代计算拉格朗日插值并估计x值
	   double newtion(double X,vector<double>Xi,vector<double>Yi); //牛顿插值计算估计值 
private:int v,b;
};
#endif
