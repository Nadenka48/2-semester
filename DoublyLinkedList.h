#pragma once
#include <initializer_list>
#include <string>
#include <iostream>

/**
 * @brief Класс двусвязного списка целых чисел.
 */
class DoublyLinkedList
{
private:

    /**
     * @brief Узел списка.
     */
    struct Node
    {
        /**
        * @brief data Значение элемента списка
        */
        int data;
        /**
        * @brief prev Указатель на предыдущий узел
        */
        Node* prev;
        /**
        * @brief next Указатель на следующий узел
        */
        Node* next;


        Node(int value);
    };

    /**
    * @brief head Указатель на первый элемент списка
    */
    Node* head;
    /**
    * @brief tail Указатель на последний элемент списка
    */
    Node* tail;
    /**
    * @brief size Количество элементов в списке
    */
    size_t size;


    void clear(); ///< Очистка списка

public:

    /**
     * @brief Конструктор по умолчанию.
     */
    DoublyLinkedList();

    /**
     * @brief Конструктор со списком инициализации.
     */
    DoublyLinkedList(std::initializer_list<int> list);

    /**
     * @brief Деструктор.
     */
    ~DoublyLinkedList();

    /**
     * @brief Добавить элемент в конец.
     */
    void push_back(int value);

    /**
     * @brief Проверка наличия элемента.
     */
    bool contains(int value) const;

    /**
     * @brief Удалить первое вхождение элемента.
     */
    void remove(int value);

    /**
     * @brief Заменить значение oldValue на newValue.
     */
    void modify(int oldValue, int newValue);

    /**
     * @brief Проверка на пустоту.
     */
    bool empty() const;

    /**
     * @brief Получить размер списка.
     */
    size_t getSize() const;

    /**
     * @brief Преобразование в строку.
     */
    std::string toString() const;

    /**
     * @brief Оператор вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list);
};
