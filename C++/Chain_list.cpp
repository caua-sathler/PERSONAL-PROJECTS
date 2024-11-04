#include "Chain_list.hpp"
#include <iostream>

Chain_list::Chain_list(){
    this->head = nullptr;
    this->tail = nullptr;
    this->num_elements = 0;
    this->p = &num_elements;
}


void Chain_list::insert_node(int data) {
    Node* ctrl = new Node;
    ctrl->data = data;
    ctrl->next = nullptr;

    if(head == nullptr) {
        head = ctrl;
        ctrl->previous = nullptr;
        tail = ctrl;
    } else {
        tail->next = ctrl;
        ctrl->previous = tail;
        tail = ctrl;
    }
    *p += 1;
}

void Chain_list::delete_node(int data) {
    Node* current = head;

    while (current != nullptr) {
        if (current->data == data) {
            if (current->previous == nullptr) { 
                head = current->next;
                if (head != nullptr) {
                    head->previous = nullptr;
                }
                if (current == tail) { 
                    tail = nullptr;
                }
            } else if (current->next == nullptr) { 
                tail = current->previous;
                tail->next = nullptr;
            } else { 
                current->previous->next = current->next;
                current->next->previous = current->previous;
            }
            delete current;
            *p -= 1;
            return; 
        }
        current->previous = current;
        current = current->next;
    }
}

bool Chain_list::is_on_list(int data) {
    Node* current = head;

    while(current != nullptr) {
        if(current->data == data) {
            std::cout << "The number " << data << " is on the list." << std::endl;
            return true;
        }
        else 
            current = current->next;
    }
    std::cout << "The number " << data << " is not on the list." << std::endl;
    return false;
}

void Chain_list::display_content() {
    Node* current = head;

    while(current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Chain_list::display_num_nodes() {
    std::cout << num_elements << std::endl;
}

Chain_list::~Chain_list() {
    Node* current = head;
    Node* next;

    while(current != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
}










