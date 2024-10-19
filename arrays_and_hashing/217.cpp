#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/contains-duplicate/
// 15-10-2024 @ marcogroot

using namespace std;

bool containsDuplicate(vector<int> &nums) {
  unordered_map<int, int> m;
  for (const int &num : nums) {
    if (++m[num] > 1)
      return true;
  }

  return false;
}
