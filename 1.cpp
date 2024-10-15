#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

// https://leetcode.com/problems/contains-duplicate/
// 15-10-2024 @ marcogroot

using namespace std;

bool isAnagram(string s, string t) {
    vector<int> chars(26);

    for (const char& c : s) {
        int curr = c -'a';
        chars[curr]++;
    }

    for (const char& c : t) {
        int curr = c -'a';
        chars[curr]--;
    }

    for (const int& x : chars) {
        if (x != 0) return false;
    }

    return true;
}
