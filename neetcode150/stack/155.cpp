#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/min-stack/description/
// 21-10-2024 @ marcogroot

using namespace std;

class MinStack {

  vector<pair<int, int>> stack;

  MinStack() { stack = {}; }

  void push(int val) {
    int existing_min = val;
    if (stack.size()) {
      existing_min = min(existing_min, stack[stack.size() - 1].second);
    }
    stack.push_back({val, existing_min});
  }

  void pop() { stack.pop_back(); }

  int top() { return stack[stack.size() - 1].first; }

  int getMin() { return stack[stack.size() - 1].second; }
}
