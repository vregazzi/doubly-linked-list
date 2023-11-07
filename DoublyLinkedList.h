#include <iostream>
#include <stdexcept>
template <typename T>
class DoublyLinkedList

{
private:
    class Node
    {
    public:
        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
        int value;
        Node *next;
        Node *prev;
    };

    int m_size;
    Node *m_head;
    Node *m_tail;
    unsigned int calls;
    unsigned int links_followed;
    unsigned long nano_seconds_running;

    void insert_very_first_node(Node *node_to_insert)
    {
        node_to_insert->next = nullptr;
        node_to_insert->prev = nullptr;

        m_head = node_to_insert;
        m_tail = node_to_insert;

        m_size++;
    }

    void insert_new_head(Node *node_to_insert)
    {
        node_to_insert->next = m_head;
        node_to_insert->prev = nullptr;

        m_head->prev = node_to_insert;
        m_head = node_to_insert;

        m_size++;
    }

    void insert_new_tail(Node *node_to_insert)
    {
        node_to_insert->next = nullptr;
        node_to_insert->prev = m_tail;

        m_tail->next = node_to_insert;
        m_tail = node_to_insert;

        m_size++;
    }

    void insert_between_nodes(Node *previous_node, Node *next_node, Node *node_to_insert)
    {
        node_to_insert->next = next_node;
        node_to_insert->prev = previous_node;

        previous_node->next = node_to_insert;
        next_node->prev = node_to_insert;

        m_size++;
    }

    T remove_only_node()
    {
        Node *node_to_free = m_head;
        T value_to_return = node_to_free->value;

        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;

        delete node_to_free;
        return value_to_return;
    }

    T remove_head()
    {
        if (size() < 2)
        {
            throw std::out_of_range("remove_head should be done on list with size >= 2");
        }

        Node *node_to_free = m_head;
        T value_to_return = node_to_free->value;
        m_size--;

        m_head = m_head->next;
        m_head->prev = nullptr;

        delete node_to_free;
        return value_to_return;
    }

    T remove_tail()
    {
        if (size() < 2)
        {
            throw std::out_of_range("remove_tail should be done on list with size >= 2");
        }

        Node *node_to_free = m_tail;
        T value_to_return = node_to_free->value;
        m_size--;

        m_tail = m_tail->prev;
        m_tail->next = nullptr;

        delete node_to_free;
        return value_to_return;
    }

    T remove_node(Node *node_to_remove)
    {
        int value_to_return = node_to_remove->value;
        Node *previous_node = node_to_remove->prev;
        Node *next_node = node_to_remove->next;

        previous_node->next = next_node;
        next_node->prev = previous_node;

        delete node_to_remove;
        m_size--;

        return value_to_return;
    }

    Node *find_node(int position)
    {
        auto start = std::chrono::high_resolution_clock::now();
        calls++;
        int current_position = 0;
        Node *current_node = m_head;

        while (current_position < position)
        {
            current_node = current_node->next;
            current_position++;
            links_followed++;
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        nano_seconds_running += duration.count();

        return current_node;
    }

public:
    DoublyLinkedList()
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
        calls = 0;
        links_followed = 0;
        nano_seconds_running = 0;
    }

    ~DoublyLinkedList()
    {
        report_stats();
        Node *list_head = new Node(0);
        while (list_head->next != 0)
        {
            Node *nextNode = list_head->next;
            list_head->next = nextNode->next;
            delete nextNode;
        }
        // delete list_head;
    }

    int size() const
    {
        return m_size;
    }

    bool is_empty() const
    {
        return size() == 0;
    }

    void push_head(T value)
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

    void push_tail(T value)
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

    void prepend(T value)
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

    void append(T value)
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

    void insert(int position, T value)
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

            Node *previous_node = find_node(position - 1);
            Node *next_node = find_node(position) + 1;

            insert_between_nodes(previous_node, next_node, node_to_insert);
        }
    }

    T pop_head()
    {
        if (size() <= 0)
        {
            throw std::out_of_range("pop_head called on empty list");
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

    T pop_tail()
    {
        if (size() <= 0)
        {
            throw std::out_of_range("pop_tail called on empty list");
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

    T get(int position)
    {
        if (position < 0 || position > size() - 1)
        {
            throw std::out_of_range("get called with out of range position");
        }
        else
        {
            Node *current_node = find_node(position);

            return current_node->value;
        }
    }

    T remove(int position)
    {
        if (position < 0)
        {
            throw std::out_of_range("out of range");
        }
        else if (position >= size())
        {
            throw std::out_of_range("out of range");
        }
        else if (position == 0)
        {
            return pop_head();
        }
        else if (position == size() - 1)
        {
            return pop_tail();
        }
        else if (size() == 1)
        {
            return remove_only_node();
        }
        else
        {
            Node *node_to_remove = find_node(position);
            return remove_node(node_to_remove);
        }
    }

    T set(int position, T value)
    {
        if (position < 0 || position >= size())
        {
            throw std::out_of_range("set called with out of range position");
        }
        else
        {
            Node *current_node = find_node(position);
            int value_to_return = current_node->value;
            current_node->value = value;

            return value_to_return;
        }
    }

    void report_stats()
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Stats" << std::endl;
        std::cout << "Number of calls to find_node: " << calls << std::endl;
        std::cout << "Number of link follows: " << links_followed << std::endl;
        std::cout << "Average number of link follows for a call to find_node: " << links_followed / calls << std::endl;
        std::cout << "Average time for a call to find_node: " << nano_seconds_running / calls << " nanoseconds" << std::endl;
        std::cout << "End Stats" << std::endl;
        std::cout << "--------------------" << std::endl;
    }
};
