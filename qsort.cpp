// qsort.cpp

#include "lsort.h"

#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

void qsort_sort(List &l, bool numeric) {
    vector<Node *> nodeVec;
    for(auto curr = l.head; curr!=nullptr; curr = curr->next){
        nodeVec.push_back(curr);
    }
    if(numeric){
        qsort(nodeVec.data() , nodeVec.size(), sizeof(Node*), void_number_compare);
    }
    
    else{
        qsort(nodeVec.data(), nodeVec.size(), sizeof(Node*), void_string_compare);
    }
    //relink nodes in array
    Node* curr;
    l.head = nodeVec[0];
    curr = l.head;
    for(size_t i=1; i<nodeVec.size(); i++){
        curr->next = nodeVec[i];
        curr = curr->next;
    }
    //curr is at last node, so last node->next to be null
    curr->next = nullptr;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
