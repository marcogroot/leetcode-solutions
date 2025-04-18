#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <deque>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void print(const vector<int> &v) {
  for (int num : v) {
    cout << num << " ";
  }
  cout << "\n";
}

int main() {
  vector<int> t{1, 2, 3, 4, 5};
  print(t);
  auto it = find(t.begin(), t.end(), 3);
  if (it != t.end()) {
    t.erase(it);
  }
  print(t);
}
