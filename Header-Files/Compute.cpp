#include<Compute.h>
#include<cmath>
#include<iostream>
using namespace std;
 
DeptComputer::DeptComputer(){

}
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
double DeptComputer::ranglari(double X,vector<double>Xi,vector<double>Yi){
	double y=0;
	double t=1;
	for(int i=0;i<Xi.size();i++){
		for(int j=0;j<Xi.size();j++){
			if(i!=j){
				double t1=X-Xi[j];
				double t2=Xi[i]-Xi[j];
				t=t*(t1/t2);
			}
		}
		y=y+Yi[i]*t;
		t=1;
	}
	return y;	
}
double DeptComputer::newtion(double X,vector<double>Xi,vector<double>Yi){
	int n1;
	n1=Xi.size();
	//使用牛顿插值法
	//double val[100][100];
	vector<vector<double> >val(n1,vector<double>());
	for(int i=0;i<n1;i++)
	val[i].resize((n1));
	for(int i=0;i<n1;i++)
		for(int j=0;j<n1;j++)
			val[i][j]=0;
	for(int i=0;i<n1;i++)
	val[i][0]=Yi[i];	
	for(int i=1;i<n1;i++)
		for(int j=i;j<n1;j++)
			val[j][i]=(val[j][i-1]-val[j-1][i-1])/(Xi[j]-Xi[j-i]);
	//计算k阶差分函数，从f（x)到f(x1..xn)
	/*for(int i=0;i<n1;i++){
		for(int j=0;j<n1;j++)
		cout<<val[i][j]<<" ";
		cout<<endl;
	}*/
	double t=Yi[0];
	double y;
	for(int i=1;i<n1;i++){
		y=1;
		for(int j=0;j<i;j++){
			y=y*(X-Xi[j]);
			//cout<<y<<endl;
		}
		t=t+y*val[i][i];
		//cout<<t<<endl;
	}
	//根据差分值和已知x带入多项式预测结果	
	return t;
}
double DeptComputer::newtoncont(double a,double b,int n,double (*comp1)(double)){
	double C0[5][7]={
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
	//假设函数为y=sqrt(x) 
	double t=(b-a)*1.0/n;//步长
	double res=b-a;
	double count=a;
	double mres=0;
	for(int i=0;i<=n;i++){
		if(i>0)
		count=count+t;
		cout<<count<<endl;
	double size=C0[n-1][0];//分母 
			mres+=(((C0[n-1][i+1]*1.0))/size)*(comp1(count));
	}
	return res*mres;
}
