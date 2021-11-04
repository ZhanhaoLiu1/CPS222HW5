#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;
struct DNode {
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const {
		return node == other.node;
	}
};

class BetterPriorityQueue
{

    public:
        ~BetterPriorityQueue();

        void push(DNode n){};
        int top(){};
        void pop(){};

        string ToString() const;


        bool Contains(DNode n){};
        bool Update(DNode n){};

    private:
        vector<DNode> list; 

};



#endif