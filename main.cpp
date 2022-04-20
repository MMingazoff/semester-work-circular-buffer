#include <iostream>

#include "circular_buffer.hpp"

using namespace std;
using namespace itis;

int main(int argc, char *argv[]) {
  CircularBuffer test_buff = CircularBuffer(10);
//  test_buff.Enqueue(10);
//  test_buff.Enqueue(12);
//  test_buff.Enqueue(14);
//  test_buff.Enqueue(16);
//  cout << test_buff.front().value() << "\n";
//  cout << test_buff.back().value() << "\n";
//  test_buff.Dequeue();
//  cout << test_buff.front().value() << "\n";
//  cout << test_buff.back().value();
  for (int i = 0; i < 10; i++) {
    test_buff.Enqueue(i);
  }
  cout << test_buff.front().value() << "\n";
  cout << test_buff.back().value() << "\n";
  for (int i = 0; i < 10; i++) {
    test_buff.Dequeue();
  }
//  cout << test_buff.front().value() << "\n";
//  cout << test_buff.back().value() << "\n";
  cout << test_buff.IsEmpty();
  return 0;
}