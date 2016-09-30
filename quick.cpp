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
    if(head->next == nullptr) { return head; }   
    //divide
    Node* left;
    Node* right;
    partition(head, head, left, right,compare);
    //conquer
    qsort(head, compare);
    //combine
    head = concatenate(left, right);
    return head;
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
    Node* curr;
    Node* temp;
    curr = head;
    //scan the list, prepend to 'left' or 'right' depending on the result of CompareFunction
    while( curr!=nullptr ){
        std::cout<<"before if"<<std::endl;
        if( compare(curr, pivot) ){
            temp=curr;
            std::cout<<"inside if comparison"<<std::endl;
            if(left==nullptr){ left=temp;}
            else{ temp->next = left; left = temp; }
        }
        else if( compare(pivot, curr) ){
            temp=curr;
            std::cout<<"inside else comparison"<<std::endl;
            if(right==nullptr){ right=temp; }
            else{ temp->next = right; right = temp; }
        }
        else if( pivot==curr ){
        }
        curr = curr->next;
        std::cout<<curr->string<<std::endl;
    }
}

Node *concatenate(Node *left, Node *right) {
    Node* curr;
    curr = left;
    //traverse left sublist until the end
    while(curr->next == nullptr){
        curr = curr->next;
    }
    curr->next = right;
    return left;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
