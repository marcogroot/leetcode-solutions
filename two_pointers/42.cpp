#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/trapping-rain-water/description/
// 18-10-2024 @ marcogroot

using namespace std;

int trap(vector<int> &height) {
  if (height.empty()) {
    return 0;
  }

  int left{0};
  int right = {static_cast<int>(height.size() - 1)};
  int max_left{height[left]};
  int max_right{height[right]};
  int answer = 0;

  while (left < right) {
    if (max_left < max_right) {
      left++;
      max_left = max(max_left, height[left]);
      answer += max_left - height[left];
    } else {
      right--;
      max_right = max(max_right, height[right]);
      answer += max_right - height[right];
    }
  }
  return answer;
}

int main() {
  vector<int> input = {4, 2, 3};
  trap(input);
}
