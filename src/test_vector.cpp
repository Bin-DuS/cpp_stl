#include "test_vector.h"
using namespace std;
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