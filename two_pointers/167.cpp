#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/valid-palindrome/description/
// 16-10-2024 @ marcogroot

using namespace std;

bool isPalindrome(string s) {
  int left = 0;
  int right = s.size() - 1;

  while (left <= right) {

    if (!isalnum(s[left])) {
      left++;
      continue;
    }
    if (!isalnum(s[right])) {
      right--;
      continue;
    }

    if (tolower(s[left]) != tolower(s[right])) {
      return false;
    }

    left++;
    right--;
  }

  return true;
}
