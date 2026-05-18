#include "pch.h"
#include "DoublyLinkedList.h"
#include <cassert>

void TestList()
{
    DoublyLinkedList list{ 1,2,3 };

    assert(list.contains(2));
    assert(!list.contains(10));

    list.remove(2);
    assert(!list.contains(2));

    list.modify(3, 30);
    assert(list.contains(30));

    assert(!list.empty());
}
