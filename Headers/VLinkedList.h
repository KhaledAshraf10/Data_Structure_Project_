#pragma once

struct Node {
    int value1;
    int value2;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(int val1, int val2);
    void printList();
};
