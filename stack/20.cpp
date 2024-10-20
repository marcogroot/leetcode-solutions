#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/valid-parentheses/description/
// 20-10-2024 @ marcogroot

using namespace std;
bool isValid(string s) {
  vector<char> stack;
  unordered_map<char, char> pairs;
  pairs['('] = ')';
  pairs['['] = ']';
  pairs['{'] = '}';

  for (char &c : s) {
    if (c == '(' || c == '{' || c == '[') {
      stack.push_back(c);
    } else {
      if (stack.size() == 0)
        return false;
      char top = stack[stack.size() - 1];
      if (pairs[c] != top)
        return false;
      stack.pop_back();
    }
  }
  if (stack.size() != 0)
    return false;
  return true;
}
