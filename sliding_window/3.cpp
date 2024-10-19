#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// 19-10-2024 @ marcogroot

using namespace std;

int lengthOfLongestSubstring(string s) {
  int i{0};
  int j{0};
  int n{static_cast<int>(s.size())};
  int answer{0};

  unordered_map<char, int> letter_included;

  while (j < n) {
    if (letter_included.count(s[j]) != 0) {
      i = max(i, letter_included[s[j]] + 1);
    }
    answer = max(answer, j - i + 1);
    letter_included[s[j]] = j;
    j++;
  }

  return answer;
}
