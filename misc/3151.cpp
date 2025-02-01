#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
// 01-02-2025 @ marcogroot

using namespace std;

bool isArraySpecial(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    if ((nums[i] % 2) != (nums[i - 1] % 2))
      return false;
  }

  return true;
}
