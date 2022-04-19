#include <iostream>

#include "circular_buffer.hpp"

using namespace itis;

int main(int argc, char *argv[]) {

  auto* temp = new CircularBuffer(10);
  for (int i = 0; i < 15; i++) {
    temp->Enqueue(i);
  }
  temp->Resize(20);
  for (int i = 10; i < 15; i++) {
    temp->Enqueue(i);
  }
  for (int i = 0; i < 14; i++) {
    std::cout << temp->front().value();
    temp->Dequeue();
  }
  std::cout << "\n";
  for (int i = 1; i < 5; i++) {
    temp->Enqueue(i);
  }
//  for (int i = 0; i < 4; i++) {
//    std::cout << temp->front().value();
//    temp->Dequeue();
//  }
  std::cout << "\nefaw";
  temp->Clear();
  temp->Enqueue(1);

  std::cout << temp->front().value();

  return 0;
}