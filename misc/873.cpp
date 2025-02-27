#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/?envType=daily-question&envId=2025-02-27

using namespace std;

int lenLongestFibSubseq(vector<int> &A) {
  int n = A.size();
  map<int, int> m;
  for (int i = 0; i < n; i++)
    m[A[i]] = i;
  vector<vector<int>> dp(n, vector<int>(n, 2));
  for (int j = 1; j < n; j++)
    for (int i = 0; i < j; i++)
      if (m.find(A[j] - A[i]) != m.end() and m[A[j] - A[i]] < i)
        dp[i][j] = max(dp[i][j], dp[m[A[j] - A[i]]][i] + 1);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = max(ans, dp[i][j]);

  return (ans == 2) ? 0 : ans;
}

int main() { vector<int> nums = {1, 2, 3, 4, 5}; }
