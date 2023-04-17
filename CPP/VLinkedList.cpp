#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::insert(int val1, int val2) {
    Node* newNode = new Node;
    newNode->value1 = val1;
    newNode->value2 = val2;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void LinkedList::printList() {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value1 << " " << curr->value2 << std::endl;
        curr = curr->next;
    }
}
