#include <iostream>

void printArray(bool arr[][12]) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      std::cout << (arr[i][j] ? "O" : "X");
    }
    std::cout << "\n";
  }
}

int main() {
  bool bubble[12][12];
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      bubble[i][j] = true;
    }
  }

  printArray(bubble);

  int n = 144;
  while (n > 0) {
    int x_1 = 0, x_2 = 0, y_1 = 0, y_2 = 0;

    std::cout << "Enter coordinates(x_1:y_1 form 0-11): ";
    std::cin >> x_1 >> y_1;
    if ((0 > x_1 || x_1 > 12) || (0 > y_1 || y_1 > 12)) continue;

    do {
      std::cout << "Enter coordinates(x_2:y_2 form 0-11): ";
      std::cin >> x_2 >> y_2;
    } while ((0 > x_2 || x_2 > 12) || (0 > y_2 || y_2 > 12));

    if (x_1 > x_2) std::swap(x_1, x_2);
    if (y_1 > y_2) std::swap(y_1, y_2);

    for (int i = x_1; i <= x_2; i++) {
      for (int j = y_1; j <= y_2; j++) {
        if (bubble[i][j]) {
          bubble[i][j] = false;
          n--;
        }
      }
    }
    printArray(bubble);
  }
}