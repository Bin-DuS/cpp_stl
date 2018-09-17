#不能使用gcc
SRC=src
INC=inc
BIN=cpp_stl
obj=test.o speak.o test_vector.o test_stack_queue.o
COMFLAGS= -lstdc++
CFLAGS = -I $(INC)/
BIN:$(obj)
	g++ -o $(BIN) $(obj) 
test.o:
	g++ -c test.cpp $(CFLAGS)
speak.o:
	g++ -c $(SRC)/speak.cpp $(CFLAGS)
test_vector.o:
	g++ -c $(SRC)/test_vector.cpp $(CFLAGS)
test_stack_queue.o:
	g++ -c $(SRC)/test_stack_queue.cpp $(CFLAGS)
clean:
	rm -rf cpp_stl *.o