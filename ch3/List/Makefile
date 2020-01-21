sample:	sample.o	my_unordered_list.o my_ordered_list.o my_node.o
	g++ -Wall -o sample sample.o my_node.o my_unordered_list.o my_ordered_list.o
my_node.o:my_node.cpp
	g++ -Wall -c my_node.cpp
my_unordered_list.o:my_unordered_list.cpp
	g++ -Wall -c my_unordered_list.cpp
my_ordered_list.o:my_ordered_list.cpp
	g++ -Wall -c my_ordered_list.cpp
sample.o:sample.cpp
	g++ -Wall -c sample.cpp
clean:
	rm -f *.o sample
