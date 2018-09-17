// Test_vector_begin.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;
int main(int argc, _TCHAR* argv[])
{
	cout << " hello world \n" << endl;
	vector<int> v(5);
	iota(v.begin(),v.end(),1);
	vector<int>::iterator It = v.begin();
	while(It != v.end())
		cout << *It++ << " ";
	cout << endl;
	It = v.begin()+2;
	cout << *It << endl;
	system("pause");
	return 0;
}

