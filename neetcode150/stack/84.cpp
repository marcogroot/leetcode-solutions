#include <iostream>
#include <map>
#include <stack>
#include <utility>
#include <vector>

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// 25-10-2024 @ marcogroot

using namespace std;

int largestRectangleArea(vector<int> &heights) {
  int max_area = 0;
  stack<pair<int, int>> stack; // pair: (index, height)

  for (int i = 0; i < heights.size(); i++) {
    int start = i;
    while (!stack.empty() && stack.top().second > heights[i]) {
      pair<int, int> top = stack.top();
      int index = top.first;
      int height = top.second;
      max_area = max(max_area, height * (i - index));
      start = index;
      stack.pop();
    }
    stack.push({start, heights[i]});
  }

  while (!stack.empty()) {
    int index = stack.top().first;
    int height = stack.top().second;
    max_area =
        max(max_area, height * (static_cast<int>(heights.size()) - index));
    stack.pop();
  }
  return max_area;
}
