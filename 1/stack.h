#ifndef STACK_H
#define STACK_H

#include <iostream>

/**
 * @class Node
 * @brief Узел стека
 * 
 * Содержит данные и указатель на следующий узел
 */
class Node {
public:
    int data;       ///< Значение узла
    Node* next;     ///< Указатель на следующий узел
    
    /**
     * @brief Конструктор узла
     * @param value Значение для хранения в узле
     */
    Node(int value);
};

/**
 * @class Stack
 * @brief Класс стека, реализованный на связном списке
 * 
 * Предоставляет стандартные операции работы со стеком: push, pop, peek и другие
 */
class Stack {
private:
    Node* top;  ///< Указатель на вершину стека

public:
    /**
     * @brief Конструктор стека
     */
    Stack();
    
    /**
     * @brief Деструктор стека
     * 
     * Автоматически очищает память при уничтожении стека
     */
    ~Stack();
    
    /**
     * @brief Добавление элемента в стек
     * @param value Значение для добавления
     */
    void push(int value);
    
    /**
     * @brief Удаление элемента из стека
     * 
     * Удаляет и возвращает элемент с вершины стека
     */
    void pop();
    
    /**
     * @brief Вывод содержимого стека
     * 
     * Выводит все элементы стека, начиная с вершины
     */
    void print();
    
    /**
     * @brief Получение указателя на вершину стека
     * @return Указатель на вершину стека
     */
    Node* getTop();
    
    /**
     * @brief Очистка стека
     * 
     * Удаляет все элементы из стека и освобождает память
     */
    void clearStack();
    
    /**
     * @brief Дружественная функция для добавления элемента и вывода адреса вершины
     * @param stack Стек для работы
     * @param D Значение для добавления
     */
    friend void addElementAndPrintAddress(Stack& stack, int D);
};

/**
 * @brief Добавляет элемент в стек и выводит адрес новой вершины
 * @param stack Стек для работы
 * @param D Значение для добавления
 */
void addElementAndPrintAddress(Stack& stack, int D);

#endif // STACK_H
