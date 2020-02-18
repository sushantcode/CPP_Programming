CXXFLAGS = --std=c++17

coin: main.o coin.o
	$(CXX) $(CXXFLAGS) main.o coin.o -o coin

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o

clean:
	rm -f *.o *.gch a.out  coin
logger:
	$(CXX) $(CXXFLAGS) -DLOGGER -c main.cpp -o main.o
	$(CXX) $(CXXFLAGS) -DLOGGER -c coin.cpp -o coin.o
	$(CXX) $(CXXFLAGS) -DLOGGER main.o coin.o -o coin
