#include <iostream>

using Operation = void (*)(int&);

struct Command {
  const char* name;
  Operation action;
};

void Deposit(int& money) {
  int next;
  std::cin >> next;
  if (next <= 0) {
    std::cout << "error\n";
    return;
  }
  money += next;
}

void Withdraw(int& money) {
  int next;
  std::cin >> next;
  if (next <= 0 || next > money) {
    std::cout << "error\n";
    return;
  }
  money -= next;
}

void Balance(int& money) { std::cout << money << '\n'; }

void Reset(int& money) { money = 0; }

void Double(int& money) { money *= 2; }

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
  int money = 0;

  Command commands[] = {{"deposit", Deposit},
                        {"withdraw", Withdraw},
                        {"balance", Balance},
                        {"reset", Reset},
                        {"double", Double}};

  char command[32];

  while (std::cin >> command) {
    if (SameText(command, "stop")) {
      break;
    }

    bool found = false;

    for (const Command& entry : commands) {
      if (SameText(command, entry.name)) {
        entry.action(money);
        found = true;
        break;
      }
    }

    if (!found) {
      std::cout << "error\n";
    }
  }

  return 0;
}
