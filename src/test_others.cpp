#include "test_others.h"
#include <string.h>
#include <math.h>
using namespace std;
/*
 * slab的使用
 */
typedef class data{
	public:
		int i;
		char data[16];
}data;
void Test_others::Test_others_slab(){
	cout << "Test_others_slab"<<endl;
	gm_slab<data> slab;
	data *d = slab.alloc();
	d->i = 1;
	strcpy(d->data,"hello world");
	cout << "(d->i):" << d->i << " (d->data):" << d->data << endl; 
	slab.free(d);
	cout << "(d->i):" << d->i << " (d->data):" << d->data << endl;
	return;
}
/*
 * 继承的使用
 * C++的子类与孙子类都实现了虚函数时，孙子类的实现会覆盖掉子类的实现。
 * 继承的最主要的应用就是把不同的类放到一个数组中，然后遍历调用同名函数。
 */
void Test_others::Test_others_inherit(){
	cout << "Test_others_inherit"<<endl;
	string name = "C";
	Child child(name);
	name = "GC";
	GrandChild gchild(name);
	vector<Parent*> mlist;
	mlist.push_back(dynamic_cast<Parent*>(&child));
	mlist.push_back(dynamic_cast<Parent*>(&gchild));
	for(int i = 0; i < mlist.size();++i){
		mlist[i]->printName();
	}
	return;
}
/*
 * 结合着类的特性和类中一般成员函数，我们可以这样理解：类具有封装和信息隐藏的特性。只有类的成员函数才能访问类的私有
 * 成员，程序中的其他函数是无法访问私有成员的。非成员函数可以访问类中的公有成员，但是如果将数据成员都定义为公有的，
 * 这又破坏了隐藏的特性。另外，应该 看到在某些情况下，特别是在对某些成员函数多次调用时，由于参数传递，类型检查和安
 * 全性检查等都需要时间开销，而影响程序的运行效率。
 * 为了解决上述问题，提出一种使用友元的方案。友元是一种定义在类外部的普通函数，但它需要在类体内进行说明，
 * 为了与该类的成员函数加以区别，在说明时前面加以关键字friend。友元不是成员函数，但是它可以访问类中的私有成员。友元
 * 的 作用在于提高程序的运行效率，但是，它破坏了类的封装性和隐藏性，使得非成员函数可以访问类的私有成员。
 * 友元函数的特点是能够访问类中的私有成员的非成员函数。友元函数从语法上看，它与普通函数一样，即在定义上和调用上与普通函数一样.
*/
double Distance(Point &a, Point &b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx*dx+dy*dy);
}
void Point::Getxy(){
	cout << "(" << x << "," << y << ")" << endl;
}
/*
 * 友元的使用
 */
void Test_others::Test_others_firends(){
	cout << "Test_others_firends"<<endl;
	Point p1(3.0,4.0), p2(6.0,8.0);
	p1.Getxy();
	p2.Getxy();
	double d = Distance(p1,p2);
	cout << "Distance is " << d << endl;
	You you;
	d = you.Multi(p1);
	cout << "Math.Multi is " << d << endl;
	return;
}