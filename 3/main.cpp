#include "linked_list.h"
#include <iostream>
#include <string>

int main() {
    LinkedList list;
    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    ReadFromFile(list, filename);

    std::cout << "Упорядоченный список: ";
    list.Print();

    return 0;
}
