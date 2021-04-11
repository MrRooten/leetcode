#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        set<vector<int>> emptys;
        for(int i=0;i < 9;i++) {
            for(int j=0;j < 9;j++) {
                if (board[i][j] == '.') {
                    emptys.insert({i,j});
                }
            }
        }

        for(auto empty : emptys) {
            int x = empty[0];
            int y = empty[1];

            
        }
    }
};