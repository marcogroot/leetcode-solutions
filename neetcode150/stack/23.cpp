#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/generate-parentheses/description/
// 22-10-2024 @ marcogroot

using namespace std;

void dfs(string curr, int left, int left_total, int right_total, int n,
         vector<string> &output) {
  // cout << curr << endl;
  // cout << curr.size() << " " << n << endl;
  if (curr.size() >= n * 2) {
    cout << curr << endl;
    cout << "left " << left_total << " "
         << " right " << right_total << endl;
    if (left_total == right_total) {
      output.push_back(curr);
    }
    return;
  }
  dfs(curr + "(", left + 1, left_total + 1, right_total, n, output);
  if (left >= 1) {
    dfs(curr + ")", left - 1, left_total, right_total + 1, n, output);
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> output;
  dfs("", 0, 0, 0, n, output);
  for (string &s : output) {
    cout << s << endl;
  }
  return output;
}

int main() { generateParenthesis(3); }
