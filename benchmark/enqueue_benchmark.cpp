#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // to_string
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds

// подключаем вашу структуру данных
#include "circular_buffer.hpp"

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main() {
  int num;
  cin >> num;

  const auto path = string(kDatasetPath);
  cout << path << endl << endl;

  for(int folder_num = 1; folder_num <= 10; folder_num++) {
    CircularBuffer circBuff = CircularBuffer(num/2);

    string filename = "/" + to_string(num) + ".csv";
    string folder;
    if (folder_num<10){
      folder = "/0" + to_string(folder_num);
    }else{
      folder = "/" + to_string(10);
    }
    cout << path + folder + filename << endl;
    ifstream fin(path + folder + filename);
    int value;

    const auto time_point_before = chrono::steady_clock::now();
    for (int i = 0; i < num; i++) {
      fin >> value;
      circBuff.Enqueue(value);
    }
    const auto time_point_after = chrono::steady_clock::now();
    const auto time_diff = time_point_after - time_point_before;
    const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
    cout << "Time elapsed (ns): " << time_elapsed_ns << '\n';
    fin.close();
  }
  return 0;
}

