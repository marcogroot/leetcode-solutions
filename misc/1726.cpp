#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06
// 06-02-2025 @ marcogroot

using namespace std;

int tupleSameProduct(vector<int> &nums) {
  unordered_map<int, int> m;
  int answer = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (i == j) {
        continue;
      }
      int product = nums[i] * nums[j];
      answer += m[product] * 8;
      m[product]++;
    }
  }

  for (auto &x : m) {
    cout << x.first << ": " << x.second << endl;
  }

  return answer;
}

int main() {
  vector<int> v = {2, 3, 4, 6, 8, 12};
  cout << tupleSameProduct(v) << endl;
}
