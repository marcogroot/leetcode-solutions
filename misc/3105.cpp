#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
// 03-02-2025 @ marcogroot

using namespace std;

int longestMonotonicSubarray(vector<int> &nums) {
  int longest_increasing = 1;
  int longest_decreasing = 1;

  int temp = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] > nums[i - 1]) {
      temp++;
      longest_increasing = max(longest_increasing, temp);
    } else {
      temp = 1;
    }
  }

  temp = 1;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] < nums[i - 1]) {
      temp++;
      longest_decreasing = max(longest_decreasing, temp);
    } else {
      temp = 1;
    }
  }

  return max(longest_decreasing, longest_increasing);
}
