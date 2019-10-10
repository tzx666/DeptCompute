#include<vector>
using namespace std;
#ifndef Compute_H
#define Compute_H
class DeptComputer{
//长期数值方法计算集合类
public:	static const double C0[5][7];
		DeptComputer();
		int multinomialReduction(vector<int> q,int x);
       int multinomialReduction(int w[],int size,int x);
       //多项式化简迭代：y=ax^n+an-1^x^n-1...
       //先计算v=an,计算anx+b,v=aix+b
       //原计算次数为n^2次，经过迭代变为n次乘法，时间复杂度变小
       double SquareBoot(double a);
       //迭代法求开方值，设定固定迭代初值a0
       double ranglari(double X,vector<double>Xi,vector<double>Yi);//迭代计算拉格朗日插值并估计x值
	   double newtion(double X,vector<double>Xi,vector<double>Yi); //牛顿插值计算估计值 
	   double newtoncont(double x,double y,int n);//牛顿积分计算 
private:int v,b;
};

const double DeptComputer::C0[5][7]={
			{
			2,1,1
			},
			{
			6,1,4,1
			},
			{
			8,1,3,3,1	
			},
			{
			90,7,32,12,32,7	
			},
			{
			288,19,100,50,50,100,19	
			} 
};
#endif