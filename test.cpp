/*main cpp*/
#include <iostream>
#include "speak.h"
#include "test_vector.h"
using namespace std;
int main(){
	//cout<<"hello world"<<endl;
	Speak speak;
	//speak.sayHello("world");
	Test_vector test_vector;
	//test_vector.Test_vector_constructors();
	//test_vector.Test_vector_assign();
	//test_vector.Test_vector_at();
	test_vector.Test_vector_back();
	cout<<"test end"<<endl;
	return 0;
}