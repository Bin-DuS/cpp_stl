#include "test_stack_queue.h"
using namespace std;
/*
 * stack的使用
 */
void Test_stack_queue::Test_stack(){
	cout << "Test_stack"<<endl;
	vector<int> v1(5), v2(5), v3(5);
	int ary[]={1,2,3,4,5,
			   6,7,8,9,10,
			   11,12,13,14,15};
	v1.assign(ary,ary+5);
	v2.assign(ary+6,ary+10);
	v3.assign(ary+11,ary+15);
	stack< vector<int> > s;
	s.push(v1);
	s.push(v2);
	s.push(v3);
	cout << "Size of stack's = " << s.size() << endl;
	if(v3 != v2){
		s.pop();
		cout << "v3 != v2" << endl;
	}
	cout << "Size of stack's = " << s.size() << endl;
	vector<int> top = s.top();
	cout << "Contents of v2:" << endl;
	copy(top.begin(),top.end(),ostream_iterator<int>(cout," "));
	cout << endl;
	while(!s.empty())
		s.pop();
	cout << "Stack's is " << (s.empty() ? " ":"not") << "empty" << endl;
	return;
}

