#include <deque>
#include <ios>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/sliding-window-maximum/description/
// 20-10-2024 @ marcogroot

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  int n = nums.size();
  vector<int> output(n - k + 1);
  deque<int> q;
  int l = 0, r = 0;

  while (r < n) {
    while (!q.empty() && nums[q.back()] < nums[r]) {
      q.pop_back();
    }
    q.push_back(r);

    if (l > q.front()) {
      q.pop_front();
    }

    if (r + 1 >= k) {
      output[l] = nums[q.front()];
      l++;
    }
    r++;
  }

  return output;
}
