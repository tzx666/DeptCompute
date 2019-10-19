#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
double cops(double x) {
	if (x == 0)
		return 1.0;
	//cout << x << " " << sin(x) << endl;
	return sin(x)/x;
}
int main() {
	DeptComputer compute;
	double res = compute.Gauss1(0, 1,  cops);
	double res1=compute.newtoncont(0, 1, 4, cops);
	cout << res <<" "<<res1<< endl;
}
