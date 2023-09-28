#include <iostream>
#include "IntList.h"
using namespace std;

int main()
{
    IntList my_int_list = IntList();

    // Show current state
    cout << "At the beginning, the size of list is: " << my_int_list.size() << endl;

    cout << "At the beginning is_empty() returns: " << my_int_list.is_empty() << endl;

    my_int_list.push_head(7);
    my_int_list.push_head(8);
    my_int_list.push_head(9);

    cout << "I expect the list to be 9, 8, 7" << endl;
    my_int_list.print_list();

    my_int_list.push_tail(1);
    cout << "I expect the list to be 9, 8, 7, 1" << endl;
    my_int_list.print_list();
}