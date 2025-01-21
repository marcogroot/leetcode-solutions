#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/group-anagrams/
// 15-10-2024 @ marcogroot

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<string, vector<string>> m;

  for (string str : strs) {
    string copy = str;

    sort(str.begin(), str.end());
    m[str].push_back(copy);
  }

  vector<vector<string>> output;
  for (auto &x : m) {
    output.push_back(x.second);
  }
  return output;
}
