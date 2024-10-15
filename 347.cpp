#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// https://leetcode.com/problems/top-k-frequent-elements/description/
// 15-10-2024 @ marcogroot

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    for (const int& num : nums) {
        counts[num]++;
    }

    vector<pair<int, int>> pairs_count;
    for (const auto& p : counts) {
        pairs_count.emplace_back(-p.second, p.first);
    }

    sort(pairs_count.begin(), pairs_count.end());

    vector<int> answer;
    for (const auto& p : pairs_count) {
        answer.push_back(p.second);
        k--;
        if (k == 0) return answer;
    }
    return answer;
}

int main() {
    vector<int> test = {1, 1, 1, 2, 2, 3};
    topKFrequent(test, 2);
}
