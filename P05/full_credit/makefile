CXXFLAGS = --std=c++17

store: main.o product.o taxed.o taxfree.o
	$(CXX) $(CXXFLAGS) main.o product.o taxed.o taxfree.o -o store

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

product.o: product.cpp
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o

taxed.o: taxed.cpp
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o

taxfree.o: taxfree.cpp
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o

clean:
	rm -f *.o *.gch a.out  coin
