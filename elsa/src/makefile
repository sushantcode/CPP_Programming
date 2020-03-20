CXXFLAGS = --std=c++17

test: test.o customer.o store.o options.o desktop.o
	$(CXX) $(CXXFLAGS) test.o customer.o store.o options.o desktop.o -o test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -c -o test.o

customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

store.o: store.cpp
	$(CXX) $(CXXFLAGS) store.cpp -c -o store.o

options.o: options.cpp
	$(CXX) $(CXXFLAGS) options.cpp -c -o options.o
	
desktop.o: desktop.cpp
	$(CXX) $(CXXFLAGS) desktop.cpp -c -o desktop.o
	
clean:
	rm -f *.o *.gch a.out test
