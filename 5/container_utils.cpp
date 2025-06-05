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

template<typename Container>
bool ContainerUtils::FillContainer(Container& container, size_t size, InputMethod method) {
    container.clear();

    if (size < 2 || size % 2 != 0) {
        std::cerr << "Error: Size must be even and >= 2\n";
        return false;
    }

    try {
        switch (method) {
            case KEYBOARD: {
                std::cout << "Enter " << size << " integer elements:\n";
                for (size_t i = 0; i < size; ++i) {
                    int value;
                    while (!(std::cin >> value)) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cerr << "Invalid input. Please enter an integer: ";
                    }
                    container.insert(container.end(), value);
                }
                break;
            }
            case RANDOM: {
                std::srand(static_cast<unsigned>(std::time(nullptr)));
                std::generate_n(std::back_inserter(container), size, []() {
                    return std::rand() % 100;
                });
                std::cout << "Generated " << size << " random elements\n";
                break;
            }
            case FILE_INPUT: {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;

                std::ifstream file(filename);
                if (!file.is_open()) {
                    std::cerr << "Error: Cannot open file " << filename << "\n";
                    return false;
                }

                int value;
                size_t count = 0;
                while (file >> value && count < size) {
                    container.insert(container.end(), value);
                    count++;
                }

                if (count < size) {
                    std::cerr << "Error: File contains only " << count << " elements\n";
                    container.clear();
                    return false;
                }
                break;
            }
            default:
                std::cerr << "Error: Invalid input method\n";
                return false;
        }
        return true;
    } catch (...) {
        std::cerr << "Error: Exception occurred during container filling\n";
        return false;
    }
}

template<typename Container>
void ContainerUtils::PrintContainer(const Container& container) {
    std::copy(container.begin(), container.end(), 
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

template<typename Container>
void ContainerUtils::PrintReverse(const Container& container) {
    std::copy(container.rbegin(), container.rend(), 
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

template<typename Container>
bool ContainerUtils::SwapMiddleElements(Container& container) {
    if (container.size() < 2 || container.size() % 2 != 0) {
        std::cerr << "Error: Container size must be even and >= 2\n";
        return false;
    }

    try {
        // Явно указываем тип итератора
        typename Container::iterator mid1 = container.begin();
        std::advance(mid1, container.size()/2 - 1);
        
        typename Container::iterator mid2 = mid1;
        std::advance(mid2, 1);
        
        std::iter_swap(mid1, mid2);
        return true;
    } catch (...) {
        std::cerr << "Error: Exception during swap operation\n";
        return false;
    }
}

// Явные инстанциации
template bool ContainerUtils::FillContainer(std::vector<int>&, size_t, InputMethod);
template bool ContainerUtils::FillContainer(std::deque<int>&, size_t, InputMethod);
template bool ContainerUtils::FillContainer(std::list<int>&, size_t, InputMethod);

template void ContainerUtils::PrintContainer(const std::vector<int>&);
template void ContainerUtils::PrintContainer(const std::deque<int>&);
template void ContainerUtils::PrintContainer(const std::list<int>&);

template void ContainerUtils::PrintReverse(const std::vector<int>&);
template void ContainerUtils::PrintReverse(const std::deque<int>&);
template void ContainerUtils::PrintReverse(const std::list<int>&);

template bool ContainerUtils::SwapMiddleElements(std::vector<int>&);
template bool ContainerUtils::SwapMiddleElements(std::deque<int>&);
template bool ContainerUtils::SwapMiddleElements(std::list<int>&);
