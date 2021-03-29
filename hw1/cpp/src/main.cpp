#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

#include "select.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Usage: ./program <input file>" << endl;
    return EXIT_FAILURE;
  }

  int n, i;
  // arr 하나만 사용하면 randomized_select 수행 시
  // 배열이 정렬로 인해 망가지므로
  // linear_select용 arr를 하나 더 추가함.
  vector<int> arr1;
  vector<int> arr2;
  ifstream input(argv[1]);

  // Read input.
  if (input.is_open()) {
    int a;
    input >> n >> i;
    for (int idx = 0; idx < n; ++idx) {
      input >> a;
      arr1.push_back(a);
      arr2.push_back(a);
    }
    input.close();
  } else {
    cerr << "Failed to read input." << endl;
    return EXIT_FAILURE;
  }

  // Select i-th element (randomized select).
  clock_t x_start = clock();
  int x = randomized_select(arr1, 0, n-1, i);
  clock_t x_finish = clock();

  // Select i-th element (deterministic select).
  clock_t y_start = clock();
  int y = linear_select(arr2, 0, n-1, i);
  clock_t y_finish = clock();

  // Check correctness.
  bool x_correct = check(arr1, i, x);
  bool y_correct = check(arr2, i, y);

  cout << "randomized select    : " << x << " ("
       << (x_correct ? "CORRECT" : "WRONG") << ") (elapsed time: "
       << static_cast<double>(x_finish - x_start) / CLOCKS_PER_SEC  << " sec)"
       << endl;
  cout << "deterministic select : " << y << " ("
       << (y_correct ? "CORRECT" : "WRONG") << ") (elapsed time: "
       << static_cast<double>(y_finish - y_start) / CLOCKS_PER_SEC << " sec)"
       << endl;

  return EXIT_SUCCESS;
}
