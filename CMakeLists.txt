cmake_minimum_required(VERSION 2.8)#最低cmake版本
add_definitions("-lstdc++")# 增加编译选项
add_executable(cpp_stl #生成的可执行文件名称
	test.cpp #源代码
	src/speak.cpp
	src/test_vector.cpp
	src/test_stack_queue.cpp
	src/test_others.cpp
)