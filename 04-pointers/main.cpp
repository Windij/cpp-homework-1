#include <iostream>

int main() {
  // Журнал читает оценки числами или буквами и выводит сумму для каждого
  // студента. int*** хранит группы, в каждой группе — массив студентов, у
  // каждого студента свой массив оценок. Размеры этих массивов задаются во
  // время ввода и могут различаться, поэтому каждый массив выделяется отдельно.
  // void* хранит адрес общего временного буфера: int[] для чисел или char[] для
  // букв. Формат определяет тип буфера; после приведения указателя оценки
  // читаются и переводятся в числовой журнал, затем буфер освобождается.

  int G;
  std::cin >> G;

  int*** journal = new int**[G];
  int* studentCounts = new int[G];
  int** markCounts = new int*[G];

  for (int i = 0; i < G; ++i) {
    int S;
    std::cin >> S;
    studentCounts[i] = S;

    int** group = new int*[S];
    markCounts[i] = new int[S];

    for (int j = 0; j < S; ++j) {
      int K;
      std::cin >> K;
      markCounts[i][j] = K;

      int* student = new int[K];

      char type;
      std::cin >> type;

      void* buffer = nullptr;

      if (type == 'n') {
        buffer = new int[K];
      } else {
        buffer = new char[K];
      }

      if (type == 'n') {
        int* numbers = static_cast<int*>(buffer);
        for (int x = 0; x < K; ++x) {
          std::cin >> numbers[x];
        }
        for (int x = 0; x < K; ++x) {
          student[x] = numbers[x];
        }
        delete[] numbers;
      } else {
        char* letters = static_cast<char*>(buffer);
        for (int x = 0; x < K; ++x) {
          std::cin >> letters[x];
        }
        // Преобр букв в числа
        for (int x = 0; x < K; ++x) {
          if (letters[x] == 'A') {
            student[x] = 5;
          } else if (letters[x] == 'B') {
            student[x] = 4;
          } else if (letters[x] == 'C') {
            student[x] = 3;
          } else if (letters[x] == 'D') {
            student[x] = 2;
          }
        }
        delete[] letters;
      }

      group[j] = student;
    }
    journal[i] = group;
  }

  // Вывод
  for (int i = 0; i < G; ++i) {
    for (int j = 0; j < studentCounts[i]; ++j) {
      int sum = 0;
      for (int x = 0; x < markCounts[i][j]; ++x) {
        sum += journal[i][j][x];
      }
      if (j > 0) {
        std::cout << ' ';
      }
      std::cout << sum;
    }
    std::cout << '\n';
  }

  // Удаление массивов
  for (int i = 0; i < G; ++i) {
    for (int j = 0; j < studentCounts[i]; ++j) {
      delete[] journal[i][j];
    }
    delete[] journal[i];
    delete[] markCounts[i];
  }
  delete[] journal;
  delete[] markCounts;
  delete[] studentCounts;

  return 0;
}
