#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int maxDistance(string s, int k) {
  vector<int> N(s.size());
  vector<int> S(s.size());
  vector<int> E(s.size());
  vector<int> W(s.size());

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'N') {
      N[i]++;
    }
    if (s[i] == 'S') {
      S[i]++;
    }
    if (s[i] == 'E') {
      E[i]++;
    }
    if (s[i] == 'W') {
      W[i]++;
    }

    if (i > 0) {
      N[i] += N[i - 1];
      S[i] += S[i - 1];
      E[i] += E[i - 1];
      W[i] += W[i - 1];
    }
  }

  int answer = 0;
  for (int i = 0; i < s.size(); i++) {
    int NS = abs(N[i] - S[i]);
    int EW = abs(E[i] - W[i]);
    int potential_max = NS + EW;

    int temp_k = k;

    if (temp_k > 0) {
      int m = min(N[i], S[i]);
      if (m > temp_k) {
        potential_max += 2 * temp_k;
        temp_k = 0;
      } else {
        potential_max += 2 * m;
        temp_k -= m;
      }
    }

    if (temp_k > 0) {
      int m = min(E[i], W[i]);
      if (m > temp_k) {
        potential_max += 2 * temp_k;
        temp_k = 0;
      } else {
        potential_max += 2 * m;
        temp_k -= m;
      }
    }

    answer = max(answer, potential_max);
  }

  return answer;
}

int main() {
  string a = "NSWWEW";
  cout << maxDistance(a, 3) << endl;
}
