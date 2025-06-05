/*Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.
Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "linked_list.h"

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::InsertSorted(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr || head->data < value) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data > value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void LinkedList::Print() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::ReadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    int N;
    file >> N;

    int value;
    for (int i = 0; i < N; ++i) {
        file >> value;
        InsertSorted(value);
    }

    file.close();
}

void readFromFile(LinkedList& list, const std::string& filename) {
    list.readFromFile(filename);
}
