

#include "Graph.h"
//#include "Graph.cpp"
#include <iostream>
#include <cassert>

using namespace std;



void TestAddNode(){
	cout << "Testing AddNode..." << endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");

	
	
	// more tests....
	try{
		g.AddNode('a',7);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}
	
	cout << "PASSED!" << endl << endl;
}


void TestAddEdge(){
	cout << "Testing AddEdge..." << endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15)]");
	assert(g.ToString() == "a | \n");
	
	GraphNode *gn2 = g.AddNode('b', 12);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;

	assert(g.NodesToString() == "[(a:15), (b:12)]");
	assert(g.ToString() == "a | \nb | \n");
	
	GraphNode *gn3 = g.AddNode('c', 9);
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | \nb | \nc | \n");
	
	g.AddEdge(gn1, gn3, 2);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2]\nb | \nc | \n");
	
	g.AddEdge(gn3, gn2);
	g.AddEdge(gn1, gn2, 8);
	//cout << "nodes: "  << g.NodesToString() << endl;
	//cout << "graph: " << endl << g.ToString() << endl;
	
	assert(g.NodesToString() == "[(a:15), (b:12), (c:9)]");
	assert(g.ToString() == "a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n");

	GraphNode *gn6 = new GraphNode {'f',8};
	try{
		g.AddEdge(gn6, gn1, 6);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}

	GraphNode *gn7 = new GraphNode {'f',8};
	try{
		g.AddEdge(gn3, gn7, 6);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}
	
	delete gn6;
	delete gn7;


	cout << "PASSED!" << endl << endl;
}

void TestGetEdges(){
	cout << "Testing GetEdges..."<< endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	GraphNode *gn2 = g.AddNode('b', 12);
	
	GraphNode *gn3 = g.AddNode('c', 9);

	GraphNode *gn4 = g.AddNode('d',10);

	g.AddNode('e',7);

	GraphNode *gn6 = new GraphNode {'f',8};

	g.AddEdge(gn1, gn3, 2);
	g.AddEdge(gn3, gn1, 6);
	g.AddEdge(gn2, gn4, 9);
	g.AddEdge(gn2, gn3, 9);

	vector<GraphEdge*> test_get_edge = g.GetEdges(gn1);
	assert(g.GraphEdgeToString(test_get_edge.at(0)) == "[(a:15)->(c:9) w:2]");
	test_get_edge = g.GetEdges(gn2);
	assert(g.GraphEdgeToString(test_get_edge.at(0)) == "[(b:12)->(d:10) w:9]");
	assert(g.GraphEdgeToString(test_get_edge.at(1)) == "[(b:12)->(c:9) w:9]");

	try{
		test_get_edge = g.GetEdges(gn6);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}

	delete gn6;

	cout << "PASSED!" << endl << endl;
}

void TestGetNodes(){
	cout << "Testing GetNodes..."<< endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	g.AddNode('b', 12);
	g.AddNode('c', 9);
	g.AddNode('d',10);
	g.AddNode('e',7);


	vector<GraphNode*> test_node = g.GetNodes();
	string get_node = "[";
	for (size_t i = 0; i < test_node.size()-1; i++)
	{
		get_node += g.GraphNodeToString(test_node.at(i)) + ", ";
	}
	get_node += g.GraphNodeToString(test_node.at(test_node.size()-1))+"]";
	//cout << get_node <<endl;
	assert(get_node == "[(a:15), (b:12), (c:9), (d:10), (e:7)]");
	cout << "PASSED!" << endl << endl;
}

void TestNodeAt(){
	cout << "Testing NodeAt..." << endl;
	Graph g = Graph();
	g.AddNode('a', 15);
	g.AddNode('b', 12);
	g.AddNode('c', 9);
	g.AddNode('d',10);
	g.AddNode('e',7);

	//cout << g.GraphNodeToString(g.NodeAt(0)) << endl;
	assert(g.GraphNodeToString(g.NodeAt(0)) == "(a:15)");
	assert(g.GraphNodeToString(g.NodeAt(4)) == "(e:7)");
	try
	{
		string try_test; 
		try_test = g.GraphNodeToString(g.NodeAt(5));
		assert(false);
	}
	catch(const invalid_argument& e)
	{
		
	}
	cout << "PASSED!" << endl << endl;
}

void TestSize(){
	cout << "Testing Size..."<< endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	GraphNode *gn2 = g.AddNode('b', 12);
	
	GraphNode *gn3 = g.AddNode('c', 9);

	GraphNode *gn4 = g.AddNode('d',10);
	g.AddNode('e',7);


	g.AddEdge(gn1, gn3, 2);
	g.AddEdge(gn3, gn1, 6);
	g.AddEdge(gn2, gn4, 9);
	g.AddEdge(gn2, gn3, 9);

	assert(g.Size() == 4);
	cout << "PASSED!" << endl << endl;
}

void TestOrder(){
	cout << "Testing Order..."<< endl;
	Graph g = Graph();
	GraphNode *gn1 = g.AddNode('a', 15);
	
	GraphNode *gn2 = g.AddNode('b', 12);
	
	GraphNode *gn3 = g.AddNode('c', 9);

	GraphNode *gn4 = g.AddNode('d',10);

	g.AddNode('e',7);


	g.AddEdge(gn1, gn3, 2);
	g.AddEdge(gn3, gn1, 6);
	g.AddEdge(gn2, gn4, 9);
	g.AddEdge(gn2, gn3, 9);

	assert(g.Order() == 5);
	cout << "PASSED!" << endl << endl;
}

void TestDestructor(){
	cout << "Testing Destructor..." << endl;
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('a', 3);
	GraphNode *b = g->AddNode('b', 5);
	g->AddEdge(b, a, 15);
	
	delete g;

	
	Graph g2 = Graph();
	GraphNode *c = g2.AddNode('c', 12);
	g2.AddNode('d', 11);
	assert(c->key == 'c' && c->data == 12);
	cout << "NO ERRORS.  Use valgrind to check!" << endl << endl;

}


// more test functions...


int main(){
	TestAddNode();
	TestAddEdge();
	TestGetEdges();
	TestGetNodes();
	TestNodeAt();
	TestSize();
	TestOrder();
	TestDestructor();


	
	cout << "ALL TESTS PASSED!" << endl;
	return 0;
}
