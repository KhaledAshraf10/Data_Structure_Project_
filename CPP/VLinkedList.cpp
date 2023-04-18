#include "../Headers/VLinkedList.h"
#include <iostream>

VLinkedList::VLinkedList() {
    head = nullptr;
}

void VLinkedList::insert(int val1, int val2) {
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

void VLinkedList::printList() {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value1 << " " << curr->value2 << std::endl;
        curr = curr->next;
    }
}
