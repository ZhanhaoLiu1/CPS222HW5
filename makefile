all: 
	g++ -Wall Graph.cpp GraphTests.cpp -o graph-tests 
	g++ -Wall Graph.cpp BetterPriorityQueue.cpp BPQTests.cpp -o bpq-tests
	g++ -Wall Dijkstra.cpp Graph.cpp BetterPriorityQueue.cpp -o dijkstra
run:
	./graph-tests
do: 
	./bpq-tests
dijkstra:
	./dijkstra