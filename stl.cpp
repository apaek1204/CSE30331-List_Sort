// stl.cpp

#include "lsort.h"

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void stl_sort(List &l, bool numeric) {
    //store the nodes in a vector
    vector<Node*> nodeVec;
    for(auto curr = l.head; curr!= nullptr; curr = curr->next){
        nodeVec.push_back(curr);
    }

    //sort by int number data
    if(numeric){
        sort( nodeVec.begin(), nodeVec.end(), node_number_compare );
    }
    //sort by string data
    else{
        sort( nodeVec.begin(), nodeVec.end(), node_string_compare );
    }

    //relink nodes in array
    l.head = nodeVec[0];
    Node* curr;
    curr = l.head;
    for(size_t i=1; i<nodeVec.size(); i++){
        curr->next=nodeVec[i];
        curr = curr->next;
    }
    //right now, curr is at the last node. Set last node's next to be null
    curr->next = nullptr;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
