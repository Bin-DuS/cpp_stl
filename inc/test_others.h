#ifndef __TEST_OTHERS_H__
#define __TEST_OTHERS_H__
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Parent{
	protected:
		string pname;
	public:
		Parent(string name){
			pname = name;
		}
		virtual void printName(){};
};
class Child: public Parent{
	protected:
		string cname;
	public:
		Child(string name):Parent(name){
			cname = name;
		}
		virtual void printName(){
			cout << "This is child, cname is " << cname << ",pname is " << pname << endl;
		}
};
class GrandChild :public Child{
	private:
		string gname;
	public:
		GrandChild(string name):Child(name){
			gname = name;
		}
		virtual void printName(){
			cout << "This is grandchild, gname is " << gname << ", cname is " << cname << ", pname is " << pname << endl;
		}
};
class Test_others{
	public:
		void Test_others_firends();
		void Test_others_inherit();
};
class Point{
	public:
		Point(double xx,double yy){
			x = xx;
			y = yy;
		}
		void Getxy();
		friend double Distance(Point &a,Point &b);
		friend class You; //类Point的友元类
	private:
		double x,y;
};
class You{
	public:
		double Multi(Point &a){
			return a.x * a.y +1;
		}
};
#endif