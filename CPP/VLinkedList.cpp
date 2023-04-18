#include "../Headers/VLinkedList.h"
#include <iostream>

VLinkedList::VLinkedList() {
    head = nullptr;
}

void VLinkedList::insert(int val1, int val2) {
    Node2* newNode = new Node2;
    newNode->value1 = val1;
    newNode->value2 = val2;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node2* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void VLinkedList::printList() {
    Node2* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value1 << " " << curr->value2 << std::endl;
        curr = curr->next;
    }
}
