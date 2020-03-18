CXXFLAGS = --std=c++17

test: test.o customer.o 
	$(CXX) $(CXXFLAGS) test.o customert.o -o test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -c -o test.o

customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

clean:
	rm -f *.o *.gch a.out store
