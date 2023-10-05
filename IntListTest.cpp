#include <iostream>
#include "IntList.h"
using namespace std;

void old()
{
    IntList my_int_list = IntList();

    // test size()
    // cout << "At the beginning, the size of list is: " << my_int_list.size() << endl;

    // test is_empty()
    // cout << "At the beginning is_empty() returns: " << my_int_list.is_empty() << endl;

    // test push_head()
    // cout << "I will be pushing the head 3 times with values 7, 8, 9" << endl;
    my_int_list.push_head(7);
    my_int_list.push_head(8);
    my_int_list.push_head(9);

    // cout << "I expect the list to be 9, 8, 7" << endl;
    // my_int_list.print_list();
    // cout << "\n";

    // test prepend()
    // cout << "I will be prepending 6" << endl;
    my_int_list.prepend(6);
    // cout << "I expect the list to be 6, 9, 8, 7" << endl;
    // my_int_list.print_list();
    // cout << "\n";

    // test push_tail()
    // cout << "I will be pushing the tail with value 1" << endl;
    my_int_list.push_tail(1);
    // cout << "I expect the list to be 6, 9, 8, 7, 1" << endl;
    // my_int_list.print_list();
    // cout << "\n";

    // test append()
    // cout << "I will be appending 2" << endl;
    my_int_list.append(2);
    // cout << "I expect the list to be 6, 9, 8, 7, 1, 2" << endl;
    // my_int_list.print_list();
    // cout << "\n";

    // test insert()
    // test insert in empty list
    IntList empty_list = IntList();
    // cout << "I will be inserting 1 into an empty list" << endl;
    empty_list.insert(0, 1);
    // cout << "I expect the list to be 1" << endl;
    // empty_list.print_list();
    // cout << "\n";

    // create new list to test insert
    IntList new_list = IntList();
    new_list.push_head(1);
    new_list.push_head(2);
    new_list.push_head(3);
    new_list.push_head(4);
    new_list.push_head(5);

    // test insert at <= 0
    // cout << "I will be inserting 9 at index -1" << endl;
    new_list.insert(-1, 9);
    // cout << "I expect the list to be 9, 5, 4, 3, 2, 1" << endl;
    // new_list.print_list();
    // cout << "\n";

    // test insert at >= size
    // cout << "I will be inserting 12 at index 12" << endl;
    new_list.insert(12, 12);
    // cout << "I expect the list to be 9, 5, 4, 3, 2, 1, 12" << endl;
    // new_list.print_list();
    // cout << "\n";

    // test insert in middle
    // cout << "I will be inserting 8 at index 3" << endl;
    new_list.insert(3, 8);
    // cout << "I expect the list to be 9, 5, 4, 8, 3, 2, 1, 12" << endl;
    // new_list.print_list();
}

int main()
{
    // initialize list with 10 nodes
    IntList my_int_list = IntList();
    for (int i = 0; i < 10; i++)
    {
        my_int_list.push_head(i);
    }
    cout << "I expect the list to be 9, 8, 7, 6, 5, 4, 3, 2, 1, 0" << endl;
    my_int_list.print_list();
    cout << "\n";

    // test pop_head()
    cout << "I will be popping the head 2 times" << endl;
    cout << "The first pop returns: " << my_int_list.pop_head() << endl;
    cout << "The second pop returns: " << my_int_list.pop_head() << endl;
    cout << "I expect the list to be 7, 6, 5, 4, 3, 2, 1, 0" << endl;
    my_int_list.print_list();
    cout << "\n";

    // test pop_tail()
    cout << "I will be popping the tail 2 times" << endl;
    cout << "The first pop returns: " << my_int_list.pop_tail() << endl;
    cout << "The second pop returns: " << my_int_list.pop_tail() << endl;
    cout << "I expect the list to be 7, 6, 5, 4, 3, 2" << endl;
    my_int_list.print_list();
    cout << "\n";

    // test get()
    cout << "I will be getting the value at index 3" << endl;
    cout << "I expect the value to be 4" << endl;
    cout << "The value at index 3 is: " << my_int_list.get(3) << endl;
    cout << "\n";

    // test remove()
    cout << "I will be removing the value at index 3" << endl;
    cout << "I expect the list to be 7, 6, 5, 3, 2" << endl;
    cout << "The value removed is: " << my_int_list.remove(3) << endl;
    my_int_list.print_list();
    cout << "\n";

    cout << "I will be removing the value at index 0" << endl;
    cout << "I expect the list to be 6, 5, 3, 2" << endl;
    cout << "The value removed is: " << my_int_list.remove(0) << endl;
    my_int_list.print_list();
    cout << "\n";

    cout << "I will be removing the value at index 3" << endl;
    cout << "I expect the list to be 6, 5, 2" << endl;
    cout << "The value removed is: " << my_int_list.remove(2) << endl;
    my_int_list.print_list();

    return 0;
}
