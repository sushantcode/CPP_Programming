CXXFLAGS = --std=c++17

store: test.o product.o taxed.o taxfree.o
	$(CXX) $(CXXFLAGS) test.o product.o taxed.o taxfree.o -o test

main.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

product.o: product.cpp
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o

taxed.o: taxed.cpp
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o

taxfree.o: taxfree.cpp
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o

clean:
	rm -f *.o *.gch a.out test
