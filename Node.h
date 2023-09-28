#pragma once

class Node
{
public:
    Node(int val = 0) : value(val), next(nullptr), prev(nullptr) {}
    int value;
    Node *next;
    Node *prev;
};