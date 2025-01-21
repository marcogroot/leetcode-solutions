#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// 20-10-2024 @ marcogroot

using namespace std;

int evalRPN(vector<string> &tokens) {
  vector<int> stack;

  int total = stoi(tokens[0]);

  for (int i = 0; i < tokens.size(); i++) {
    string token = tokens[i];
    if (token == "+") {
      int operand1 = stack[stack.size() - 1];
      stack.pop_back();
      total += operand1;

    } else if (token == "-") {
      int operand1 = stack[stack.size() - 1];
      stack.pop_back();
      total -= operand1;
    } else if (token == "*") {
      int operand1 = stack[stack.size() - 1];
      stack.pop_back();
      total *= operand1;
    } else if (token == "/") {
      int operand1 = stack[stack.size() - 1];
      stack.pop_back();
      total /= operand1;
    } else {
      stack.push_back(stoi(token));
    }
  }
  return total;
}
