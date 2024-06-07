#include <iostream>
#include <vector>

void input_matrix(float arr[][4]){
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> arr[i][j];
    }
  }  
}

void printVec(std::vector<float> vec) {
  for (int j = 0; j < 4; j++) {
    std::cout << vec[j] << "\n"; 
  }
  std::cout << "\n";
}

int main() {
  std::cout << "Multiplying a matrix by a vector\n";
  
  float a[4][4];
  std::cout << "Input matrix 4x4: ";
  input_matrix(a);

  std::vector<float> vec(4);
  std::cout << "Input vector: ";
  for (int i = 0; i < 4; i++) {
      std::cin >> vec[i];
  }
  
  std::vector<float> c(4);
  for (int i = 0; i < 4; i++) {
    int sum = 0;
    for (int j = 0; j < 4; j++) {
      sum += a[i][j] * vec[j];
    }
    c[i] = sum;
  }
  std::cout << "Result: \n";
  printVec(c); 
}