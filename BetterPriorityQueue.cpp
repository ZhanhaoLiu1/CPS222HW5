#include "BetterPriorityQueue.h"
#include <iostream>
#include <vector>

using namespace std;


bool BetterPriorityQueue::Contains(DNode n){// copy all the container in priority_queue and find the DNode
    Queue = priority_queue::c;
    for (size_t i = 0; i < Queue.size(); i++)
    {
        if (n==Queue[i])
        {
            return true;
        }
        
    }
    return false;
}

bool BetterPriorityQueue::Update(DNode n){// copy all the container in priority_queue, change the value in copy. empty all the queue and rewrite into it
    Queue = priority_queue::c;
    for (size_t i = 0; i < Queue.size(); i++)
    {
        if (n == Queue[i] && n.pri < Queue[i].pri )
        {
            Queue[i].pri=n.pri;
            for (size_t k = 0; k <Queue.size(); k++)
            {
                priority_queue::pop();
            }
            
            for (size_t j = 0; j < Queue.size(); j++)
            {
                priority_queue::push(Queue[j]);
            }
            return true;
        }
    }
    return false;
}

string BetterPriorityQueue::ToString(){
    Queue = priority_queue::c;
    string queue_to_string = "[(";
    for (size_t i = 0; i < Queue.size()-1; i++)
    {
        queue_to_string = queue_to_string + Queue[i].node->key + ": " + to_string(Queue[i].pri) + "), (";
    }
    queue_to_string = queue_to_string + Queue[Queue.size()-1].node->key + ": " + to_string(Queue[Queue.size()-1].pri) + ")]";
    return queue_to_string;
}

string BetterPriorityQueue::DnodeToString(DNode n){
    string Dnode_to_string = "(";
    Dnode_to_string = Dnode_to_string + n.node->key + ": " + to_string(n.pri) + ")";
    return Dnode_to_string;
}