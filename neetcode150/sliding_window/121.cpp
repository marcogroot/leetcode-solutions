#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/container-with-most-water/description/
// 18-10-2024 @ marcogroot

using namespace std;

int maxArea(vector<int> &height) {
  int left{0};
  int right{static_cast<int>(height.size() - 1)};

  int answer = 0;
  while (left < right) {
    int left_wall = {height[left]};
    int right_wall = {height[right]};

    int water = min(left_wall, right_wall) * (right - left);
    answer = max(answer, water);

    if (left_wall < right_wall) {
      left++;
    } else
      right--;
  }

  return answer;
}
