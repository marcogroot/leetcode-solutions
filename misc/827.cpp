#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/making-a-large-island/?envType=daily-question&envId=2025-01-31
// 31-01-2025 @ marcogroot

using namespace std;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool is_valid(int r, int c, vector<vector<int>> &grid) {
  if (r < 0 || c < 0)
    return false;
  if (r >= grid.size())
    return false;
  if (c >= grid[0].size())
    return false;

  return true;
}

void dfs(int r, int c, int &size, int &island_name, vector<vector<int>> &grid) {
  grid[r][c] = island_name;
  size++;
  for (auto &dir : directions) {
    int new_r = r + dir.first;
    int new_c = c + dir.second;

    if (is_valid(new_r, new_c, grid) && grid[new_r][new_c] == 1) {
      dfs(new_r, new_c, size, island_name, grid);
    }
  }
}

int largestIsland(vector<vector<int>> &grid) {
  vector<int> island_sizes;

  int R = grid.size();
  int C = grid[0].size();

  int island_name = 2;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (grid[r][c] == 1) {
        int size = 0;
        dfs(r, c, size, island_name, grid);
        island_name++;
        island_sizes.push_back(size);
      }
    }
  }
  int answer = 0;
  for (int x : island_sizes) {
    answer = max(x, answer);
  }
  cout << " asdf " << endl;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      if (grid[r][c] == 0) {
        unordered_set<int> adjacent_islands;
        for (auto &dir : directions) {
          int new_r = r + dir.first;
          int new_c = c + dir.second;
          if (is_valid(new_r, new_c, grid) && grid[new_r][new_c] > 0) {
            adjacent_islands.insert(grid[new_r][new_c]);
          }
        }
        int temp = 1;
        for (int island : adjacent_islands) {
          temp += island_sizes[island + -2];
        }
        answer = max(answer, temp);
      }
    }
  }
  return answer;
}

int main() {
  vector<vector<int>> input = {{0, 0}, {0, 0}};
  cout << largestIsland(input) << endl;
}
