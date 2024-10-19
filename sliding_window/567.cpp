#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/permutation-in-string/
// 19-10-2024 @ marcogroot

using namespace std;

int characterReplacement(string s, int k) {
  vector<int> occs(26);

  int left{0};
  int right{0};
  int answer{0};

  while (left <= right && right < s.size()) {
    occs[s[right] - 'A']++;
    int max_occs = *max_element(occs.begin(), occs.end());
    // cout << max_occs << endl;
    int required = right - left + 1 - max_occs;
    // cout << left << " " << right << " " << max_occs << endl;
    if (required > k) {
      occs[s[left] - 'A']--;
      left++;
    }
    answer = max(answer, right - left + 1);
    right++;
  }
  return answer;
}
