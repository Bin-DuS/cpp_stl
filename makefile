BIN=cpp_stl
obj=test.o
BIN:$(obj)
	#不能使用gcc
	g++ -o $(BIN) $(obj)
test.o:
	g++ -c test.cpp
clean:
	rm -rf cpp_stl test.o