#pragma once

#include <vector>

#include "assignment/node.hpp"   // Node
#include "assignment/queue.hpp"  // Queue

namespace assignment {

  /**
   * Структура данных "очередь" на базе "связного списка".
   */
  struct LinkedQueue : Queue {
   private:
    // поля структуры
    int size_{0};           // кол-во узлов в очереди
    Node* front_{nullptr};  // указатель на начало очереди
    Node* back_{nullptr};   // указатель на конец очереди

   public:
    /**
     * Создание пустой очереди ~ O(1).
     */
    LinkedQueue() = default;

    /**
     * Деструктор ~ O(n).
     *
     * Высвобождает выделенную под очередь память.
     * Устанавливает поля в нулевые значения.
     */
    ~LinkedQueue() override;

    /**
     * Добавление элемента в конец очереди ~ O(1).
     *
     * @param value - значение добавляемого элемента
     */
    void Enqueue(int value) override;

    /**
     * Удаление элемента из начала очереди ~ O(1).
     *
     * @return true - операция успешна, false - операция невозможна (очередь пуста)
     */
    bool Dequeue() override;

    /**
     * Очистка очереди ~ O(n).
     *
     * Высвобождает выделенную под очередь память.
     * Устанавливает поля в нулевые значения.
     */
    void Clear() override;

    /**
     * Получение элемента в начале очереди ~ O(1).
     *
     * @return значение элемента или ничего (пустая очередь)
     */
    std::optional<int> front() const override;

    /**
     * Получение элемента в конце очереди ~ O(1).
     *
     * @return значение элемента или ничего (пустая очередь)
     */
    std::optional<int> back() const override;

    /**
     * Проверка пустоты очереди.
     *
     * @return true - очередь пустая, false - в очереди есть элементы
     */
    bool IsEmpty() const override;

    /**
     * Возвращает размер очереди.
     *
     * @return количество элементов в очереди
     */
    int size() const override;

    // для тестирования
    explicit LinkedQueue(const std::vector<int>& values);

    std::vector<int> toVector() const;
  };

}  // namespace assignment