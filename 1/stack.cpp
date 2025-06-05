#include "stack.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr) {}

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    clearStack();
}

void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    std::cout << "Элемент " << value << " добавлен в стек." << std::endl;
}

void Stack::pop() {
    if (top == nullptr) {
        std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    std::cout << "Элемент " << temp->data << " удален из стека." << std::endl;
    delete temp;
}

void Stack::print() {
    if (top == nullptr) {
        std::cout << "Стек пуст!" << std::endl;
        return;
    }
    Node* current = top;
    std::cout << "Элементы стека: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* Stack::getTop() {
    return top;
}

void Stack::clearStack() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    std::cout << "Стек очищен." << std::endl;
}

void addElementAndPrintAddress(Stack& stack, int D) {
    stack.push(D);
    std::cout << "Адрес новой вершины стека: " << stack.getTop() << std::endl;
}
