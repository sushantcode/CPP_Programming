CXXFLAGS = --std=c++17

test: test.o customer.o store.o
	$(CXX) $(CXXFLAGS) test.o customer.o store.o -o test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -c -o test.o

customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

store.o: store.cpp
	$(CXX) $(CXXFLAGS) store.cpp -c -o store.o
	
clean:
	rm -f *.o *.gch a.out test
