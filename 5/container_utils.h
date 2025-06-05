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

#ifndef CONTAINER_UTILS_H
#define CONTAINER_UTILS_H

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

/**
 * @brief Заполнение контейнера данными
 * @tparam Container Тип контейнера
 * @param container Контейнер для заполнения
 * @param size Размер контейнера (должен быть ≥ 2 и четным)
 * @return true при успешном заполнении, false при ошибке
 */
template <typename Container>
bool FillContainer(Container& container, size_t size);

/**
 * @brief Вывод элементов контейнера
 * @tparam Container Тип контейнера
 * @param container Контейнер для вывода
 */
template <typename Container>
void PrintContainer(const Container& container);

/**
 * @brief Обмен значений двух средних элементов
 * @tparam Container Тип контейнера
 * @param container Контейнер для обработки
 */
template <typename Container>
void SwapMiddleElements(Container& container);

#endif // CONTAINER_UTILS_H
