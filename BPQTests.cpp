

#include "Graph.h"
#include "Graph.cpp"
#include "BetterPriorityQueue.h"
#include "BetterPriorityQueue.cpp"
#include <cassert>

using namespace std;
/*
void ContainsTest() {
	cout << "Testing Contains Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	GraphNode *a = g.AddNode('a');
	
	GraphNode *b = g.AddNode('b');
	GraphNode *c = g.AddNode('c');
	GraphNode *d = g.AddNode('d');
	GraphNode *e1 = g.AddNode('e');
	GraphNode *g1 = g.AddNode('g');
	GraphNode *h = g.AddNode('h');
	GraphNode *l = g.AddNode('k');
	GraphNode *p = g.AddNode('m');
	GraphNode *o = g.AddNode('n');

	DNode an;
	
	DNode bn;
	DNode dn;
	DNode gn;
	DNode en;
	DNode ln;
	DNode on;
	DNode pn;
	DNode cn;
	DNode hn;

	an.node = a;
	
	bn.node = b;
	dn.node = d;
	gn.node = g1;
	ln.node = l;
	on.node = o;
	pn.node = p;
	cn.node = c;
	hn.node = h;
	en.node = e1;

	q.push(an);
	
	q.push(bn);
	q.push(hn);
	q.push(cn);
	q.push(on);
	q.push(pn);
	q.push(gn);
	
	assert(q.Contains(an) == true);
	
	assert(q.Contains(gn) == true);
	assert(q.Contains(pn) == true);
	assert(q.Contains(on) == true);
	assert(q.Contains(dn) == false);
	assert(q.Contains(en) == false);
	assert(q.Contains(ln) == false);
	

	// more tests go here!
	
	
	cout << "PASSED!" << endl;
}



void UpdateTest() {
	cout << "Testing Update Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode('a');
	g.AddNode('b');
	g.AddNode('c');
	g.AddNode('d');
	g.AddNode('e');
	GraphNode *f = g.AddNode('f');
	vector<GraphNode*> nodes = g.GetNodes();
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		cur.pri = i;
		cur.node = nodes.at(i);
		//cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q.push(cur);
		//cout << "size: " << q.size() << endl;
		cout << q.DnodeToString(cur)<<endl;
	}
	

	//cout << "q before: " << queue_to_string(q) << endl;

	DNode positive;
	positive.node = f;
	positive.pri = 0;
	cout << "q before: " << q.ToString() << endl;
	assert(q.Update(positive) == true);
	cout << "q after: " << q.ToString() << endl;


	// Either one of these solutions is correct depending on
	// how you implement the priority queue
	string soln1 = "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 4), (c: 2)]";
	string soln2 = "[(f: 0), (b: 1), (a: 0), (d: 3), (e: 4), (c: 2)]";
	assert(q.ToString() == soln1 || q.ToString() == soln2);
	
	
	// more tests go here...
	
	
	cout << "PASSED!" << endl;
}*/


void ContainsTest() {
	cout << "Testing Contains Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	GraphNode *a = g.AddNode('a');
	g.AddNode('b');
	g.AddNode('c');
	g.AddNode('d');
	g.AddNode('e');
	g.AddNode('f');
	vector<GraphNode*> nodes = g.GetNodes();
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		cur.node = nodes.at(i);
		cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q.push(cur);
		cout << "size: " << q.size() << endl;
	}
	
	
	// 1st test
	DNode positive;
	positive.node = a;
	assert(q.Contains(positive) == true);
	
	// 2nd test
	DNode negative;
	assert(q.Contains(negative) == false);
	
	// 3rd test
	assert(q.Contains(positive) == true);
	
	
	cout << "PASSED!" << endl;
}



void UpdateTest() {
	cout << "Testing Update Helper Method..." << endl;
	
	Graph g = Graph();
	BetterPriorityQueue q;
	
	g.AddNode('a');
	g.AddNode('b');
	g.AddNode('c');
	g.AddNode('d');
	GraphNode *e = g.AddNode('e');
	GraphNode *f = g.AddNode('f');
	vector<GraphNode*> nodes = g.GetNodes();
	for(size_t i = 0; i < nodes.size(); i++){
		DNode cur;
		cur.pri = i;
		cur.node = nodes.at(i);
		//cout << "inserting cur.pri: " << cur.pri << "  node: " << cur.node->key << endl;
		q.push(cur);
		//cout << "size: " << q.size() << endl;
	}
	

	//cout << "q before: " << queue_to_string(q) << endl;

	// Test 1: update a node with pri 0 (normal case)
	DNode positive;
	positive.node = f;
	positive.pri = 0;
	cout << "q before: " << q.ToString() << endl;
	assert(q.Update(positive) == true);
	cout << "q after: " << q.ToString() << endl;

	string soln1 = "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 4), (c: 2)]";
	string soln2 = "[(f: 0), (b: 1), (a: 0), (d: 3), (e: 4), (c: 2)]";

	
	
	// Test 2: attempt to update with an empty / undefined input
	DNode negative;
	assert(q.Update(negative) == false);
	cout << "q after after: " << q.ToString() << endl;
	assert(q.ToString() == soln1 || q.ToString() == soln2);
	

	// Test 3: update a node with a larger priority
	// It must behave this way (ignoring larger priorities)
	// for compatibility with Dijkstra's algorithm
	DNode negative2;
	negative2.node = e;
	negative2.pri = 80;
	assert(q.Update(negative2) == false);
	cout << "q after after after: " << q.ToString() << endl;
	//soln1 = "[(a: 0), (b: 1), (f: 0), (d: 3), (e: 80), (c: 2)]";
	// some students might have a slightly different order
	// please ensure the output is a valid priorityqueue as 
	// implemented by a binary heap
	assert(q.ToString() == soln1 || q.ToString() == soln2);
	
	
	cout << "PASSED!" << endl;
}


int main(){
	
	ContainsTest();
	UpdateTest();
	
	cout << "ALL TESTS PASSED!!" << endl;
	
	return 0;
	
}
