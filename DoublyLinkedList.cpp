#include "DoublyLinkedList.h"
#include <sstream>
#include <stdexcept>

DoublyLinkedList::Node::Node(const int value)
: data(value), prev(nullptr), next(nullptr)
{
}

DoublyLinkedList::DoublyLinkedList()
: head(nullptr), tail(nullptr), size(0)
{
}

DoublyLinkedList::DoublyLinkedList(const std::initializer_list<int> list)
: head(nullptr), tail(nullptr), size(0)
{
for (int value : list)
push_back(value);
}

DoublyLinkedList::~DoublyLinkedList()
{
clear();
}


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


void DoublyLinkedList::push_back(const int value)
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

bool DoublyLinkedList::contains(const int value) const
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

void DoublyLinkedList::remove(const int value)
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

void DoublyLinkedList::modify(const int oldValue, const int newValue)
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
