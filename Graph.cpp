
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::~Graph(){
    for (size_t i = 0; i < Graph->size(); i++)
    {
        delete Node->at(i);
        for (size_t j = 0; j < Graph->at(i).size(); j++)
        {
            delete Graph->at(i).at(j);
        }
        Graph->pop_back();
    }
    delete Node;
    delete Graph;
}

GraphNode *Graph::AddNode(char key, int data){
    //GraphNode *node = new GraphNode {key,data};
    //GraphNode node {key,data};
    Node->push_back({});
    Node->at(Node->size()-1) = new GraphNode {key,data};
    Graph->push_back({});
    return Node->at(Node->size()-1);
}

GraphEdge *Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    //GraphEdge *edge = new GraphEdge {gn1,gn2,weight};
    int count;
    for (int i = 0; i < int(Node->size()); i++)
    {
        if (Node->at(i)->key == gn1->key){
            count = i;
            Graph->at(i).push_back(new GraphEdge {gn1,gn2,weight});
        }
    }
    return Graph->at(count).at(Graph->at(count).size()-1);
}

string Graph::NodesToString() const {
    string node_string;
    node_string += "[";
    for (int i = 0; i < int(Node->size()-1); i++){
        node_string = node_string+"("+ Node->at(i)->key+":"+to_string(Node->at(i)->data)+"), ";
    }
    node_string = node_string + "(" + Node->at(Node->size()-1)->key +":"+to_string(Node->at(Node->size()-1)->data)+")]";
    return node_string;
    
}

string Graph::ToString() const {
    string graph_string;
    for (int i = 0; i <=int(Node->size()-1) ; i++){
        graph_string = graph_string + Node->at(i)->key + " | ";
        if (Graph->at(i).size() == 0){
            graph_string += "\n";
        }else{
            for (int j = 0; j < int(Graph->at(i).size()-1); j++){   //"a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n "
                graph_string = graph_string + "[(" + Graph->at(i).at(j)->from->key + ":" + to_string(Graph->at(i).at(j)->from->data) + ")->(" + Graph->at(i).at(j)->to->key + ":" + to_string(Graph->at(i).at(j)->to->data) + ") w:"+to_string(Graph->at(i).at(j)->weight) + "], ";
            }
            graph_string = graph_string + "[("+Graph->at(i).at(Graph->at(i).size()-1)->from->key + ":"+to_string(Graph->at(i).at(Graph->at(i).size()-1)->from->data) + ")->(" + Graph->at(i).at(Graph->at(i).size()-1)->to->key + ":" + to_string(Graph->at(i).at(Graph->at(i).size()-1)->to->data) + ") w:" + to_string(Graph->at(i).at(Graph->at(i).size()-1)->weight) + "]\n";
        }
    }
    return graph_string;
}

string Graph::GraphNodeToString(const GraphNode *gn){
    string graph_node_string;
    graph_node_string = "[(";
    graph_node_string =  graph_node_string+ gn->key + ":" + to_string(gn->data) + ")]";
    delete gn;
    return graph_node_string;
}

string Graph::GraphEdgeToString(const GraphEdge *ge){
    string  graph_edge_string;
    graph_edge_string = "[(";
    graph_edge_string = graph_edge_string + ge->from->key + ":" + to_string(ge->from->data) + ")->(" + ge->to->key + ":" + to_string(ge->to->data) + ") w:" + to_string(ge->weight);
    delete ge;
    return graph_edge_string;
}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{
    vector<GraphEdge*> *ge = new vector<GraphEdge*>;
    for (int i = 0; i < int(Node->size()); i++){
        if (gn->key == Node->at(i)->key){
            for (int j = 0; j < int(Graph->at(i).size()); j++){
                GraphEdge *edge = new GraphEdge;
                edge->from = Graph->at(i).at(j)->from;
                edge->to = Graph->at(i).at(j)->to;
                edge->weight = Graph->at(i).at(j)->weight;
                ge->push_back(edge);
            }
        }
    }
    return *ge;
}

const vector<GraphNode*>& Graph::GetNodes() const{
    vector<GraphNode*> *gn = new vector<GraphNode*>;
    for (int i = 0; i < int(Node->size()); i++)
    {
        GraphNode *node = new GraphNode;
        node->data = Node->at(i)->data;
        node->key = Node->at(i)->key;
        gn->push_back(node);
    }
    return *gn;
}

const GraphNode* Graph::NodeAt(unsigned int idx) const{
    GraphNode *node = new GraphNode;
    node->data = Node->at(idx)->data;
    node->key = Node->at(idx)->key;
    return node;
}

size_t Graph::Size() const{
    size_t graph_size = 0;
    for (int i = 0; i < int(Graph->size()); i++){
        graph_size += Graph[i].size();
    }
    return graph_size;
}

size_t Graph::Order() const{
    return Node->size();
}
