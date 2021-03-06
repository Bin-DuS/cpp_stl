#include <iostream>
#include <test.h>
using std::cout;
using std::endl;
template <class T>
T min(T x, T y){
	return( x < y )? x : y;
}
int main(){
	int n1 = 2, n2 = 10;
	double d1 = 1.5,d2 = 5.6;
	cout << "较小整数：" << min(n1,n2) << endl;
	cout << "较小实数：" << min(d1,d2) << endl;
	myClass<int,int> class1(3,5);
	class1.show();
	myClass<int,char> class2(3,'a');
	class2.show();
	myClass<double,int> class3(2.9,10);
	class3.show();
	return 0;
}
