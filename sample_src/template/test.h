#ifndef __TEST_H__
#define __TEST_H__
#include <iostream>
using std::cout;
using std::endl;
template<typename T1,typename T2>
class myClass{
	private:
	T1 I;
	T2 J;
	public:
	myClass(T1 a,T2 b);//Constructor
	void show();
};
//构造函数
template <typename T1,typename T2>
myClass<T1,T2>::myClass(T1 a,T2 b):I(a),J(b){}
//show();
template <typename T1,typename T2>
void myClass<T1,T2>::show(){
	cout << "I=" << I << ", J=" << J << endl;
}
#endif

