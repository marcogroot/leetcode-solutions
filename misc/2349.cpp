#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08
// 08-02-2025 @ marcogroot

using namespace std;

class NumberContainers {
public:
  unordered_map<int, set<int>> smallest_index;
  unordered_map<int, int> positions;

  NumberContainers() {}

  void change(int index, int number) {
    auto it = positions.find(index);
    if (it != positions.end()) {
      smallest_index[it->second].erase(index);
    }
    positions[index] = number;
    smallest_index[number].insert(index);
  }

  int find(int number) {
    auto it = smallest_index.find(number);
    return it == smallest_index.end() || it->second.empty()
               ? -1
               : *begin(it->second);
  }
};
