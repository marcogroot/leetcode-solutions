#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/binary-search/
// 25-10-2024 @ marcogroot

using namespace std;

int search(vector<int> &nums, int target) {
  int idx = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
  if (idx > 0 && nums[idx - 1] == target) {
    return idx - 1;
  } else {
    return -1;
  }
}
