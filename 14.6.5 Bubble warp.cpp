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
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;

    std::cout << "Enter coordinates(x1:y1 form 0-11): ";
    std::cin >> x1 >> y1;
    if ((0 > x1 || x1 > 12) || (0 > y1 || y1 > 12)) continue;

    do {
      std::cout << "Enter coordinates(x2:y2 form 0-11): ";
      std::cin >> x2 >> y2;
    } while ((0 > x2 || x2 > 12) || (0 > y2 || y2 > 12));

    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);

    for (int i = x1; i <= x2; i++) {
      for (int j = y1; j <= y2; j++) {
        if (bubble[i][j]) {
          bubble[i][j] = false;
          n--;
        }
      }
    }
    printArray(bubble);
  }
}