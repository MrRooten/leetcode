#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        int i = 0;
        int j = 0;
        int direction = 0;
        int leftEnd = 0;
        int downEnd = m-1;
        int rightEnd = n-1;
        int upEnd = 0;
        int v = 1;
        while (true) {

            if (direction == 0) {
                matrix[i][j] = v;
                v++;
                if (j == rightEnd) {
                    direction = 1;
                    upEnd++;
                    if (i == downEnd) {
                        break;
                    }
                    i++;
                } else {
                    j++;
                }
            } else if (direction == 1) {
                matrix[i][j] = v;
                v++;
                if (i == downEnd) {
                    direction = 2;
                    rightEnd--;
                    if (j == leftEnd) {
                        break;
                    }
                    j--;
                } else {
                    i++;
                }
            } else if (direction == 2) {
                matrix[i][j] = v;
                v++;
                if (j == leftEnd) {
                    direction = 3;
                    downEnd--;
                    if (i == upEnd) {
                        break;
                    }
                    i--;
                }else {
                    j--;
                }
            } else if (direction == 3) {
                matrix[i][j] = v;
                v++;
                if (i == upEnd) {
                    direction = 0;
                    leftEnd++;
                    if (j == rightEnd) {
                        break;
                    }
                    j++;
                } else {
                    i--;
                }
            }
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        spiralOrder(ans);
        return ans;
    }
};