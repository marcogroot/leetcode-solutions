#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/daily-temperatures/description/
// 21-10-2024 @ marcogroot

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures) {
  vector<pair<int, int>> stack;
  vector<int> answers(temperatures.size());

  for (int i = 0; i < temperatures.size(); i++) {
    int curr = temperatures[i];
    if (stack.empty() || stack[stack.size() - 1].first >= curr) {
      stack.push_back({curr, i});
    } else {
      while (!stack.empty() && stack[stack.size() - 1].first < curr) {
        pair<int, int> top = stack[stack.size() - 1];
        answers[top.second] = i - top.second;
        stack.pop_back();
      }
      stack.push_back({curr, i});
    }
  }

  return answers;
}
