#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/search-a-2d-matrix/description/
// 25-10-2024 @ marcogroot

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int row = matrix.size();
  int col = matrix[0].size();
  int s = 0;
  int e = row * col - 1;
  int m = s + (e - s) / 2;
  while (s <= e) {
    int element = matrix[m / col][m % col];
    if (target == element) {
      return 1;
    } else if (target <= element) {
      e = m - 1;
    } else {
      s = m + 1;
    }
    m = s + (e - s) / 2;
  }
  return 0;
}
