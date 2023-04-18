#pragma once

struct Node2 {
    int value1;
    int value2;
    Node2* next;
};

class VLinkedList {
private:
    Node2* head;

public:
    VLinkedList();
    void insert(int val1, int val2);
    void printList();
};
