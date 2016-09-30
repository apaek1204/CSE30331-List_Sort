// merge.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

void merge_sort(List &l, bool numeric) {
    if(numeric)
        l.head = msort(l.head, node_number_compare);
    else
        l.head = msort(l.head, node_string_compare);
}

Node *msort(Node *head, CompareFunction compare) {
      
    
    //handle base case
    if(head->next==nullptr || head == nullptr)
        return head;
    
    //divide into left and right sublists
    Node *left;
    Node *right;
    split(head, left, right);
    
    //conquer left and right sublists
    left=msort(left, compare);
    right=msort(right, compare);
    
        
    //combine left and right sublists
       
    return merge(left, right, compare);
}

void split(Node *head, Node *&left, Node *&right) {
    Node* slow = head;
    Node* fast = head;
    //increment fast twice every time we increment slow once 
    while(fast->next != nullptr){
        fast=fast->next;
        if(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }
    }
    //slow is 1 less than half way through so set to right
    left = head;
    right = slow->next;
    //set next to null so half is in left and other half in right
    slow->next = nullptr;  
    //std::cout << "test: "<< right->next->number << std::endl;

}

Node *merge(Node *left, Node *right, CompareFunction compare) { 
    Node* head;
    Node* curr;
    //set head
    if(left&&right){
        if(compare(left, right)){
            head = left;
            left = left->next;
        }
        else{
            head = right;
            right = right->next;
            //std::cout << "right head" << std::endl;
        }
        curr=head;
    }
    //while both lists exist, compare
    while(left && right){
        if(compare(left, right)){
            curr->next = left;
            left = left->next;
        }
        else{
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }
    //if right list runs out, add rest of left list
    while(left){
        curr->next = left;
        left = left->next;
        curr = curr->next;
    }
    //if left list runs out add rest of right list
    while(right){
        curr->next = right;
        right=right->next;
        curr = curr->next;
    }
    curr->next = nullptr;
      
    return head;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
