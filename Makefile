all:
	$(CXX) -Wall main.cpp -o sortandsearch

test:
	 ./sortandsearch || exit 1