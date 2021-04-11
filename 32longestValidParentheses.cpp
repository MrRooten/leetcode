#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        int res = 0;
        for(int i=1;i < n;i++) {
            if (s[i]==')') {
                if (s[i-1]=='(') {
                    dp[i] = (i-2>=0?dp[i-2]:0)+2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i-1] + ((i-dp[i-1]-2>=0)?dp[i-dp[i-1]-2]:0) + 2;
                }

                res = max(dp[i],res);
            }
        }

        return res;
    }
};

int main(int argc, char** argv) {
    string arg = "(()()(()(()(())(()())";
    Solution s;
    cout << s.longestValidParentheses(arg) << endl;
}