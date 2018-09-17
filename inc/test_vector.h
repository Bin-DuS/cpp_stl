#ifndef __TEST_STL_H__
#define __TEST_STL_H__
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;
class Test_vector{
	public:
		void Test_vector_constructors();
		void Test_vector_assign();
		void Test_vector_at();
		void Test_vector_back();
		void Test_vector_begin();
		void Test_vector_capacity();
		void Test_vector_clear();
		void Test_vector_empty();
		void Test_vector_end();
		void Test_vector_erase();
		void Test_vector_front();
};
template <class T>
class Print{
	public:
		void operator()(T& t){
			cout << t << " ";
		}
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