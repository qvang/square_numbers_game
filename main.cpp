#include "random.h"
#include <algorithm>
#include <iostream>
#include <iterator>
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

  std::vector<int> arr{};
  generateSquares(arr, squares, start);

  bool win{false};
  while (true) {
    std::cout << "";
    int guess{};
    std::cin >> guess;

    if (!std::cin) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    auto found{std::find(arr.begin(), arr.end(), guess)};

    if (found == arr.end()) {
      std::vector<int>::iterator result{std::min_element(arr.begin(), found)};
      std::cout << guess << " is wrong. Try " << *result << " next time.\n";
      break;

    } else {
      arr.erase(found);

      if (std::ssize(arr) == 0) {
        win = true;
        break;
      }

      std::cout << "Nice! " << std::ssize(arr) << " number(s) left.\n";
    }
  }

  if (win)
    std::cout << "Nice, you found all numbers, good job!\n";

  return 0;
}
