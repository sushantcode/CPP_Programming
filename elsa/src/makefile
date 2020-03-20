CXXFLAGS = --std=c++17

store: main.o customer.o store.o options.o desktop.o order.o
	$(CXX) $(CXXFLAGS) main.o customer.o store.o options.o desktop.o order.o -o store

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

customer.o: customer.cpp
	$(CXX) $(CXXFLAGS) customer.cpp -c -o customer.o

store.o: store.cpp
	$(CXX) $(CXXFLAGS) store.cpp -c -o store.o

options.o: options.cpp
	$(CXX) $(CXXFLAGS) options.cpp -c -o options.o
	
desktop.o: desktop.cpp
	$(CXX) $(CXXFLAGS) desktop.cpp -c -o desktop.o
	
order.o: order.cpp
	$(CXX) $(CXXFLAGS) order.cpp -c -o order.o
	
clean:
	rm -f *.o *.gch a.out store
