#ifndef CHAIN_LIST_H
#define CHAIN_LIST_H

class Node {
public:
    int data;
    Node* next;
    Node* previous;
};

class Chain_list {
private:
    Node* head;
    Node* tail;
    int num_elements;
    int* p;

public:
    Chain_list();
    void display_content();
    void display_num_nodes();
    void insert_node(int data);
    void delete_node(int data);
    bool is_on_list(int data);
    ~Chain_list();
};



#endif