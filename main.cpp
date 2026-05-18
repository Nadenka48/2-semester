#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList list{ 1, 2, 3, 4 };

    list.push_front(0);
    list.push_back(5);
    list.remove(3);
    list.modify(4, 40);

    std::cout << "List: " << list << std::endl;

    return 0;
}
