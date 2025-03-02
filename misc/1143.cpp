#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/longest-common-subsequence/

using namespace std;

int dfs(int i, int j, const string &s1, const string &s2) {
  if (i >= s1.size())
    return 0;
  if (j >= s2.size())
    return 0;

  if (s1[i] == s2[j]) {
    return 1 + dfs(i + 1, j + 1, s1, s2);
  } else {
    return max(dfs(i + 1, j, s1, s2), dfs(i, j + 1, s1, s2));
  }
  return 0;
}

int longestCommonSubsequence(string text1, string text2) {
  // return dfs(0, 0, text1, text2);
  vector<vector<int>> dp(text1.size(), vector<int>(text2.size()));

  for (int i = text1.size() - 1; i >= 0; i--) {
    for (int j = text2.size() - 1; j >= 0; j--) {
      if (text1[i] == text2[j]) {
        dp[i][j] = 1 + dp[i + 1][j + 1];
      } else
        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  return dp[0][0];
}

int main() {
  string a = "abcde";
  string b = "ace";

  cout << longestCommonSubsequence(a, b) << "\n";
}
