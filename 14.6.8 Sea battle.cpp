#include <cmath>
#include <iostream>

void printArray(bool arr[][10]) {
  for (int i = 0; i < 10; i++) {
    std::cout << (i == 0 ? "  0_1_2_3_4_5_6_7_8_9\n" : "");
    for (int j = 0; j < 10; j++) {
      if (j == 0) std::cout << i;
      std::cout << "|" << (arr[i][j] ? "#" : " ");
      if (j == 9) std::cout << "|";
    }
    std::cout << "\n----------------------\n";
  }
}

void empty_field(bool arr[][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      arr[i][j] = false;
    }
  }
}

void single(bool arr[][10], int x, int y) {
  int n = 1;
  while (n < 5) {
    std::cout << "One deck ships\n";
    std::cout << n << " ship. Enter coordinates(x:y form 0-9): ";
    std::cin >> x >> y;
    if ((0 > x || x > 9) || (0 > y || y > 9) || arr[x][y] == true) continue;
    arr[x][y] = true;
    printArray(arr);
    n++;
  }
}

void longShip(bool arr[][10], int x_1, int y_1, int x_2, int y_2) {
  int n = 2;
  int count = 0;

  do {
    std::cout << n << "deck ship.\n";
    std::cout << "Enter coordinates(x_1:y_1 form 0-9): ";
    std::cin >> x_1 >> y_1;
    if ((0 > x_1 || x_1 > 9) || (0 > y_1 || y_1 > 9) || arr[x_1][y_1] == true)
      continue;

    std::cout << "Enter coordinates(x_2:y_2 form 0-9): ";
    std::cin >> x_2 >> y_2;
    if ((0 > x_2 || x_2 > 9) || (0 > y_2 || y_2 > 9) || arr[x_2][y_2] == true)
      continue;

    if (x_1 != x_2 && y_1 != y_2 || x_1 == x_2 && fabs(y_2 - y_1) != n - 1 ||
        y_1 == y_2 && fabs(x_2 - x_1) != n - 1)
      continue;

    if (x_1 > x_2) std::swap(x_1, x_2);
    if (y_1 > y_2) std::swap(y_1, y_2);

    bool controlPlace = false;

    for (int i = x_1; i < x_2 + 1; i++) {
      for (int j = y_1; j < y_2 + 1; j++) {
        if (arr[i][j] == true) {
          controlPlace = true;
          break;
        }
      }
    }
    if (controlPlace) continue;

    for (int i = x_1; i < x_2 + 1; i++) {
      for (int j = y_1; j < y_2 + 1; j++) {
        arr[i][j] = true;
      }
    }

    printArray(arr);

    count++;
    if (count == 3) {
      n++;
    } else if (count == 5) {
      n++;
    } else if (count == 6) {
      n++;
    }
  } while (n < 5);
}

bool shooting(bool arr[][10], int x, int y) {
  do {
    std::cout << "Enter coordinates(x:y form 0-9): ";
    std::cin >> x >> y;
  } while ((0 > x || x > 9) || (0 > y || y > 9));

  if (arr[x][y] == true) {
    std::cout << "Hit\n";
    arr[x][y] = false;
    return true;
  } else {
    std::cout << "Miss\n";
    return false;
  }
}
int main() {
  bool field_1[10][10];
  empty_field(field_1);

  bool field_2[10][10];
  empty_field(field_2);

  int x_1, y_1, x_2, y_2;

  std::cout << "Player 1 enter you ships \n";
  printArray(field_1);
  single(field_1, x_1, y_1);
  longShip(field_1, x_1, y_1, x_2, y_2);

  std::cout << "Player 2 enter you ships \n";
  printArray(field_2);
  single(field_2, x_1, y_1);
  longShip(field_2, x_1, y_1, x_2, y_2);

  int count_1 = 20;
  int count_2 = 20;
  bool win = false;

  int change = 0;
  do {
    if (change == 0) {
      std::cout << "Player 1 You move\n";

      if (shooting(field_2, x_1, y_1)) count_1--;
      if (count_1 == 0) {
        win = true;
        break;
      }
      change++;
    } else {
      std::cout << "Player 2 You move\n";

      if (shooting(field_1, x_1, y_1)) count_2--;
      if (count_2 == 0) {
        win = true;
        break;
      }
      change--;
    }
  } while (!win);

  std::cout << "Player " << (change == 0 ? "1" : "2") << " WIN\n";
}