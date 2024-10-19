#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/3sum/description/
// 16-10-2024 @ marcogroot

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
  vector<vector<int>> answer;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    int j = i + 1;
    int k = nums.size() - 1;

    while (j < k) {
      int a = nums[i];
      int b = nums[j];
      int c = nums[k];
      int total = a + b + c;

      if (total > 0)
        k--;
      else if (total < 0)
        j++;
      else {
        answer.push_back({a, b, c});
        j++;

        while (nums[j] == nums[j - 1] && j < k)
          j++;
      }
    }
  }
  return answer;
}
