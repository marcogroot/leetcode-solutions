#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/longest-common-subsequence/

using namespace std;

vector<int> applyOperations(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1]) {
      nums[i] = 0;
      nums[i - 1] *= 2;
    }
  }

  vector<int> output;

  for (int num : nums) {
    if (num != 0) {
      output.push_back(num);
    }
  }

  output.resize(nums.size());

  return output;
}

int main() {
  string a = "abcde";
  string b = "ace";
  vector<int> v = {1, 2, 3, 4, 5};

  auto res = applyOperations(v);
  for (int x : res) {
    cout << x << " ";
  }
  cout << "\n";
  // cout << applyOperations(v) << "\n";
}
