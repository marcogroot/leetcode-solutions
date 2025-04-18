#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
// 01-02-2025 @ marcogroot

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
  vector<pair<int, int>> s;
  vector<int> output(temperatures.size());
  for (int i = 0; i < temperatures.size(); i++) {
    int &temp = temperatures[i];
    if (s.empty()) {
      s.push_back(make_pair(temp, i));
    } else {
      while (!s.empty() && s.back().first < temp) {
        pair<int, int> &temp = s.back();
        output[temp.second] = i - temp.second;
        s.pop_back();
      }
      s.push_back(make_pair(temp, i));
    }
  }

  return output;
}
