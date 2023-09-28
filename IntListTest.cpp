#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
    IntList my_int_list = IntList();

    // test size()
    cout << "At the beginning, the size of list is: " << my_int_list.size() << endl;

    // test is_empty()
    cout << "At the beginning is_empty() returns: " << my_int_list.is_empty() << endl;

    // test push_head()
    my_int_list.push_head(7);
    my_int_list.push_head(8);
    my_int_list.push_head(9);

    cout << "I expect the list to be 9, 8, 7" << endl;
    my_int_list.print_list();

    // test prepend()
    my_int_list.prepend(6);
    cout << "I expect the list to be 6, 9, 8, 7" << endl;
    my_int_list.print_list();

    // test push_tail()
    my_int_list.push_tail(1);
    cout << "I expect the list to be 9, 8, 7, 1" << endl;
    my_int_list.print_list();

    // test append()
    my_int_list.append(2);
    cout << "I expect the list to be 9, 8, 7, 1, 2" << endl;
    my_int_list.print_list();

    // test insert()
    // test insert in empty list
    IntList empty_list = IntList();
    empty_list.insert(0, 1);
    cout << "I expect the list to be 1" << endl;
    empty_list.print_list();

    // create new list to test insert
    IntList new_list = IntList();
    new_list.push_head(1);
    new_list.push_head(2);
    new_list.push_head(3);
    new_list.push_head(4);
    new_list.push_head(5);

    // test insert at <= 0
    new_list.insert(-1, 9);
    cout << "I expect the list to be 9, 5, 4, 3, 2, 1" << endl;
    new_list.print_list();

    // test insert at >= size
    new_list.insert(12, 12);
    cout << "I expect the list to be 9, 5, 4, 3, 2, 1, 12" << endl;
    new_list.print_list();

    // test insert in middle
    new_list.insert(3, 8);
    cout << "I expect the list to be 9, 5, 4, 8, 3, 2, 1, 12" << endl;
    new_list.print_list();
}
