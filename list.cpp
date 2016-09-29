// list.cpp

#include "lsort.h"
#include <iostream>
#include <memory>
#include <string>

List::List() {
    this->head = nullptr;
    this->size = 0;
}

List::~List() {
    Node* curr;
    while(head != nullptr){
        curr = head->next;
        delete head;
        head = curr;
    }
}

void List::push_front(const std::string &s) {
    if(size == 0){
        Node* n = new Node{s, stoi(s), nullptr};
        head = n;
    }
    else{
        Node* n = new Node{s, stoi(s), head};
        head = n;
    }
    size++;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
