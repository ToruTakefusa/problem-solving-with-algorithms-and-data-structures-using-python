sample:	sample.o	my_queue.o
	g++ -Wall -o sample sample.o my_queue.o
my_queue.o:my_queue.cpp
	g++ -Wall -c my_queue.cpp
sample.o:sample.cpp
	g++ -Wall -c sample.cpp
clean:
	rm -f *.o sample
