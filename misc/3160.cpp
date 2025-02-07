#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07
// 07-02-2025 @ marcogroot

using namespace std;

vector<int> queryResults(int limit, vector<vector<int>> &queries) {
  unordered_map<int, int> colour_counts;
  unordered_map<int, int> balls;

  vector<int> answer;
  int distinct = 0;
  for (vector<int> &q : queries) {
    int x = q[0];
    int y = q[1];
    int current_colour = balls[x];
    if (colour_counts[current_colour] == 1) {
      distinct--;
    }
    balls[x] = y;
    colour_counts[current_colour]--;
    colour_counts[y]++;
    if (colour_counts[y] == 1) {
      distinct++;
    }

    answer.push_back(distinct);
  }

  return answer;
}

int main() {
  // vector<int> v = {3, 4, 5, 1, 2};
  vector<vector<int>> v = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
  cout << queryResults(4, v) << endl;
}
