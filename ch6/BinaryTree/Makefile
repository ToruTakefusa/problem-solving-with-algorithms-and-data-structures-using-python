sample:sample.o my_binary_tree.o my_binary_heap.o
	g++ -Wall -o sample sample.o my_binary_tree.o my_binary_heap.o
my_binary_tree.o:my_binary_tree.cpp
	g++ -Wall -c my_binary_tree.cpp
sample.o:sample.cpp
	g++ -Wall -c sample.cpp
my_binary_heap.o:my_binary_heap.cpp
	g++ -Wall -c my_binary_heap.cpp
clean:
	rm -f *.o sample
