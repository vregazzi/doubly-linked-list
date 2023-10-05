#pragma once

class IntList
{
public:
    IntList();
    int size() const;
    bool is_empty() const;
    void print_list() const;
    void push_head(int value);
    void push_tail(int value);
    void prepend(int value);
    void append(int value);
    void insert(int position, int value);
    int pop_head();
    int pop_tail();
    int get(int position);
    int remove(int position);

private:
    class Node
    {
    public:
        Node(int val = 0) : value(val), next(nullptr), prev(nullptr) {}
        int value;
        Node *next;
        Node *prev;
    };

    int m_size;
    Node *m_head;
    Node *m_tail;
    void insert_very_first_node(Node *node_to_insert);
    void insert_new_head(Node *node_to_insert);
    void insert_new_tail(Node *node_to_insert);
    void insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert);
    int remove_only_node();
    int remove_head();
    int remove_tail();
    int remove_node(Node *node_to_remove);
};
