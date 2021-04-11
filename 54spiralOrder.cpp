#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return {};
        }

        int n = matrix[0].size();
        if (n == 0) {
            return {};
        }

        vector<int> ans;

        int i = 0;
        int j = 0;
        int direction = 0;
        int leftEnd = 0;
        int downEnd = m-1;
        int rightEnd = n-1;
        int upEnd = 0;
        while (true) {

            if (direction == 0) {
                ans.push_back(matrix[i][j]);
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
                ans.push_back(matrix[i][j]);

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
                ans.push_back(matrix[i][j]);

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
                ans.push_back(matrix[i][j]);

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

        return ans;
    }
};

int main() {
    vector<vector<int>> args = {{1,2,3},{4,5,6},{7,8,9}};
    Solution s;
    s.spiralOrder(args);
}