#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/clear-digits/?envType=daily-question&envId=2025-02-10
// 10-02-2025 @ marcogroot

using namespace std;

string clearDigits(string s) {
  string answer = "";

  int del = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    if ((s[i] - '0' >= 0) && (s[i] - '0' <= 9)) {
      del++;
    } else {
      if (del) {
        del--;
      } else {
        answer += s[i];
      }
    }
  }
  reverse(answer.begin(), answer.end());
  return answer;
}
