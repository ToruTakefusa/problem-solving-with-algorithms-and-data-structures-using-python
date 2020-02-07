sample:	sample.o my_binary_search.o
	g++ -Wall -o sample sample.o my_binary_search.o
sample.o: sample.cpp
	g++ -Wall -c sample.cpp
my_binary_search.o:	my_binary_search.cpp
	g++ -Wall -c my_binary_search.cpp
clean:
	rm -f *.o sample
