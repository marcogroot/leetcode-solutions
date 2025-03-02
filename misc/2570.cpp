#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/?envType=daily-question&envId=2025-03-02

using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
                                vector<vector<int>> &nums2) {
  map<int, int> m;

  for (auto &x : nums1) {
    m[x[0]] += m[x[1]];
  }
  for (auto &x : nums2) {
    m[x[0]] += m[x[1]];
  }

  vector<vector<int>> answer;
  for (auto &[id, value] : m) {
    answer.push_back({id, value});
  }

  return answer;
}

int main() {
  string a = "abcde";
  string b = "ace";
  vector<int> v = {1, 2, 3, 4, 5};

  // auto res = applyOperations(v);
  //  for (int x : res) {
  //    cout << x << " ";
  //  }
  //  cout << "\n";
  //  cout << applyOperations(v) << "\n";
}
