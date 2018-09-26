cc_library(
	name = "src",
	srcs = [		
		"src/speak.cpp",
		"src/test_others.cpp",
		"src/test_stack_queue.cpp",
		"src/test_vector.cpp"
	],
	hdrs = [
		"inc/simple_list.h",
		"inc/speak.h",
		"inc/test_others.h",
		"inc/test_stack_queue.h",
		"inc/test_vector.h"
	]
)
cc_binary(
	name = "cpp_stl",
	srcs = [
		"test.cpp",
	],
	deps = [
		":src"
	]
	
)