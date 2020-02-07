sample: sample.o my_sequential_search.o
	g++ -Wall -o sample sample.o my_sequential_search.o
my_sequential_search.o:my_sequential_search.cpp
	g++ -Wall -c my_sequential_search.cpp
clean:
	rm -f *.o sample
