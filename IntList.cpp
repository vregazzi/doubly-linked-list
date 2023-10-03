#include <iostream>
#include <stdexcept>
#include "IntList.h"
using namespace std;

IntList::IntList()
{
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

int IntList::size() const
{
    return m_size;
}

bool IntList::is_empty() const
{
    return size() == 0;
}

void IntList::print_list() const
{
    Node *node_to_print = m_head;

    while (node_to_print != nullptr)
    {
        cout << "Node: " << node_to_print->value << endl;
        node_to_print = node_to_print->next;
    }
}

void IntList::insert_very_first_node(Node *node_to_insert)
{
    node_to_insert->next = nullptr;
    node_to_insert->prev = nullptr;

    m_head = node_to_insert;
    m_tail = node_to_insert;

    m_size++;
}

void IntList::insert_new_head(Node *node_to_insert)
{
    node_to_insert->next = m_head;
    node_to_insert->prev = nullptr;

    m_head->prev = node_to_insert;
    m_head = node_to_insert;

    m_size++;
}

void IntList::insert_new_tail(Node *node_to_insert)
{
    node_to_insert->next = nullptr;
    node_to_insert->prev = m_tail;

    m_tail->next = node_to_insert;
    m_tail = node_to_insert;

    m_size++;
}

void IntList::push_head(int value)
{
    Node *node_to_insert = new Node(value);
    node_to_insert->value = value;

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        insert_new_head(node_to_insert);
    }
}

void IntList::push_tail(int value)
{
    Node *node_to_insert = new Node(value);
    node_to_insert->value = value;

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        insert_new_tail(node_to_insert);
    }
}

void IntList::insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert)
{
    node_to_insert->next = next_node;
    node_to_insert->prev = previous_node;

    previous_node->next = node_to_insert;
    next_node->prev = node_to_insert;

    m_size++;
}

void IntList::prepend(int value)
{
    Node *node_to_insert = new Node(value);
    node_to_insert->value = value;

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        push_head(value);
    }
}

void IntList::append(int value)
{
    Node *node_to_insert = new Node(value);
    node_to_insert->value = value;

    if (is_empty())
    {
        insert_very_first_node(node_to_insert);
    }
    else
    {
        push_tail(value);
    }
}

void IntList::insert(int position, int value)
{
    if (is_empty())
    {
        insert_very_first_node(new Node(value));
        return;
    }
    else if (position <= 0)
    {
        push_head(value);
        return;
    }
    else if (position >= size())
    {
        push_tail(value);
        return;
    }
    else
    {
        Node *node_to_insert = new Node(value);
        node_to_insert->value = value;

        Node *previous_node = m_head;
        Node *next_node = m_head->next;

        for (int i = 0; i < position - 1; i++)
        {
            previous_node = next_node;
            next_node = next_node->next;
        }

        insert_between_nodes(previous_node, next_node, node_to_insert);
    }
}

int IntList::remove_only_node()
{
    Node *node_to_free = m_head;
    int value_to_return = node_to_free->value;

    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;

    delete node_to_free;
    return value_to_return;
}

int IntList::remove_head()
{
    if (size() < 2)
    {
        throw out_of_range("remove_head should be done on list with size >= 2");
    }

    Node *node_to_free = m_head;
    int value_to_return = node_to_free->value;
    m_size--;

    m_head = m_head->next;
    m_head->prev = nullptr;

    delete node_to_free;
    return value_to_return;
}

int IntList::remove_tail()
{
    if (size() < 2)
    {
        throw out_of_range("remove_tail should be done on list with size >= 2");
    }

    Node *node_to_free = m_tail;
    int value_to_return = node_to_free->value;
    m_size--;

    m_tail = m_tail->prev;
    m_tail->next = nullptr;

    delete node_to_free;
    return value_to_return;
}

int IntList::pop_head()
{
    if (size() <= 0)
    {
        throw out_of_range("pop_head called on empty list");
    }
    else if (size() == 1)
    {
        return remove_only_node();
    }
    else
    {
        return remove_head();
    }
}

int IntList::pop_tail()
{
    if (size() <= 0)
    {
        throw out_of_range("pop_tail called on empty list");
    }
    else if (size() == 1)
    {
        return remove_only_node();
    }
    else
    {
        return remove_tail();
    }
}

int IntList::get(int position)
{
    if (position < 0 || position > size() - 1)
    {
        throw out_of_range("get called with out of range position");
    }
    else
    {
        int current_position = 0;
        Node *current_node = m_head;

        while (current_position < position)
        {
            current_position++;
            current_node = current_node->next;
        }

        return current_node->value;
    }
}

int IntList::remove(int position)
{
    if (position < 0 || position >= size())
    {
        throw out_of_range("out of range");
    }
    else if (size() == 1)
    {
        return remove_only_node();
    }
    // add more
}

int IntList::remove_node(Node *node_to_remove)
{
    // if position < 0, throw exception
    // if position >= size of list, throw exception
    // if position is 0, pop the front element
    // if position is size-1, pop the back element
    // otherwise, you know the list has at least 3
    // elements. Find the node to remove and use your
    // utility function
}