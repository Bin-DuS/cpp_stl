#include "test_stl.h"
using namespace std;
/*
 * vector 类似于数组，存放一组数据,数据可以重复
 * 使用iterator变量sIt作为游标，先赋值为begin(),
 * 循环到end()对所有元素遍历
 */
void Test_stl::Test_vector_constructors(){
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