#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/grid-game/?envType=daily-question&envId=2025-01-21
// 21-01-2025 @ marcogroot

using namespace std;

bool dfs(int curr, vector<vector<int>> &graph, vector<bool> &safe,
         unordered_set<int> visited) {

  if (visited.contains(curr))
    return false;
  if (safe[curr])
    return true;

  visited.insert(curr);
  vector<int> &outgoing_nodes = graph[curr];
  if (outgoing_nodes.size() == 0) {
    return true;
  }
  for (int i = 0; i < graph[curr].size(); i++) {
    bool dfs_result = dfs(graph[curr][i], graph, safe, visited);
    if (!dfs_result)
      return false;
  }

  return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
  vector<bool> safe_nodes(graph.size(), false);
  vector<int> answer;
  for (int i = 0; i < graph.size(); i++) {
    bool safe = true;
    for (int j = 0; j < graph[i].size(); j++) {
      unordered_set<int> vis;
      safe = safe && dfs(graph[i][j], graph, safe_nodes, vis);
    }
    if (safe) {
      safe_nodes[i] = true;
      answer.push_back(i);
    }
  }

  return answer;
}
