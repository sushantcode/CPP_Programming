CXXFLAGS = --std=c++17

coin: test.o coin.o
	$(CXX) $(CXXFLAGS) test.o coin.o -o coin

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp -o coin.o

clean:
	rm -f *.o *.gch a.out  coin
logger:
	$(CXX) $(CXXFLAGS) -DLOGGER -c test.cpp -o test.o
	$(CXX) $(CXXFLAGS) -DLOGGER -c coin.cpp -o coin.o
	$(CXX) $(CXXFLAGS) -DLOGGER test.o coin.o -o coin
