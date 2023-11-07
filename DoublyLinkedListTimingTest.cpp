#include <iostream>
#include <stdexcept>
#include <sstream>
#include <cassert>
#include <random>
#include "DoublyLinkedList.h"

using namespace std;

void test_list_timing()
{
    // Create a DoublyLinkedList of items of type int
    DoublyLinkedList<int> my_list_of_ints;

    // Add 1,000 random values by pushing on to the front.
    random_device dev;
    mt19937 random_number_generator(dev());
    uniform_int_distribution<mt19937::result_type> value_dist(1, 1000);
    uniform_int_distribution<mt19937::result_type> location_dist(1, 3000);

    for (int i = 0; i < 1000; ++i)
    {
        int value = value_dist(random_number_generator);
        cout << i << " push_head(value: " << value << ")" << endl;
        my_list_of_ints.push_head(value);
    }

    // Add 1,000 random values by pushing on to the back.
    for (int i = 0; i < 1000; ++i)
    {
        int value = value_dist(random_number_generator);
        cout << i << " push_tail(value: " << value << ")" << endl;
        my_list_of_ints.push_tail(value);
    }

    // Insert 1,000 random values at random locations
    for (int i = 0; i < 1000; ++i)
    {
        int value = value_dist(random_number_generator);
        int position = location_dist(random_number_generator);
        cout << i << " insert(position: " << position << ", value: " << value << ")" << endl;
        my_list_of_ints.insert(position, value);

        if (position > my_list_of_ints.size() - 1)
        {
            assert(my_list_of_ints.get(my_list_of_ints.size() - 1) == value);
        }
        else
        {
            assert(my_list_of_ints.get(position) == value);
        }
    }

    return;
}

int main()
{
    test_list_timing();
    return 0;
}