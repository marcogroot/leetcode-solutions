#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// 16-10-2024 @ marcogroot

using namespace std;

int binary_search(int left, const vector<int>&  numbers, const int& target) {
    int right = numbers.size()-1;

    while (left <= right) {
        int mid = (left+right) / 2;
        int current = numbers[mid];

        if (current == target) return mid;

        if (current < target)  {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0  ; i  < numbers.size(); i++) {
        int result = binary_search(i+1, numbers, target-numbers[i]);
        if (result != -1) return {i+1, result+1};
    }
    return {};
}

// alternative better solution
// int left = 0;
// int right = numbers.size() - 1;

// while (left < right) {
//     int total = numbers[left] + numbers[right];

//     if (total == target) {
//         return {left + 1, right + 1};
//     } else if (total > target) {
//         right--;
//     } else {
//         left++;
//     }
// }
