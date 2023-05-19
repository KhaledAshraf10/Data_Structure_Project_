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
int VLinkedList::getValue1At(int position) {
    if (position < 0) {
        throw std::out_of_range("Invalid position");
    }

    Node2* curr = head;
    int currentPosition = 0;

    while (curr != nullptr && currentPosition < position) {
        curr = curr->next;
        currentPosition++;
    }

    if (curr == nullptr) {
        throw std::out_of_range("Position out of range");
    }

    return curr->value1; // Return the desired value (e.g., value1)
}
int VLinkedList::getValue2At(int position) {
    if (position < 0) {
        throw std::out_of_range("Invalid position");
    }

    Node2* curr = head;
    int currentPosition = 0;

    while (curr != nullptr && currentPosition < position) {
        curr = curr->next;
        currentPosition++;
    }

    if (curr == nullptr) {
        throw std::out_of_range("Position out of range");
    }

    return curr->value2; // Return the desired value (e.g., value1)
}
int VLinkedList::getSize() {
    int count = 0;
    Node2* curr = head;

    while (curr != nullptr) {
        count++;
        curr = curr->next;
    }

    return count;
}
bool VLinkedList::containsValue1(int value) {
    Node2* curr = head;
    while (curr != nullptr) {
        if (curr->value1 == value) {
            return true; // Found a node with value1 equal to the given value
        }
        curr = curr->next;
    }
    return false; // No node with value1 equal to the given value found
}


