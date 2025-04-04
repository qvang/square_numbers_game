#include "random.h"
#include <iostream>
#include <vector>

void generateSquares(std::vector<int> &arr, int num, int start) {

  int randomNum{Random::get(2, 4)};
  for (std::size_t i{0}; i < num; ++i) {
    arr.push_back((start * start) * randomNum);
    start++;
  }

  std::cout << "I generated " << num
            << " square numbers. Do you know what each number is after "
               "multiplying it by "
            << randomNum << "?\n";
}

int main() {

  std::cout << "Start where? ";
  int start;
  std::cin >> start;

  std::cout << "How many? ";
  int squares;
  std::cin >> squares;

  std::vector<int> squareNumsArr{};
  generateSquares(squareNumsArr, squares, start);

  for (auto &p : squareNumsArr) {
    std::cout << p << ' ';
  }

  std::cout << '\n';
  return 0;
}
