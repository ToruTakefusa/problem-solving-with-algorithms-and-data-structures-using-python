sample: sample.o my_hash_table.o
	g++ -Wall -o sample sample.o my_hash_table.o
sample.o:	sample.cpp
	g++ -Wall -c sample.cpp
my_hash_table.o: my_hash_table.cpp
	g++ -Wall -c my_hash_table.cpp
clean:
	rm -f *.o sample
