CXXFLAGS = --std=c++17

store: main.o product.o taxed.o taxfree.o
	$(CXX) $(CXXFLAGS) main.o product.o taxed.o taxfree.o -o store

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

product.o: product.cpp
	$(CXX) $(CXXFLAGS) product.cpp -c -o product.o

taxed.o: taxed.cpp
	$(CXX) $(CXXFLAGS) taxed.cpp -c -o taxed.o

taxfree.o: taxfree.cpp
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o

clean:
	rm -f *.o *.gch a.out store
