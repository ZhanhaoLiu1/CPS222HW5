

#include "Graph.h"
#include "BetterPriorityQueue.h"
//#include "Graph.cpp"
//#include "BetterPriorityQueue.cpp"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

// This file is not used for part 1


int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){
	BetterPriorityQueue q;
	vector<GraphNode*> nodes = g->GetNodes();
	bool contain_start=false;
	bool contain_end=false;
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		if (nodes[i] == start){
			cur.pri = 0;
			contain_start = true;
		}
		if (nodes[i] == end){
			contain_end = true;
		}else if (nodes[i] != start)
		{
			cur.pri = INT_MAX;
		}
		cur.node = nodes.at(i);
		q.push(cur);
	}
	if (contain_start == false || contain_end == false)
	{
		throw invalid_argument("Node not exists");
	}
	/*
		Using bool to check if the Node is valid, and using loop to put the edge into Priority Queue.
		Set the distance to the begining node is zero, other set to infinity.
	*/

	
	DNode pointer = q.top();
	cout<<"(" << pointer.node->key<<":"<<pointer.pri<<")"<<endl;
	q.pop();
	while (pointer.node != end)
	{
		vector<GraphEdge*> edges = g->GetEdges(pointer.node);
		// get the top node and finding all the edge of this node
		for (size_t i = 0; i < edges.size(); i++)
		{// In each run update the val of the road
			DNode exchange_value;
			exchange_value.node = edges[i]->to;
			if (pointer.pri == INT_MAX){
				exchange_value.pri = INT_MAX;
			}else{
				exchange_value.pri = edges[i]->weight+pointer.pri;
			}
			q.Update(exchange_value);
		}
		pointer = q.top();
		cout<<"(" << pointer.node->key<<":"<<pointer.pri<<")"<<endl;
		q.pop();
	}
	return pointer.pri;
}


int DijkstraTest(){
	// Note, when grading I will replace this with
	// other / more tests.  I recommend you do the same!
	
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	GraphNode *i = new GraphNode;
	
	cout << g->ToString() << endl;
	cout << "Normal testing" << endl;
	unsigned int ans = dijkstra(g->NodeAt(0), e, g);
	assert(ans == 20);
	cout << " "<<endl;
	ans = dijkstra(g->NodeAt(0), d, g);
	assert(ans == 20);
	cout << "Passed!"<<endl;
	cout << " "<<endl;
	cout << "Testing Unconnected" << endl;
	GraphNode *h = g->AddNode('7');
	ans = dijkstra(g->NodeAt(0), h, g);
	assert(ans = INT_MAX);
	cout << " "<<endl;
	ans = dijkstra(h, e, g);
	assert(ans = INT_MAX);
	cout << "Passed!"<<endl;
	cout << " "<<endl;
	cout << "Testing not exist Node" << endl;

	try{
		ans = dijkstra(i, e, g);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}
	try{
		ans = dijkstra(e, i, g);
		assert(false);
	}
	catch(const invalid_argument& e){
		
	}

	cout << "Passed!"<<endl;
	delete g;
	delete i;

	Graph *g2 = new Graph();
	GraphNode *a1 = g2->AddNode('1');
	GraphNode *b1 = g2->AddNode('2');
	GraphNode *c1 = g2->AddNode('3');
	GraphNode *d1 = g2->AddNode('4');
	GraphNode *e1 = g2->AddNode('5');
	GraphNode *f1 = g2->AddNode('6');
	
	//g2->AddEdge(a, b, 7);
	g2->AddEdge(b1, a1, 7);
	//g2->AddEdge(a, c, 9);
	g2->AddEdge(c1, a1, 9);
	//g2->AddEdge(a, f, 14);
	g2->AddEdge(f1, a1, 14);
	
	g2->AddEdge(b1, c1, 10);
	g2->AddEdge(c1, b1, 10);
	g2->AddEdge(b1, d1, 15);
	g2->AddEdge(d1, b1, 15);
	
	g2->AddEdge(c1, f1, 2);
	g2->AddEdge(f1, c1, 2);
	g2->AddEdge(c1, d1, 11);
	g2->AddEdge(d1, c1, 11);
	
	g2->AddEdge(f1, e1, 9);
	g2->AddEdge(e1, f1, 9);
	
	g2->AddEdge(d1, e1, 6);
	g2->AddEdge(e1, d1, 6);
	cout << " "<<endl;
	cout << "Testing single side edge" << endl;
	ans = dijkstra(f1, a1, g2);
	assert(ans == 11);
	cout << " "<<endl;
	ans = dijkstra(g2->NodeAt(0), e1, g2);
	assert(ans == INT_MAX);
	cout << "Passed!"<<endl;

	cout << " "<<endl;
	cout << "Testing selfNode" << endl;
	ans = dijkstra(a1, a1, g2);
	assert(ans == 0);
	cout << "Passed!"<<endl;
	delete g2;

	cout << " "<<endl;
	cout << "All Test Passed!";
	return ans;
}

int main(){
	
	int ans = DijkstraTest();
	cout << "ans: "  << ans << endl;
	
	return 0;
}
