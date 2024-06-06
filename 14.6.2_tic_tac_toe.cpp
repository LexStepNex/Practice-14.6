#include <iostream>

void printGame(char arr[][3]) {
  for (int i = 0; i < 3; i++) {
    std::cout << (i == 0 ? "\n__0_1_2_\n" : "");
    for (int j = 0; j < 3; j++) {
      if (j == 0) std::cout << i;
      std::cout << "|" << arr[i][j] << (j == 2 ? "|" : "");
    }
    std::cout << "\n---------\n";
  }
}

bool result(char arr[][3], char player) {
  for (int i = 0; i < 3; i++) {
    int sumHorizon = 0;
    int sumVertical = 0;

    for (int j = 0; j < 3; j++) {
      if (arr[i][j] == player) {
        sumHorizon++;
      }
      if (arr[j][i] == player) {
        sumVertical++;
      }
    }

    if (sumHorizon == 3 || sumVertical == 3) {
      return true;
    }
  }
  if (arr[1][1] == player && (arr[0][0] == player && arr[2][2] == player ||
                              arr[2][0] == player && arr[0][2] == player)) {
    return true;
  }
  return false;
}

int main() {
  char game[3][3] = {{' ', ' ', ' '},
                     {' ', ' ', ' '},
                     {' ', ' ', ' '}};

  printGame(game);

  bool place[3][3] = {{false, false, false},
                      {false, false, false},
                      {false, false, false}};

  int n = 9;
  int x, y;
  char player;
  bool win = false;

  while (n > 0 && !win) {
    if (n % 2 == 1) {
      player = 'X';
    } else {
      player = 'O';
    }

    std::cout << "Player " << player << " enter coordinates(x:y): ";
    std::cin >> x >> y;
    if (place[x][y]) continue;
    if ((0 > x || x > 2) || (0 > y || y > 2)) continue;

    game[x][y] = player;
    place[x][y] = true;

    printGame(game);

    win = result(game, player);
    n--;
  }

  if (win) {
    std::cout << "WIN " << player;
  } else {
    std::cout << "Draw";
  }
}