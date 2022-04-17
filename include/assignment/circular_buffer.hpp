#pragma once

#include "assignment/linked_queue.hpp"

namespace assignment {
  /**
   * Структура данных "кольцевой буфер" на базе "очереди".
   */
  struct CircularBuffer: LinkedQueue {
   private:
    // поля структуры
    int size_{0};           // количество элементов в буфере
    int capacity{0};        // емкость буфера
    Node* front_{nullptr};  // указатель на начало буфера
    Node* back_{nullptr};   // указатель на конец буфера

   public:
    // константы структуры
    static constexpr int kInitCapacity = 10;  // начальная емкость буфера
    static constexpr int kCapacityGrowthCoefficient = 5;  // коэффициент увеличения размера буфера

    /**
     * Создание буфера с указанной емкостью.
     *
     * Выделенные ячейки буфера инициализируются нулевым значением.
     *
     * @param capacity - начальная емкость буфера
     * @throws invalid_argument при указании неположительной емкости буфера
     */
    explicit CircularBuffer(int capacity = kInitCapacity);

    /**
     * Добавление элемента в буфер.
     *
     * @param value - значение добавляемого элемента
     */
    void Enqueue(int value) override;

    /**
     * Удаление элемента из буфера.
     *
     * @return true - операция успешна, false - операция невозможна
     */
    bool Dequeue() override;

    /**
     * Очистка буфера.
     *
     * Высвобождает выделенную под буфер память.
     * Устанавливает поля в нулевые значения.
     */
    void Clear() override;

    /**
     * Увеличение емкости буфера.
     *
     * @param new_capacity - новая емкость буфера
     * @return true - операция прошла успешно, false - новая емкость меньше или равна текущей
     */
    bool Resize(int new_capacity);


  };
}