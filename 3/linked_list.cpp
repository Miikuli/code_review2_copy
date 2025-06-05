/*Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.
*/

#include "linked_list.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Clear();
}

void LinkedList::InsertSorted(int value) {
    Node* newNode = new Node(value);
    
    // Вставка в начало или если новый элемент больше головы
    if (head == nullptr || value > head->data) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    // Поиск места для вставки
    Node* current = head;
    while (current->next != nullptr && current->next->data > value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

bool LinkedList::DeleteValue(int value) {
    if (IsEmpty()) return false;

    // Удаление из головы
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    // Поиск элемента для удаления
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) return false;

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
    return true;
}

void LinkedList::Print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

bool LinkedList::IsEmpty() const {
    return head == nullptr;
}

void LinkedList::Clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

bool LinkedList::ReadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return false;
    }

    int N;
    file >> N;
    if (N <= 0) {
        std::cerr << "Некорректное количество элементов: " << N << std::endl;
        return false;
    }

    Clear(); // Очищаем существующий список

    int value;
    for (int i = 0; i < N; ++i) {
        if (!(file >> value)) {
            std::cerr << "Ошибка чтения данных" << std::endl;
            Clear();
            return false;
        }
        InsertSorted(value);
    }

    file.close();
    return true;
}
