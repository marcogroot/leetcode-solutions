#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2025-02-02
// 01-02-2025 @ marcogroot

using namespace std;

bool check2(int start, vector<int> &nums) {
  int prev = nums[start];
  for (int i = 0; i < nums.size() - 1; i++) {
    start++;
    if (start == nums.size()) {
      start = 0;
    }
    int curr = nums[start];
    if (curr < prev) {
      cout << "fake " << curr << " " << prev << endl;
      return false;
    }

    prev = curr;
  }

  cout << "asdf" << endl;
  return true;
}

bool check(vector<int> &nums) {
  if (nums.size() == 1)
    return true;

  for (int i = 0; i < nums.size(); i++) {
    if (i == 0 || nums[i - 1] > nums[i]) {
      cout << "checking index " << i << endl;
      if (check2(i, nums)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  vector<int> v = {3, 4, 5, 1, 2};
  cout << check(v) << endl;
}
