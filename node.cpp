// node.cpp

#include "lsort.h"

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool node_number_compare(const Node *a, const Node *b) {
    return (a->number < b->number);
}

bool node_string_compare(const Node *a, const Node *b) {
    return (a->string < b->string);
}

int void_number_compare(const void *a, const void *b) {
    const Node** NodeA = (const Node**)a;
    const Node** NodeB = (const Node**)b;
    return ((*NodeA)->number - (*NodeB)->number);
}

int void_string_compare(const void *a, const void *b) {
    const Node** NodeA = (const Node**)a;
    const Node** NodeB = (const Node**)b;
    const char* aSTR = (*NodeA)->string.c_str();
    const char* bSTR = (*NodeB)->string.c_str();
    
    return strcmp(aSTR, bSTR);
}

void dump_node(Node *n) {
    Node* curr = n;
    while(curr != nullptr){
        std::cout << curr->string << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
