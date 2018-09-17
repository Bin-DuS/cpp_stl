#include "test_vector.h"
using namespace std;
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