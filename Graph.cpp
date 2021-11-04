
#include "Graph.h"
#include <iostream>
#include <vector>

using namespace std;

Graph::~Graph(){
    for (int i = 0; i <int (Node.size()-1); i++){
        delete &Node[i];
        for (size_t j = 0; j < Graph[i].size(); j++)
        {
            delete &Graph[i][j];
        }
    }
    
}

GraphNode *Graph::AddNode(char key, int data){
    GraphNode *node = new GraphNode {key,data};
    Node.push_back(*node);
    Graph.push_back({});
    return node;
}

GraphEdge *Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    GraphEdge *edge = new GraphEdge {gn1,gn2,weight};
    for (int i = 0; i < int(Node.size()); i++)
    {
        if (Node[i].key == gn1->key)
        {
            Graph[i] .push_back(*edge);
        }
    }
    return edge;
}

string Graph::NodesToString() const {
    string node_string;
    node_string += "[";
    for (int i = 0; i < int(Node.size()-1); i++){
        node_string = node_string+"("+ Node.at(i).key+":"+to_string(Node.at(i).data)+"), ";
    }
    node_string = node_string + "(" + Node.at(Node.size()-1).key +":"+to_string(Node.at(Node.size()-1).data)+")]";
    return node_string;
    
}

string Graph::ToString() const {
    string graph_string;
    for (int i = 0; i <=int(Node.size()-1) ; i++){
        graph_string = graph_string + Node[i].key + " | ";
        if (Graph[i].size() == 0){
            graph_string += "\n";
        }else{
            for (int j = 0; j < int(Graph[i].size()-1); j++){   //"a | [(a:15)->(c:9) w:2], [(a:15)->(b:12) w:8]\nb | \nc | [(c:9)->(b:12) w:0]\n "
                graph_string = graph_string + "[("+Graph[i][j].from->key+":"+to_string(Graph[i][j].from->data)+")->("+Graph[i][j].to->key+":"+to_string(Graph[i][j].to->data)+") w:"+to_string(Graph[i][j].weight)+"], ";
            }
            graph_string = graph_string + "[("+Graph[i][Graph[i].size()-1].from->key+":"+to_string(Graph[i][Graph[i].size()-1].from->data)+")->("+Graph[i][Graph[i].size()-1].to->key+":"+to_string(Graph[i][Graph[i].size()-1].to->data)+") w:"+to_string(Graph[i][Graph[i].size()-1].weight)+"]\n";
        }
        
    }
    return graph_string;
}

string Graph::GraphNodeToString(const GraphNode *gn){
    string graph_node_string;
    graph_node_string = "[(";
    graph_node_string =  graph_node_string+ gn->key + ":" + to_string(gn->data) + ")]";
    return graph_node_string;
}

string Graph::GraphEdgeToString(const GraphEdge *ge){
    string  graph_edge_string;
    graph_edge_string = "[(";
    graph_edge_string = graph_edge_string + ge->from->key + ":" + to_string(ge->from->data) + ")->(" + ge->to->key + ":" + to_string(ge->to->data) + ") w:" + to_string(ge->weight);
    return graph_edge_string;
}

const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn) const{
    vector<GraphEdge*> *ge = new vector<GraphEdge*>;
    for (int i = 0; i < int(Node.size()); i++){
        if (gn->key == Node[i].key){
            //ge = Graph[i];
            for (int j = 0; j < int(Graph[i].size()); j++){
                GraphEdge *edge = new GraphEdge;
                edge->from = Graph[i][j].from;
                edge->to = Graph[i][j].to;
                edge->weight = Graph[i][j].weight;
                ge->push_back(edge);
            }
        }
    }
    return *ge;
}

const vector<GraphNode*>& Graph::GetNodes() const{
    vector<GraphNode*> *gn = new vector<GraphNode*>;
    for (int i = 0; i < int(Node.size()); i++)
    {
        GraphNode *node = new GraphNode;
        node->data = Node[i].data;
        node->key = Node[i].key;
        gn->push_back(node);
    }
    return *gn;
}

const GraphNode* Graph::NodeAt(unsigned int idx) const{
    GraphNode *node = new GraphNode;
    node->data = Node[idx].data;
    node->key = Node[idx].key;
    return node;
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
