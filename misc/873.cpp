#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27

using namespace std;

int lenLongestFibSubseq(vector<int> &nums) {
  unordered_set<int> s;
  for (int x : nums) {
    s.insert(x);
  }

  int answer = 0;

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      int a = nums[i];
      int b = nums[j];

      int c = a + b;

      int count = 2;
      while (s.contains(c)) {
        a = b;
        b = c;
        c = a + b;
        count++;
        answer = max(answer, count);
      }
    }
  }

  return answer;
}

int main() { vector<int> nums = {1, 2, 3, 4, 5}; }
