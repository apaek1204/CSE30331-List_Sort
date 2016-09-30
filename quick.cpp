// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    if(numeric){
        l.head = qsort(l.head, node_number_compare);
    }
    else{
        l.head = qsort(l.head, node_string_compare);
    }
}

Node *qsort(Node *head, CompareFunction compare) {
    //handle base case
    if(head->next == nullptr ) { return head; }   
    //divide
    Node* left=nullptr;
    Node* right=nullptr;
    partition(head->next, head, left, right,compare);
    //conquer
    if(left!=nullptr)  { left=qsort(left, compare); }
    if(right!=nullptr) { right=qsort(right, compare); }

    //add head to right
    head->next=right;
    right=head;

    head=concatenate(left, right);
    return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    Node* curr;
    Node* toNext;
    curr = head;
    //scan the list, prepend to 'left' or 'right' depending on the result of CompareFunction
    while( curr!=nullptr ){
        toNext = curr->next;
        if( compare(curr, pivot) ){
            curr->next = left; left = curr;
        }
        else if( compare(pivot, curr) ){
            curr->next = right; right = curr;
        }
        else if(pivot==curr){}
        curr = toNext;
    }
}

Node *concatenate(Node *left, Node *right) {
    Node* curr;
    curr = left;
    //traverse left sublist until the end, then connect end of left to right
    if(left!=nullptr){
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = right;
        return left;
    }
    else{
        return right;
    }
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
