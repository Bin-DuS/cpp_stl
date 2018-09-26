/*main cpp*/
#include <iostream>
#include "./inc/speak.h"
#include "./inc/test_vector.h"
#include "./inc/test_stack_queue.h"
#include "./inc/test_others.h"
using namespace std;
int main(){
	//cout<<"hello world"<<endl;
	Speak speak;
	//speak.sayHello("world");
	Test_vector test_vector;
	//test_vector.Test_vector_constructors();
	//test_vector.Test_vector_assign();
	//test_vector.Test_vector_at();
	//test_vector.Test_vector_back();
	//test_vector.Test_vector_begin();
	//test_vector.Test_vector_capacity();
	//test_vector.Test_vector_clear();
	//test_vector.Test_vector_empty();
	//test_vector.Test_vector_end();
	//test_vector.Test_vector_erase();
	//test_vector.Test_vector_front();
	//test_vector.Test_vector_insert();
	//test_vector.Test_vector_max_size();
	//Test_stack_queue test_stack_queue;
	//test_stack_queue.Test_stack();
	//test_stack_queue.Test_queue();
	//test_stack_queue.Test_priority_queue();
	Test_others test_others;
	//test_others.Test_others_firends();//友元
	//test_others.Test_others_inherit();//继承
	//test_others.Test_others_slab();
	test_others.Test_others_dijkstra();
	cout<<"test end"<<endl;
	return 0;
}