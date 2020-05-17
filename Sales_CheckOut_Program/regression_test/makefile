CXXFLAGS = --std=c++17

test: test.o product.o taxed.o taxfree.o
	$(CXX) $(CXXFLAGS) test.o product.o taxed.o taxfree.o -o test

test.o: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -c -o test.o

product.o: product.cpp
	$(CXX) $(CXXFLAGS) product.cpp -c -o product.o

taxed.o: taxed.cpp
	$(CXX) $(CXXFLAGS) taxed.cpp -c -o taxed.o

taxfree.o: taxfree.cpp
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o

clean:
	rm -f *.o *.gch a.out test
