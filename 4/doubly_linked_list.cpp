/*
Дан двусвязный линейный список и указатель первый элемент этого 
списка. Все элементы списка хранят различные между собой значения. Необходимо 
вывести значения элементов списка, которые находятся между наименьшим и 
наибольшим элементами списка, в том порядке, в каком они находятся в исходном 
списке. Использовать процедуры. 

Все динамические структуры данных реализовывать через классы. Не использовать STL.  
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Clear();
}

void DoublyLinkedList::Append(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
    newNode->prev = current;
}

void DoublyLinkedList::Print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::FindMinMax(Node*& min, Node*& max) const {
    if (head == nullptr) return;

    min = max = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->value < min->value) min = current;
        if (current->value > max->value) max = current;
        current = current->next;
    }
}

bool DoublyLinkedList::IsFirstBeforeSecond(Node* first, Node* second) const {
    Node* current = head;
    while (current != nullptr) {
        if (current == first) return true;
        if (current == second) return false;
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::PrintBetweenMinMax() const {
    Node* min = nullptr;
    Node* max = nullptr;
    FindMinMax(min, max);

    if (min == nullptr || max == nullptr || min == max) {
        std::cout << "Нет элементов для вывода!" << std::endl;
        return;
    }

    bool minFirst = IsFirstBeforeSecond(min, max);
    Node* start = minFirst ? min : max;
    Node* end = minFirst ? max : min;

    std::cout << "Элементы между " << min->value << " и " << max->value << ": ";
    Node* current = start->next;
    bool hasElements = false;

    while (current != nullptr && current != end) {
        std::cout << current->value << " ";
        hasElements = true;
        current = current->next;
    }

    if (!hasElements) std::cout << "Отсутствуют";
    std::cout << std::endl;
}

void DoublyLinkedList::Clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
