#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// https://leetcode.com/problems/valid-sudoku/description/
// 16-10-2024 @ marcogroot

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int s = nums.size();
    vector<int> backwards = nums;
    vector<int> forwards = nums;

    for (int i = 1; i  < s; i++) {
        forwards[i] *= forwards[i-1];
    }
    for (int i = s-2; i >= 0;  i--) {
        backwards[i] *= backwards[i+1];
    }

    vector<int> output(s);
    output[0] =  backwards[1];
    output[s-1] = forwards[s-2];

    for (int i = 1;  i <  nums.size()-1; i++) {
        output[i] = forwards[i-1] * backwards[i+1];
    }

    return output;
}
