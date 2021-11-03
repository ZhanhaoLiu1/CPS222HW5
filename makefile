all: 
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests 
run:
	./graph-tests
