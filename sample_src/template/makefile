#不能使用gcc
BIN=cpp_template
obj=test.o
COMFLAGS= -lstdc++
BIN:$(obj)
	g++ -o $(BIN) $(obj) 
test.o:
	g++ -c test.cpp
clean:
	rm -rf cpp_template *.o