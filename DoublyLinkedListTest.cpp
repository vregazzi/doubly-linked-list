#include <iostream>
#include <cassert>
#include "DoublyLinkedList.h"
using namespace std;

template <typename T>
void print_list(DoublyLinkedList<T> list)
{
    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        cout << list.get(i) << endl;
    }
}

void testIntFunctions()
{
    cout << "Testing functions on int list" << endl;
    // initialize a list of ints
    DoublyLinkedList<int> my_list_of_ints = DoublyLinkedList<int>();

    // test initial state
    cout << "Testing initial state" << endl;
    assert(my_list_of_ints.size() == 0);
    assert(my_list_of_ints.is_empty() == true);

    // test push_head
    my_list_of_ints.push_head(0);
    my_list_of_ints.push_head(1);
    my_list_of_ints.push_head(2);
    my_list_of_ints.push_head(3);
    my_list_of_ints.push_head(4);

    cout << "Testing push_head" << endl;
    array<int, 5> expected_head_values = {4, 3, 2, 1, 0};
    for (int i = 0; i < 5; i++)
    {
        assert(my_list_of_ints.get(i) == expected_head_values[i]);
    }

    // test push_tail
    my_list_of_ints.push_tail(5);
    my_list_of_ints.push_tail(6);
    my_list_of_ints.push_tail(7);
    my_list_of_ints.push_tail(8);
    my_list_of_ints.push_tail(9);

    cout << "Testing push_tail" << endl;
    array<int, 5> expected_tail_values = {5, 6, 7, 8, 9};
    for (int i = 0; i < 5; i++)
    {
        assert(my_list_of_ints.get(i + 5) == expected_tail_values[i]);
    }

    cout << "Testing is_empty()" << endl;
    assert(my_list_of_ints.is_empty() == false);

    cout << "Testing size()" << endl;
    assert(my_list_of_ints.size() == 10);

    cout << "Testing pop_head()" << endl;
    assert(my_list_of_ints.pop_head() == 4);

    cout << "Testing pop_tail()" << endl;
    assert(my_list_of_ints.pop_tail() == 9);

    cout << "Testing get()" << endl;
    assert(my_list_of_ints.get(0) == 3);

    cout << "Testing remove()" << endl;
    assert(my_list_of_ints.remove(5) == 6);

    cout << "Testing set()" << endl;
    assert(my_list_of_ints.set(0, 10) == 3);

    cout << "Testing print_list()" << endl;
    print_list(my_list_of_ints);
    cout << "All tests passed!\n"
         << endl;
}

void testCharFunctions()
{
    cout << "Testing functions on char list" << endl;
    // initialize a list of chars
    DoublyLinkedList<char> my_list_of_chars = DoublyLinkedList<char>();

    // test initial state
    cout << "Testing initial state" << endl;
    assert(my_list_of_chars.size() == 0);
    assert(my_list_of_chars.is_empty() == true);

    // test push_head
    my_list_of_chars.push_head('a');
    my_list_of_chars.push_head('b');
    my_list_of_chars.push_head('c');
    my_list_of_chars.push_head('d');
    my_list_of_chars.push_head('e');

    cout << "Testing push_head" << endl;
    array<char, 5> expected_head_values = {'e', 'd', 'c', 'b', 'a'};
    for (int i = 0; i < 5; i++)
    {
        assert(my_list_of_chars.get(i) == expected_head_values[i]);
    }

    // test push_tail
    my_list_of_chars.push_tail('f');
    my_list_of_chars.push_tail('g');
    my_list_of_chars.push_tail('h');
    my_list_of_chars.push_tail('i');
    my_list_of_chars.push_tail('j');

    cout << "Testing push_tail" << endl;
    array<char, 5> expected_tail_values = {'f', 'g', 'h', 'i', 'j'};
    for (int i = 0; i < 5; i++)
    {
        assert(my_list_of_chars.get(i + 5) == expected_tail_values[i]);
    }

    cout << "Testing is_empty()" << endl;
    assert(my_list_of_chars.is_empty() == false);

    cout << "Testing size()" << endl;
    assert(my_list_of_chars.size() == 10);

    cout << "Testing pop_head()" << endl;
    assert(my_list_of_chars.pop_head() == 'e');

    cout << "Testing pop_tail()" << endl;
    assert(my_list_of_chars.pop_tail() == 'j');

    cout << "Testing get()" << endl;
    assert(my_list_of_chars.get(0) == 'd');

    cout << "Testing remove()" << endl;
    assert(my_list_of_chars.remove(5) == 'g');

    cout << "Testing set()" << endl;
    assert(my_list_of_chars.set(0, 'k') == 'd');

    cout << "Testing print_list()" << endl;
    print_list(my_list_of_chars);
    cout << "All tests passed!" << endl;
}

int main()
{
    testIntFunctions();
    testCharFunctions();
    return 0;
}