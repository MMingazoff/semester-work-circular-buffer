#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main(int argc, char** argv) {

  // Tip 1: можете передать путь до входного/выходного файла в качестве аргумента
  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  const auto path = string(kDatasetPath);  // конвертация string_view в string
  cout << "Dataset path: " << path << endl;

  // Пример: чтение набора данных
  auto input_stream = ifstream(path + "/dataset-example.csv");

  if (input_stream) {
    int line_number = 0;

    // построчное чтение
    for (string line; getline(input_stream, line); /* ... */) {
      auto ss = stringstream(line);  // оборачиваем строку в объект "поток"

      for (string token; getline(ss, token, ','); /* ... */) {
        cout << "Token: [" << token << "] at line " << line_number << '\n';
      }

      cout << line << '\n';
      line_number++;
    }
  }

  // Пример: генерация набора данных
  for (int papka = 1; papka <= 10; papka++) {
    string string_papka;
    if (papka != 10) {
      string_papka = "0" + to_string(papka);
    } else {
      string_papka = to_string(papka);
    }
    for (int size = 100; size < 1000001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream = ofstream(path + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел

      if (output_stream) {
        for (int counter = 0; counter < size - 1; counter++) {
          output_stream << dist(engine) << '\n';
        }
        output_stream << dist(engine) << '\n';
      }
    }
    for (int size = 500; size < 5000001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream = ofstream(path + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел

      if (output_stream) {
        for (int counter = 0; counter < size; counter++) {
          output_stream << dist(engine) << '\n';
        }
        output_stream << dist(engine) << '\n';
      }
    }
  }
  return 0;
}