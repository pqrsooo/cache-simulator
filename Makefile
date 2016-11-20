all: simulator

simulator:
	gcc -o Simulator Simulator.c

simulator-cpp:
	g++ -std=c++11 -o Simulator-cpp Simulator.cpp

clean: clean-simulator clean-simulator-cpp

clean-simulator:
	rm Simulator

clean-simulator-cpp:
	rm Simulator-cpp
