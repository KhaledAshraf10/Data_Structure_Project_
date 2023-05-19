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
    int getValue1At(int position);
    int getValue2At(int position);
    int getSize();
    bool containsValue1(int value);
};
