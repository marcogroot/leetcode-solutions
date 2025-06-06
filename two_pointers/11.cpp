#include <ios>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// 18-10-2024 @ marcogroot

using namespace std;

int maxProfit(vector<int> &prices) {
  int answer{0};
  int left{0};
  int right{1};

  while (left < prices.size()) {
    if (right == prices.size())
      return answer;

    if (prices[right] < prices[left]) {
      left = right;
    } else {
      answer = max(answer, prices[right] - prices[left]);
      right++;
    }
  }

  return answer;
}
