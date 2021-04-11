#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.size();
        int pn = p.size();
        vector<vector<int>> dp(sn + 1, vector<int>(pn + 1));
        dp[0][0] = true;
        for (int i = 1; i <= pn; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = true;
            }
            else {
                break;
            }
        }
        for (int i = 1; i <= sn; ++i) {
            for (int j = 1; j <= pn; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
                }
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[sn][pn];
    }
};
