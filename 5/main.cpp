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
#include <iostream>

void PrintCat() {
    std::cout << "      /\\     /\\  \n"
              << "     {  `---'  } \n"
              << "     {  O   O  } \n"
              << "     ~~>  V  <~~ \n";
}

int main() {
    std::vector<int> vec;
    std::deque<int> deq;
    std::list<int> lst;

    size_t size;
    
    std::cout << "Enter vector size (>=2 and even): ";
    std::cin >> size;
    if (!FillContainer(vec, size)) return 1;

    std::cout << "Enter deque size (>=2 and even): ";
    std::cin >> size;
    if (!FillContainer(deq, size)) return 1;

    std::cout << "Enter list size (>=2 and even): ";
    std::cin >> size;
    if (!FillContainer(lst, size)) return 1;

    std::cout << "\nOriginal containers:\n";
    std::cout << "Vector: ";
    PrintContainer(vec);
    std::cout << "Deque:  ";
    PrintContainer(deq);
    std::cout << "List:   ";
    PrintContainer(lst);

    SwapMiddleElements(vec);
    SwapMiddleElements(deq);
    SwapMiddleElements(lst);

    std::cout << "\nAfter swapping middle elements:\n";
    std::cout << "Vector: ";
    PrintContainer(vec);
    std::cout << "Deque:  ";
    PrintContainer(deq);
    std::cout << "List:   ";
    PrintContainer(lst);

    PrintCat();
    return 0;
}
