#pragma once

#include "Node.h"

class IntList
{
public:
    IntList() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    int size() const;
    bool is_empty() const;
    void print_list() const;
    void push_head(int value);
    void push_tail(int value);
    void prepend(int value);
    void append(int value);
    void insert(int position, int value);

private:
    int m_size;
    Node *m_head;
    Node *m_tail;
    void insert_very_first_node(Node *node_to_insert);
    void insert_new_head(Node *node_to_insert);
    void insert_new_tail(Node *node_to_insert);
    void insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert);
};
