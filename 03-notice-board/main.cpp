#include <iostream>

void Clear(char board[5][10]) {
  for (int y = 0; y < 5; ++y) {
    for (int x = 0; x < 10; ++x) {
      board[y][x] = ' ';
    }
  }
}

bool IsInside(int x, int y) { return x >= 0 && x < 10 && y >= 0 && y < 5; }

bool Put(char board[5][10], int x, int y, char c) {
  if (!IsInside(x, y)) {
    return false;
  }
  board[y][x] = c;
  return true;
}

bool Text(char board[5][10], int x, int y, const char word[]) {
  if (!IsInside(x, y)) {
    return false;
  }

  int length = 0;
  while (word[length] != '\0') {
    ++length;
  }

  if (length > 10 - x) {
    return false;
  }

  for (int i = 0; i < length; ++i) {
    Put(board, x + i, y, word[i]);
  }
  return true;
}

void Print(const char board[5][10]) {
  for (int y = 0; y < 5; ++y) {
    for (int x = 0; x < 10; ++x) {
      std::cout << board[y][x];
    }
    std::cout << '\n';
  }
}

bool SameText(const char* first, const char* second) {
  int i = 0;
  while (first[i] != '\0' && second[i] != '\0') {
    if (first[i] != second[i]) {
      return false;
    }
    ++i;
  }
  return first[i] == second[i];
}

int main() {
  char board[5][10];
  Clear(board);

  char command[32];
  while (std::cin >> command) {
    if (SameText(command, "quit")) {
      break;
    } else if (SameText(command, "clear")) {
      Clear(board);
    } else if (SameText(command, "put")) {
      int x, y;
      char c;
      if (!(std::cin >> x >> y >> c)) {
        break;
      }
      if (!Put(board, x, y, c)) {
        std::cout << "error\n";
      }
    } else if (SameText(command, "text")) {
      int x, y;
      char word[11];
      if (!(std::cin >> x >> y >> word)) {
        break;
      }
      if (!Text(board, x, y, word)) {
        std::cout << "error\n";
      }
    } else if (SameText(command, "print")) {
      Print(board);
    } else {
      std::cout << "error\n";
    }
  }

  return 0;
}
