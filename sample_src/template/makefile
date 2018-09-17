#不能使用gcc
BIN=cpp_template
obj=test.o
COMFLAGS= -lstdc++
CFLAGS = -I .
BIN:$(obj)
	g++ -o $(BIN) $(obj) 
test.o:
	g++ -c test.cpp $(CFLAGS)
clean:
	rm -rf cpp_template *.o