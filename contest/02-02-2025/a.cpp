#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int maxDifference(string s) {
  vector<int> nums(26);
  for (auto c : s) {
    int temp = c - 'a';
    nums[temp]++;
  }

  int min_even = INT_MAX;
  int max_odd = INT_MIN;
  for (auto &t : nums) {
    if (t != 0) {
      cout << t << endl;
      if (t % 2 == 0) {
        min_even = min(t, min_even);
      } else {
        max_odd = max(t, max_odd);
      }
    }
  }

  return max_odd - min_even;
}

int main() {
  string a = "aaaaabbc";
  cout << maxDifference(a) << endl;
}
