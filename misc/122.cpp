#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// https://leetcode.com/problems/special-array-i/?envType=daily-question&envId=2025-02-01
// 01-02-2025 @ marcogroot

using namespace std;

int maxProfit(vector<int> &prices) {
  int potential_profit = 0;
  int held_stock_price = prices[0];

  int answer = 0;
  for (int i = 0; i < prices.size(); i++) {
    int curr = prices[i];
    int curr_diff = curr - held_stock_price;
    potential_profit = max(potential_profit, curr_diff);
    held_stock_price = min(held_stock_price, curr);

    cout << curr_diff << " " << potential_profit << endl;

    if (curr_diff <= potential_profit) {
      cout << "Selling for profit: " << potential_profit << endl;
      answer += potential_profit;
      potential_profit = 0;
      held_stock_price = curr;
    }

    cout << "Holding " << held_stock_price << endl;
  }

  return max(potential_profit, answer);
}

int main() {
  vector<int> v = {6, 1, 3, 2, 4, 7};
  cout << maxProfit(v) << endl;
}
