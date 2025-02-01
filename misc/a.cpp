#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/redundant-connection/?envType=daily-question&envId=2025-01-29
// 29-01-2025 @ marcogroot

using namespace std;

int find(vector<int> &parent, int curr) {
  int p = parent[curr];
  while (p != parent[p]) {
    parent[p] = parent[parent[p]];
    p = parent[p];
  }
  return p;
}

bool union_func(vector<int> &parent, vector<int> &rank, int n1, int n2) {
  int p1 = find(parent, n1);
  int p2 = find(parent, n1);
  if (p1 == p2) {
    return true;
  }
  if (rank[p1] > rank[p2]) {
    parent[p2] = p1;
    rank[p1] += rank[p2];
  } else {
    parent[p1] = p2;
    rank[p2] += rank[p1];
  }

  return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
  vector<int> parent(edges.size());
  for (int i = 0; i < edges.size(); i++) {
    parent[i] = i + 1;
  }
  vector<int> rank(edges.size(), 1);

  for (vector<int> &v : edges) {
    if (union_func(parent, rank, v[0], v[1])) {
      return {v[0], v[1]};
    }
  }
  return {};
}
