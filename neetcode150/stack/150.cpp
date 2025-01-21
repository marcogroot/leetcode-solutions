#include <ios>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// 21-10-2024 @ marcogroot

using namespace std;
int evalRPN(vector<string> &tokens) {
  stack<long> st;
  for (int i = 0; i < tokens.size(); i++) {
    string s = tokens[i];
    if (s == "*" || s == "+" || s == "-" || s == "/") {
      long a = st.top(), result;
      st.pop();
      long b = st.top();
      st.pop();
      if (s == "*")
        result = a * b;
      else if (s == "+")
        result = a + b;
      else if (s == "-")
        result = b - a;
      else
        result = b / a;
      st.push(result);
    } else {
      long x = stoi(s);
      st.push(x);
    }
  }
  return (int)st.top();
}
