#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
  vector<vector<int>> output = grid;

  for (int i = 1; i < grid.size(); i++) {
    vector<int> temp;
    for (int j = 0; j < grid.size() - i; j++) {
      temp.push_back(grid[j][j + i]);
    }

    sort(temp.begin(), temp.end());
    int t = 0;
    for (int j = 0; j < grid.size() - i; j++) {
      output[j][j + i] = temp[t];
      t++;
    }
  }

  for (int i = 0; i < grid.size(); i++) {
    vector<int> temp;
    int r = i;
    int c = 0;
    for (int j = 0; j < grid.size() - i; j++) {
      temp.push_back(grid[r][c]);
      r++;
      c++;
    }

    // cout << "-------------------\n";
    sort(temp.begin(), temp.end(), greater<int>());
    // for (int i = 0; i < temp.size(); i++) {
    //   cout << temp[i] << " ";
    // }
    // cout << "-------------------\n";

    int t = 0;
    r = i;
    c = 0;
    for (int j = 0; j < grid.size() - i; j++) {
      output[r][c] = temp[t];
      r++;
      c++;
      t++;
    }
  }

  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid.size(); j++) {
      cout << output[i][j] << " ";
    }
    cout << "\n";
  }

  return output;
}

int main() {
  vector<vector<int>> v{
      {1, 7, 3},
      {9, 8, 2},
      {4, 5, 6},
  };
  sortMatrix(v);
}
