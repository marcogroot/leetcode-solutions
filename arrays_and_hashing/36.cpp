#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

// https://leetcode.com/problems/top-k-frequent-elements/description/
// 15-10-2024 @ marcogroot

using namespace std;

bool is_invalid_row(const int& row, const vector<vector<char>>& board) {
   unordered_set<char> s;

   for (int i = 0; i < 9; i++) {
       char curr = board[row][i];
       if (curr == '.') continue;

       if (s.count(curr) != 0) return true;
       s.emplace(curr);
   }

   return false;
}

bool is_invalid_col(const int& col, const vector<vector<char>>& board) {
   unordered_set<char> s;

   for (int i = 0; i < 9; i++) {
       char curr = board[i][col];
       if (curr == '.') continue;

       if (s.count(curr) != 0) return true;
       s.emplace(curr);
   }

   return false;
}


bool is_invalid_square(
    const int& start_row,
    const int& start_col,
    const vector<vector<char>>& board
) {
   unordered_set<char> s;

   for (int i = start_row; i < start_row+3; i++) {
       for (int j = start_col; j < start_col+3; j++) {
           char curr = board[i][j];
           if (curr == '.') continue;
           if (s.count(curr) != 0) return true;
           s.emplace(curr);
       }
   }

   return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    const int rows = 9;
    const int cols = 9;

    for (int i = 0; i < rows; i++) {
        if (is_invalid_row(i, board))  {
            return false;
        }
    }

    for (int i = 0; i < cols; i++) {
        if (is_invalid_col(i, board))  {
            return false;
        }
    }

    for (int i = 0; i < cols; i+=3) {
        for (int j = 0; j < cols; j+=3) {
            if (is_invalid_square(i, j, board))  {
                return false;
            }
        }
    }

    return true;
}
