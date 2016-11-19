all: simulator

simulator:
	gcc -o Simulator Simulator.c

clean:
	rm Simulator
