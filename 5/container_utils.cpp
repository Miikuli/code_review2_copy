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


#include "container_utils.h"

template <typename Container>
bool FillContainer(Container& container, size_t size) {
    if (size < 2 || size % 2 != 0) {
        std::cerr << "Error: Size must be >= 2 and even\n";
        return false;
    }

    int choice;
    std::cout << "Choose input method:\n"
              << "1) Keyboard\n"
              << "2) Random\n"
              << "3) From file\n"
              << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: {
            std::cout << "Enter " << size << " elements:\n";
            for (size_t i = 0; i < size; ++i) {
                int value;
                std::cout << "Element " << i + 1 << ": ";
                if (!(std::cin >> value)) {
                    std::cerr << "Invalid input\n";
                    return false;
                }
                container.insert(container.end(), value);
            }
            break;
        }
        case 2: {
            std::srand(std::time(0));
            for (size_t i = 0; i < size; ++i) {
                container.insert(container.end(), std::rand() % 101 - 50);
            }
            break;
        }
        case 3: {
            std::ifstream file("input.txt");
            if (!file.is_open()) {
                std::cerr << "Failed to open file\n";
                return false;
            }
            for (size_t i = 0; i < size; ++i) {
                int value;
                if (!(file >> value)) {
                    std::cerr << "Not enough data in file\n";
                    return false;
                }
                container.insert(container.end(), value);
            }
            break;
        }
        default:
            std::cerr << "Invalid choice\n";
            return false;
    }
    return true;
}

template <typename Container>
void PrintContainer(const Container& container) {
    typedef typename Container::const_iterator Iterator;
    for (Iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

template <typename Container>
void SwapMiddleElements(Container& container) {
    typename Container::iterator middle1 = container.begin();
    std::advance(middle1, container.size() / 2 - 1);
    typename Container::iterator middle2 = middle1;
    std::advance(middle2, 1);
    std::swap(*middle1, *middle2);
}

// Явные инстанциации шаблонов
template bool FillContainer(std::vector<int>&, size_t);
template bool FillContainer(std::deque<int>&, size_t);
template bool FillContainer(std::list<int>&, size_t);

template void PrintContainer(const std::vector<int>&);
template void PrintContainer(const std::deque<int>&);
template void PrintContainer(const std::list<int>&);

template void SwapMiddleElements(std::vector<int>&);
template void SwapMiddleElements(std::deque<int>&);
template void SwapMiddleElements(std::list<int>&);
