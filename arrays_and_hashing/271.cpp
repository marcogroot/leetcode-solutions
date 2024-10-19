#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/encode-and-decode-strings/description/
// 15-10-2024 @ marcogroot

using namespace std;

string encode(vector<string> &strs) {
  string result = "";
  for (const string &str : strs) {
    result += to_string(str.length()) + '#' + str;
  }
  return result;
}

vector<string> decode(string s) {
  vector<string> output;
  int i = 0;
  while (i < s.size()) {
    int j = i;
    while (s[j] != '#') {
      j++;
    }
    int length = stoi(s.substr(i, j - i));
    string str = s.substr(j + 1, length);
    output.push_back(str);
    i = j + 1 + length;
  }
  return output;
}

int main() {
  cout << " asdfa" << endl;
  vector<string> strs = {"we", "say", ":", "yes", "!@#$%^&*()"};
  string encoded = encode(strs);
  vector<string> decoded = decode(encoded);
  cout << encoded << endl;
  for (string &s : decoded) {
    cout << s << " ";
  }
  cout << "\n";
}
