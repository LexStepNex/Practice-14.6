#include <iostream>

void input_matrices(int arr[][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> arr[i][j];
    }
  }  
}

bool compare(int arrOne[][4], int arrTwo[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (arrOne[i][j] != arrTwo[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void diagonal(int arr[][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j) {
        arr[i][j] = 0;
      }
    }
  }
}

void printArray(int arr[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::cout << "Compare matrices\n";

  int one[4][4];
  std::cout << "Input one matrix 4x4: ";
  input_matrices(one);
  
  int two[4][4];
  std::cout << "Input two matrix 4x4: ";
  input_matrices(two);

  if (!compare(one, two)) {
    std::cout << "Matrices are not equal\n";
  } else {
    diagonal(one);
    printArray(one);
  }
}