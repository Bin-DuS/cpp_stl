#不能使用gcc
SRC=src
INC=inc
BIN=cpp_stl
obj=test.o speak.o test_stl.o
COMFLAGS= -lstdc++
CFLAGS = -I $(INC)/
BIN:$(obj)
	g++ -o $(BIN) $(obj) 
test.o:
	g++ -c test.cpp $(CFLAGS)
speak.o:
	g++ -c $(SRC)/speak.cpp $(CFLAGS)
test_stl.o:
	g++ -c $(SRC)/test_stl.cpp $(CFLAGS)
clean:
	rm -rf cpp_stl *.o