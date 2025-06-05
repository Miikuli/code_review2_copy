/*
Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать 
разными способами (с клавиатуры, рандом, из файла)

Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее
двух элементов, количество элементов является четным. Поменять значения двух средних
элементов каждого из исходных контейнеров. Использовать алгоритм swap (не путать его с
одноименной функцией-членом контейнера).
*/

#include "containers.h"
#include <limits>

void printMenu() {
    std::cout << "\nChoose input method:\n"
              << "1. Keyboard input\n"
              << "2. Random generation\n"
              << "3. Read from file\n"
              << "Your choice: ";
}

void processContainer(const std::string& containerName) {
    std::vector<int> vec;
    std::deque<int> deq;
    std::list<int> lst;

    size_t size;
    int method;

    std::cout << "\n=== Processing " << containerName << " ===";
    
    while (true) {
        std::cout << "\nEnter size (even >=2): ";
        if (!(std::cin >> size) || size < 2 || size % 2 != 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid size. Must be even number >= 2\n";
            continue;
        }
        break;
    }

    while (true) {
        printMenu();
        if (!(std::cin >> method) || method < 1 || method > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid choice. Please enter 1-3\n";
            continue;
        }
        break;
    }

    bool success = false;
    if (containerName == "vector") {
        success = ContainerUtils::FillContainer(vec, size, static_cast<ContainerUtils::InputMethod>(method));
    } else if (containerName == "deque") {
        success = ContainerUtils::FillContainer(deq, size, static_cast<ContainerUtils::InputMethod>(method));
    } else {
        success = ContainerUtils::FillContainer(lst, size, static_cast<ContainerUtils::InputMethod>(method));
    }

    if (!success) {
        std::cerr << "Failed to fill container\n";
        return;
    }

    std::cout << "\n" << containerName << " contents:\n";
    if (containerName == "vector") {
        ContainerUtils::PrintContainer(vec);
        std::cout << "Reversed: ";
        ContainerUtils::PrintReverse(vec);
        ContainerUtils::SwapMiddleElements(vec);
        std::cout << "After swap: ";
        ContainerUtils::PrintContainer(vec);
    } else if (containerName == "deque") {
        ContainerUtils::PrintContainer(deq);
        std::cout << "Reversed: ";
        ContainerUtils::PrintReverse(deq);
        ContainerUtils::SwapMiddleElements(deq);
        std::cout << "After swap: ";
        ContainerUtils::PrintContainer(deq);
    } else {
        ContainerUtils::PrintContainer(lst);
        std::cout << "Reversed: ";
        ContainerUtils::PrintReverse(lst);
        ContainerUtils::SwapMiddleElements(lst);
        std::cout << "After swap: ";
        ContainerUtils::PrintContainer(lst);
    }
}

int main() {
    std::cout << "=== Container Processing Program ===\n";

    processContainer("vector");
    processContainer("deque");
    processContainer("list");

    std::cout << "\nProgram completed successfully.\n";
    return 0;
}
