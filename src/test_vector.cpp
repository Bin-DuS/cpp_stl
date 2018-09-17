#include "test_vector.h"
//#include <numeric>
using namespace std;
/*
 * front的使用
 */
void Test_vector::Test_vector_front(){
	cout << "Test_vector_front"<<endl;
	typedef Member<string,double>M;
	vector<M> v;
	v.push_back(M("Linda",75000));
	v.push_back(M("Robert",60000));
	vector<M>::iterator It = v.begin();
	cout << "Entire vector:" << endl;
	while( It != v.end())
		(It++)->print();
	cout << endl;
	cout << "Return from front()" << endl;
	v.front().print();
	return;
}
/*
 * erase的使用
 * 移除定位到的元素，
 * 两种使用方法
 *	   一个参数，移除指定的数据 
 *     两个参数 由第一个参数到第二个参数（不包含第二个参数）均移除
 */
void Test_vector::Test_vector_erase(){
	cout << "Test_vector_erase"<<endl;
	vector<int> v(10);
	vector<int>::iterator It;
	for(int i = 0;i < 10; i++){
		v[i] = i + 1;
	}
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	It = v.begin() + 2;
	v.erase(It);
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	It = v.begin();
	v.erase(It,It + 2);
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	return;
}
/*
 * end的使用
 */
void Test_vector::Test_vector_end(){
	cout << "Test_vector_end"<<endl;
	int ary[]={1,2,3,4,5};
	vector<int> v(5);
	v.assign(ary,ary+5);
	//iota(v.begin(), v.end(), 2); //linux不支持iota
	vector<int>::iterator It =  v.begin();
	while(It != v.end())
		cout << *It++ << " ";
	cout << endl;
	It = v.end()-2;
	cout << *It << endl;
	return;
}
/*
 * empty的使用
 */
void Test_vector::Test_vector_empty(){
	cout << "Test_vector_empty"<<endl;
	vector<int> v;
	cout << "Vector is ";
	v.empty() ? cout << "":cout << "not ";
	cout << "empty" << endl;
	v.push_back(100);
	cout << "After push_back:" << endl;
	cout << "Vector is ";
	v.empty() ? cout << "":cout << "not ";
	cout << "empty" << endl;
	return;
}
/*
 * clear的使用
 */
void Test_vector::Test_vector_clear(){
	cout << "Test_vector_clear"<<endl;
	vector<int> v(10);
	Print<int> print;
	fill(v.begin(),v.end(),5);
	cout << "Vector v: ";
	for_each(v.begin(),v.end(),print);
	cout << endl;
	cout << "Size of v = " << v.size() << endl;
	cout << "v.clear" << endl;
	v.clear();
	cout << "Vector v: ";
	for_each(v.begin(),v.end(),print);
	cout << endl;
	cout << "Size of v = " << v.size() << endl;
	v.empty()?cout << "":cout << "not ";
	cout << "empty" << endl;
	return;
}
/*
 * capacity的使用
 * size是当前vector容器真实占用的大小，也就是容器当前拥有多少个容器。
 * capacity是指在发生realloc前能允许的最大元素数，即预分配的内存空间。
 * 当然，这两个属性分别对应两个方法：resize()和reserve()。
 * 使用resize()，容器内的对象内存空间是真正存在的。
 * 使用reserve()仅仅只是修改了capacity的值，容器内的对象并没有真实的内存空间(空间是"野"的)。
 * 此时切记使用[]操作符访问容器内的对象，很可能出现数组越界的问题。
 */
void Test_vector::Test_vector_capacity(){
	cout << "Test_vector_capacity"<<endl;
	vector<int> v(10);
	cout << "Size of v = " << v.size() << endl;
	cout << "Capacity of v = " << v.capacity() << endl;
	v.resize(20);
	cout << "After resizing: " << endl;
	cout << "Size of v = " << v.size() << endl;
	cout << "Capacity of v = " << v.capacity() << endl;
	v.reserve(30);
	v.push_back(0);
	cout << "After reserving: " << endl;
	cout << "Size of v = " << v.size() << endl;
	cout << "Capacity of v = " << v.capacity() << endl;
	return;
}
/*
 * begin的使用
 */
void Test_vector::Test_vector_begin(){
	cout << "Test_vector_begin"<<endl;
	int ary[]={1,2,3,4,5};
	vector<int> v(5);
	v.assign(ary,ary+5);
	//iota(v.begin(), v.end(), 2); //linux不支持iota
	vector<int>::iterator It =  v.begin();
	while(It != v.end())
		cout << *It++ << " ";
	cout << endl;
	It = v.begin()+2;
	cout << *It << endl;
	return;
}
/*
 * back的使用
 */
template<class T,class D>
 void Member<T,D>::print(){ //文档中为 void Member::print() 是不正确的
	 cout << name << " " << sal << endl;
 }
void Test_vector::Test_vector_back(){
	cout << "Test_vector_back"<<endl;
	typedef Member<string,double>M;
	vector<M> v;
	v.push_back(M("Robert",60000));
	v.push_back(M("Linda",75000));
	vector<M>::iterator It = v.begin();
	cout <<"Entire vector: "<<endl;
	while(It != v.end()){
		(It++)->print();
	}
	cout << endl;
	cout << "Return from back()" << endl;
	v.back().print();
	return;
}
/*
 * at的使用
 * at 定位到指定的下标元素，和v[i]类似
 */
void Test_vector::Test_vector_at(){
	cout << "Test_vector_at"<<endl;
	vector<int> v(3,0);//3个0
	v[0] = 100;// v[0]赋值为100
	v.at(1) = 200;//v[1]赋值为200
	vector<int>::iterator iIt = v.begin();
	while(iIt != v.end())
		cout <<*iIt++<<" ";
	cout << endl;
	for(int i = 0;i<3;i++){
		cout << v[i] << " ";
	}
	cout<<endl;
	return;
}
/*
 * assign的使用
 */
void Test_vector::Test_vector_assign(){
	cout << "Test_vector_assign"<<endl;
	int ary[]={1,2,3,4,5};
	vector<int> v;
	v.assign(ary,ary+5);//相当于拷贝函数，把first到last的值赋值给调用者v
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	v.assign(3,100);//把3(n)个100(x)赋值给调用者(v)
	copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	return;
}
/*
 * vector 类似于数组，存放一组数据,数据可以重复
 * 使用iterator变量sIt作为游标，先赋值为begin(),
 * 循环到end()对所有元素遍历
 */
void Test_vector::Test_vector_constructors(){
	cout << "Test_vector_constructors"<<endl;
	string str[] = {"Alex","John","Robert","John"};
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10,0);
	vector<string> v4(str+0,str+4);
	vector<string>::iterator sIt = v4.begin();
	while(sIt != v4.end())
		cout <<*sIt++<<" ";
	cout << endl;
	vector<string> v5(v4);
	for(int i = 0;i<4;i++){
		cout <<v5[i]<<" ";
	}
	cout<<endl;
	return;
}