#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
// 01-02-2025 @ marcogroot

using namespace std;

int removeDuplicates(vector<int> &nums) {
  unordered_map<int, int> m;
  vector<int> temp;
  for (int i = 0; i < nums.size(); i++) {
    int count = m[nums[i++]];
    if (count <= 2) {
      temp.push_back(nums[i]);
    }
  }

  for (int i = 0; i < temp.size(); i++) {
    nums[i] = temp[i];
  }

  return temp.size();
}
