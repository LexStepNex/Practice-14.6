#include <iostream>
#include <vector>

int main() {
  bool block[5][5][10];
  //         x  y  z
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 5; y++) {
      int n = 0;
      do {
        std::cout << "Input heights(0 - 10) " << x << ":" << y << " : ";
        std::cin >> n;
      } while (n < 0 || n > 10);

      for (int z = 0; z < 10; z++) {
        if (z < n) {
          block[x][y][z] = true;
        } else {
          block[x][y][z] = false;
        }
      }
    }
  }
  
  for (int x = 0; x < 5; x++) { // Для наглядности 
    for (int y = 0; y < 5; y++) {
      for (int z = 0; z < 10; z++) {
        std::cout << (z == 0 ? "{" : "") << block[x][y][z] << " ";
      }
      std::cout << "}";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  
  int n = 0;
  while (n != -1) {
    std::cout << "Input slice (0 - 9): ";
    std::cin >> n;
    if (n < 0 || n > 9) continue;
  

    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 5; y++) {
        std::cout << (block[x][y][n] ? "1" : "0") << " ";
      }
      std::cout << "\n";
    }

    std::cout << "Input -1 for exit\n";
  }
}