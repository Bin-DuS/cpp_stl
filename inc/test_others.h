#ifndef __TEST_OTHERS_H__
#define __TEST_OTHERS_H__
#include <iostream>
using namespace std;
class Test_others{
	public:
		void Test_others_firends();
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