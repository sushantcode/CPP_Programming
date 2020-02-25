CXXFLAGS = --std=c++17

store: store.o product.o taxed.o taxfree.o
	$(CXX) $(CXXFLAGS) store.o product.o taxed.o taxfree.o -o store

main.o: store.cpp
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o

product.o: product.cpp
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o

taxed.o: taxed.cpp
	$(CXX) $(CXXFLAGS) -c taxed.cpp -o taxed.o

taxfree.o: taxfree.cpp
	$(CXX) $(CXXFLAGS) -c taxfree.cpp -o taxfree.o

clean:
	rm -f *.o *.gch a.out store
