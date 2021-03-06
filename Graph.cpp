
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::~Graph(){// delete the every node and graph by loop
    for (size_t i = 0; i < Graph.size(); i++)
    {
        delete Node.at(i);
        for (size_t j = 0; j < Graph.at(i).size(); j++)
        {
            delete Graph.at(i).at(j);
        }
    }
}

GraphNode *Graph::AddNode(char key, int data){ //push new node into vector and add a empty set into graph
    for (size_t i = 0; i < Node.size(); i++)
    {
        if(key == Node.at(i)->key){// if node already in Node throw exception
            throw invalid_argument("Node already exists");
        }
    }
    Node.push_back(new GraphNode {key,data});
    Graph.push_back({});
    return Node.at(Node.size()-1);
}

GraphEdge *Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){// Check the gn1 in Node get the position and push the edge in to graph by loop
    int count;
    for (int i = 0; i < int(Node.size()); i++)
    {
        if (Node.at(i)->key == gn1->key){
            for (size_t j = 0; j < Node.size(); j++)
            {
                if (Node.at(j)->key == gn2->key){
                    count = i;
                Graph.at(i).push_back(new GraphEdge {gn1,gn2,weight});
                return Graph.at(count).at(Graph.at(count).size()-1);
                }
            }
            //delete gn2;
            throw invalid_argument("Node To is not exists");
        }
    }
    //delete gn1;
    throw invalid_argument("Node From is not exists");
}

string Graph::NodesToString() const {
    string node_string;
    node_string += "[";
    for (int i = 0; i < int(Node.size()-1); i++){
        node_string = node_string+"("+ Node.at(i)->key+":"+to_string(Node.at(i)->data)+"), ";
    }
    node_string = node_string + "(" + Node.at(Node.size()-1)->key +":"+to_string(Node.at(Node.size()-1)->data)+")]";
    return node_string;
    
}

string Graph::ToString() const {
    string graph_string;
    for (int i = 0; i <=int(Node.size()-1) ; i++){
        graph_string = graph_string + Node.at(i)->key + " | ";
        if (Graph.at(i).size() == 0){
            graph_string += "\n";
        }else{
            for (int j = 0; j < int(Graph.at(i).size()-1); j++){   //"a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n "
                graph_string = graph_string + "[(" + Graph.at(i).at(j)->from->key + ":" + to_string(Graph.at(i).at(j)->from->data) + ")->(" + Graph.at(i).at(j)->to->key + ":" + to_string(Graph.at(i).at(j)->to->data) + ") w:"+to_string(Graph.at(i).at(j)->weight) + "], ";
            }
            graph_string = graph_string + "[("+Graph.at(i).at(Graph.at(i).size()-1)->from->key + ":"+to_string(Graph.at(i).at(Graph.at(i).size()-1)->from->data) + ")->(" + Graph.at(i).at(Graph.at(i).size()-1)->to->key + ":" + to_string(Graph.at(i).at(Graph.at(i).size()-1)->to->data) + ") w:" + to_string(Graph.at(i).at(Graph.at(i).size()-1)->weight) + "]\n";
        }
    }
    return graph_string;
}

string Graph::GraphNodeToString(const GraphNode *gn){
    string graph_node_string;
    graph_node_string = "(";
    graph_node_string =  graph_node_string+ gn->key + ":" + to_string(gn->data) + ")";
    return graph_node_string;
}

string Graph::GraphEdgeToString(const GraphEdge *ge){
    string  graph_edge_string;
    graph_edge_string = "[(";
    graph_edge_string = graph_edge_string + ge->from->key + ":" + to_string(ge->from->data) + ")->(" + ge->to->key + ":" + to_string(ge->to->data) + ") w:" + to_string(ge->weight) + "]";
    return graph_edge_string;
}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{// Find the to node in edge get the position in Node and return the same place in Graph
    for (int i = 0; i < int(Node.size()); i++){
        if (gn->key == Node.at(i)->key){
            return Graph.at(i);
        }
    }
    throw invalid_argument("Not have edge exist");
}

const vector<GraphNode*>& Graph::GetNodes() const{
    return Node;
}

const GraphNode* Graph::NodeAt(unsigned int idx) const{
    if (idx >= Node.size())
    {
        throw invalid_argument("Index Invalid");
    }
    return Node.at(idx);
}

size_t Graph::Size() const{
    size_t graph_size = 0;
    for (int i = 0; i < int(Graph.size()); i++){
        graph_size += Graph[i].size();
    }
    return graph_size;
}

size_t Graph::Order() const{
    return Node.size();
}
