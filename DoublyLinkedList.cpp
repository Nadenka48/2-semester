#include "DoublyLinkedList.h"
#include <sstream>
#include <stdexcept>

/* ================= Node ================= */

DoublyLinkedList::Node::Node(int value)
    : data(value), prev(nullptr), next(nullptr)
{
}

/* ================= Constructors ================= */

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr), size(0)
{
}

DoublyLinkedList::DoublyLinkedList(std::initializer_list<int> list)
    : head(nullptr), tail(nullptr), size(0)
{
    for (int value : list)
        push_back(value);
}

/* ================= Destructor ================= */

DoublyLinkedList::~DoublyLinkedList()
{
    clear();
}

/* ================= Private ================= */

void DoublyLinkedList::clear()
{
    Node* current = head;

    while (current)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    size = 0;
}

/* ================= Public ================= */

void DoublyLinkedList::push_back(int value)
{
    Node* newNode = new Node(value);

    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    size++;
}

bool DoublyLinkedList::contains(int value) const
{
    Node* current = head;

    while (current)
    {
        if (current->data == value)
            return true;

        current = current->next;
    }

    return false;
}

void DoublyLinkedList::remove(int value)
{
    Node* current = head;

    while (current)
    {
        if (current->data == value)
        {
            if (current->prev)
                current->prev->next = current->next;
            else
                head = current->next;

            if (current->next)
                current->next->prev = current->prev;
            else
                tail = current->prev;

            delete current;
            size--;
            return;
        }

        current = current->next;
    }
}

void DoublyLinkedList::modify(int oldValue, int newValue)
{
    Node* current = head;

    while (current)
    {
        if (current->data == oldValue)
        {
            current->data = newValue;
            return;
        }

        current = current->next;
    }
}

bool DoublyLinkedList::empty() const
{
    return size == 0;
}

size_t DoublyLinkedList::getSize() const
{
    return size;
}

std::string DoublyLinkedList::toString() const
{
    std::ostringstream ss;
    Node* current = head;

    while (current)
    {
        ss << current->data;

        if (current->next)
            ss << " ";

        current = current->next;
    }

    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list)
{
    os << list.toString();
    return os;
}
