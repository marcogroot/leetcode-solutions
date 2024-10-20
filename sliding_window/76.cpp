#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/minimum-window-substring/
// 20-10-2024 @ marcogroot

using namespace std;

string minWindow(string s, string t) {
  unordered_map<char, int> m;
  for (int i = 0; i < t.size(); i++) {
    m[t[i]]++;
  }

  int i = 0;
  int j = 0;

  int counter = t.size();

  int minStart = 0;
  int minLength = INT_MAX;

  while (j < s.size()) {
    if (m[s[j]] > 0) {
      counter--;
    }
    m[s[j]]--;
    j++;

    while (counter == 0) {
      if (j - i < minLength) {
        minStart = i;
        minLength = j - i;
      }
      m[s[i]]++;

      if (m[s[i]] > 0) {
        counter++;
      }
      i++;
    }
  }

  if (minLength != INT_MAX) {
    return s.substr(minStart, minLength);
  }
  return "";
}
