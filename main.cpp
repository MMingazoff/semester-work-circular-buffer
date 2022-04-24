#include <iostream>
#include <filesystem>

#include "circular_buffer.hpp"

using namespace std;
using namespace itis;


int main(int argc, char *argv[]) {
  CircularBuffer test_buff = CircularBuffer();
  for (int i = 0; i < 10; i++) {
    test_buff.Enqueue(i);
  }
  for (int i = 0; i < 10; i++) {
    test_buff.Dequeue();
  }
  system("rmdir C:\\cpprogs\\semester-work-circular-buffer\\dataset\\data /Q"); // удалить саму директорию.
//  auto a = test_buff.toVector();
//  for (int i: a) {
//    cout << i << ' ';
//  }
  return 0;
}