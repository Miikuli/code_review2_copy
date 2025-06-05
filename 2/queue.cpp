#include "queue.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::initialize() {
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue(int number) {
    Node* newNode = new Node;
    newNode->value = number;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (head == nullptr) {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
        tail = nullptr;
    }
}

void Queue::print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Queue::printPointers() {
    std::cout << "Адрес начала: " << head;
    if (head != nullptr) {
        std::cout << " (значение: " << head->value << ")";
    }
    std::cout << std::endl;

    std::cout << "Адрес конца: " << tail;
    if (tail != nullptr) {
        std::cout << " (значение: " << tail->value << ")";
    }
    std::cout << std::endl;
}
