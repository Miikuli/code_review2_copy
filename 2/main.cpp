﻿/* Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из
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
#include <windows.h>

int main() {
    Queue oddQueue, evenQueue;
    oddQueue.Initialize(); // Очередь для нечетных позиций
    evenQueue.Initialize(); // Очередь для четных позиций

    std::cout << "Введите 10 чисел:\n";
    for (int i = 1; i <= 10; i++) {
        int number;
        std::cout << "Число " << i << ": ";
        std::cin >> number;

        if (std::cin.fail()) {
            std::cout << "Ошибка! Введите число!\n";
            return 0;
        }

        // Распределение чисел по очередям
        if (i % 2 != 0) {
            oddQueue.Enqueue(number);
        } else {
            evenQueue.Enqueue(number);
        }
    }

    std::cout << "\nНечетная очередь:\n";
    oddQueue.Print();
    oddQueue.PrintPointers();

    std::cout << "\nЧетная очередь:\n";
    evenQueue.Print();
    evenQueue.PrintPointers();

    return 0;
}
