#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int minimumIncrements(vector<int> &nums, vector<int> &target) {
  int answer = 0;
  for (int i = 0; i < nums.size(); i++) {
    int min_required = INT_MAX;
    for (int j = 0; j < target.size(); j++) {
      int required = nums[i];
      int targ = target[j];

      min_required = min(min_required, targ % required);
    }
    // cout << "min reqauired for " << nums[i] << " " << min_required << endl;
    answer += min_required;
  }

  return answer;
}

int main() {
  vector<int> a = {8, 4};
  vector<int> b = {10, 5};
  cout << minimumIncrements(a, b) << endl;
}
