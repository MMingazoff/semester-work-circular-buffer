#include "circular_buffer.hpp"
#include <stdexcept>

namespace itis {
  CircularBuffer::CircularBuffer(int capacity) {
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }
    capacity_ = capacity;
  }

  void CircularBuffer::Enqueue(int value) {
    if (size_ < capacity_) {
      LinkedQueue::Enqueue(value);
      back_->next = front_;
    }
    else {
//      back_ = back_->next;
//      front_ = front_->next;
//      back_->value = value;
        Dequeue();
        LinkedQueue::Enqueue(value);
        back_->next = front_;
    }
  }

  bool CircularBuffer::Dequeue() {
    if (size_ == 0) {
      return false;
    }
    size_ -= 1;
    Node* temp = front_;
    front_ = front_->next;
    delete temp;
    return true;
  }

  bool CircularBuffer::Resize(int new_capacity) {
    if (new_capacity > capacity_) {
      capacity_ = new_capacity;
      return true;
    }
    return false;
  }

} // namespace itis