sample:	sample.o	my_stack.o
	g++ -Wall -o sample sample.o my_stack.o
my_stack.o:	my_stack.cpp
	g++ -Wall -c my_stack.cpp
sample.o: sample.cpp
	g++ -Wall -c sample.cpp
clean:
	rm -f *.o sample
