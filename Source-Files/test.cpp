#include<iostream>
#include<vector>
#include<cmath>
#include<Compute.h>
using namespace std;
double computs(double t){
	return sqrt(t);
}
int main(){
    DeptComputer d;
    cout<<d.newtoncont(0.5,1,4,computs)<<endl;
    return 0;
}