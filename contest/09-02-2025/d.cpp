#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// 2, 3, 4, 5 --- 2
long long maxScore(vector<int> &points, int m) {
  long long max_answer = 0;

  for (int i = 0; i < points.size(); i++) {
    if (!((i + 1) > m)) {
      int moves_left = m - i - 1;
      // cout << "reached " << points[i] << " with " << moves_left
      //      << " moves left " << endl;

      long long answer = points[i];
      if (moves_left % 2 != 0) {
        moves_left--;
      }
      answer += (moves_left / 2) * points[i];
      max_answer = max(max_answer, answer);
    }
  }

  return max_answer;
}

int main() {
  vector<int> v = {1, 2, 3};
  int m = 5;
  cout << maxScore(v, m) << endl;
}
