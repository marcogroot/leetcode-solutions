#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

// https://leetcode.com/problems/longest-consecutive-sequence/description/
// 16-10-2024 @ marcogroot

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;

    for (const int& num : nums) {
        s.emplace(num);
    }

    vector<int> potential_starts;

    for (const int& num : nums) {
        if (s.count(num-1) == 0) {
            potential_starts.push_back(num);
        }
    }

    int answer = 0;

    for (int& start : potential_starts) {
        int score = 1;
        while (s.count(++start) == 1) {
            score++;
        }
        answer = max(answer, score);
    }

    return answer;
}
