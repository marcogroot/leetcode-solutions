#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/?envType=daily-question&envId=2025-02-11
// 11-02-2025 @ marcogroot

// axxxxyyyyb
// 0123456789
using namespace std;

string removeOccurrences(string s, string part) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == part[0]) {
      if (s.substr(i, part.size()) == part) {
        return removeOccurrences(s.substr(0, i) + s.substr(i + part.size()),
                                 part);
      }
    }
  }

  return s;
}

int main() {
  string s = "daabcbaabcbc";
  cout << removeOccurrences(s, "abc") << endl;
}
