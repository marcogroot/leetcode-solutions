#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<int> assignElements(vector<int> &groups, vector<int> &elements) {

  unordered_map<int, int> m;
  vector<int> output(groups.size(), -1);
  vector<pair<int, int>> element_pairs(elements.size());
  for (int i = 0; i < elements.size(); i++) {
    element_pairs[i] = make_pair(elements[i], i);
  }
  sort(element_pairs.begin(), element_pairs.end());

  for (int i = 0; i < groups.size(); i++) {
    int group = groups[i];
    if (m.count(group) != 0) {
      output[i] = m[group];
    } else {
      bool flag = true;
      for (int j = 0; j < elements.size(); j++) {
        if (group % elements[j] == 0) {
          output[i] = j;
          m[group] = j;
          flag = false;
          break;
        }
      }
      if (flag) {
        output[i] = -1;
      }
    }
  }

  for (int i = 0; i < output.size(); i++) {
    cout << output[i] << " ";
  }
  cout << "\n";

  return output;
}

int main() {
  vector<int> v = {8, 4, 3, 2, 4};
  vector<int> v2 = {4, 2};
  assignElements(v, v2);
}
