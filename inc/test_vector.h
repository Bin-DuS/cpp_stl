#ifndef __TEST_STL_H__
#define __TEST_STL_H__
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
class Test_vector{
	public:
		void Test_vector_constructors();
		void Test_vector_assign();
		void Test_vector_at();
		void Test_vector_back();
};
 /*
  * 创建模板
  */
template<class T,class D>
class Member{
	public:
		Member(T t,D d):name(t),sal(d){}
		void print();
	private:
		T name;
		D sal;
};
#endif