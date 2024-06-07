#include <iostream>

void printArray(int arr[][5]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::cout << "Snake array\n";
  int arr[5][5];

  int n = 0;

  for (int i = 0; i < 5; i++) {
    int m = (0 - i % 2);
    for (int j = 0; j < 5; j++) {
      arr[i][(j + j * m) - ((4 - j) * m)] = n;
      n++;
    }
  }

  printArray(arr);
}