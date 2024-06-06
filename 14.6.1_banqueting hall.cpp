#include <iostream>

int main() {
  int fork[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int spoon[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int knife[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int soupPlate[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int flatPlate[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  int chair[2][6] = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};

  int desertSpoon[2][6] = {{1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0}};  // for vip
  int desertPlate[2][6] = {{1, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0}};

  std::cout << "Fork, spoon, knife, soup plate, flat plat and chair: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << fork[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "Desert spoon and desert plate: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << desertSpoon[i][j] << " ";
    }
    std::cout << "\n";
  }

  std::cout << "\nActions after initialization\n\n";

  chair[0][4]++;

  std::cout << "chair: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << chair[i][j] << " ";
    }
    std::cout << "\n";
  }

  spoon[1][2]--;

  std::cout << "spoon: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << spoon[i][j] << " ";
    }
    std::cout << "\n";
  }

  desertSpoon[1][0]--;
  desertSpoon[1][2]++;

  std::cout << "Desert spoon: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << desertSpoon[i][j] << " ";
    }
    std::cout << "\n";
  }

  desertPlate[1][0]--;

  std::cout << "Desert plate: \n";
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 6; j++) {
      std::cout << desertPlate[i][j] << " ";
    }
    std::cout << "\n";
  }
}