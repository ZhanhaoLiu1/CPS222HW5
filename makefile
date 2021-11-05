all: 
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests 
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests
run:
	./graph-tests
do: 
	./bpq-tests
