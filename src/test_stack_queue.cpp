#include "test_stack_queue.h"
using namespace std;
/*
 * priority_queue的使用,优先队列
 */
void Test_stack_queue::Test_priority_queue(){
	cout << "Test_priority_queue"<<endl;
	priority_queue<int,vector<int>,less<int> > ipq;
	ipq.push(100);
	ipq.push(200);
	ipq.push(300);
	cout << "size of priority_queue ipq = " << ipq.size() << endl;
	cout << "ipq<int,vector<int>,less<int> > = " << endl;
	while(!ipq.empty()){
		cout << ipq.top() << " ";
		ipq.pop();
	}
	cout << endl;
	cout << "priority_queue<string,vector<string> > spq;" << endl;
	priority_queue<string,vector<string> > spq;
	for(int i = 1; i < 10; i++){
		spq.push(string(i,'*'));
	}
	while(!spq.empty()){
		cout << spq.top() << endl;
		spq.pop();
	}
	return;
}
/*
 * queue的使用,队列
 */
void Test_stack_queue::Test_queue(){
	cout << "Test_queue"<<endl;
	string s1("C++");
	string s2("is");
	string s3("powerfull");
	string s4("language");
	queue<string> que;
	que.push(s1);
	que.push(s2);
	que.push(s3);
	que.push(s4);
	cout << "size of queue 'que' = "<< que.size() << endl;
	string temp = que.back();
	cout << temp << endl;
	while(!que.empty()){
		temp = que.front();
		cout << temp << " ";
		que.pop();
	}
	cout << endl;
	return;
}
/*
 * stack的使用,栈
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

