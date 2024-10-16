#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// https://leetcode.com/problems/valid-anagram/description/
// 15-10-2024 @ marcogroot

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;

    for (int i = 0; i  < nums.size(); i++) {
        int num = nums[i];
        int needed = target - num;
        if (m.count(needed) != 0) {
            return  {i, m[needed]};
        }

        m[num] = i;
    }

    return {};
}
