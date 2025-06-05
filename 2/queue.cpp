/* Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из
исходного набора с нечетными номерами (1, 3, …, 9), а вторая — с четными (2, 4, …, 10);
порядок чисел в каждой очереди должен совпадать с порядком чисел в исходном наборе.
Вывести указатели на начало и конец первой, а затем второй очереди.
Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.
*/

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

void Queue::Initialize() {
    head = nullptr;
    tail = nullptr;
}

void Queue::Enqueue(int number) {
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

void Queue::Dequeue() {
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

void Queue::Print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Queue::PrintPointers() {
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
