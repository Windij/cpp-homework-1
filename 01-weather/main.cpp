#include <iomanip>
#include <iostream>

struct LowHighTemp {
  int low;
  int high;
};

float AverageTemp(const int* temp, int n) {
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += temp[i];
  }
  return (float)s / n;
}

LowHighTemp MinMaxTemp(const int* temp, int n) {
  LowHighTemp result = {temp[0], temp[0]};

  for (int i = 1; i < n; ++i) {
    if (result.low > temp[i]) {
      result.low = temp[i];
    }
    if (result.high < temp[i]) {
      result.high = temp[i];
    }
  }
  return result;
}

int ColdDays(const int* temp, int n) {
  int counter = 0;
  for (int i = 0; i < n; ++i) {
    if (temp[i] < 0) {
      ++counter;
    }
  }
  return counter;
}

int main() {
  int N;
  std::cin >> N;

  if (N <= 0) {
    return 0;
  }

  int* temp = new int[N];

  for (int i = 0; i < N; ++i) {
    std::cin >> temp[i];
  }

  std::cout << std::fixed << std::setprecision(1);

  LowHighTemp range = MinMaxTemp(temp, N);

  std::cout << AverageTemp(temp, N) << '\n';
  std::cout << range.low << ' ' << range.high << '\n';
  std::cout << ColdDays(temp, N) << '\n';

  delete[] temp;

  return 0;
}
