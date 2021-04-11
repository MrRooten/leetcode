#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int ans = 0;
        if (n == 1) {
            return 0;
        }
        while (i < n) {
            int steps = nums[i];
            int j;
            int best_step;
            int max_jump = -1;
            for(j=0;j <= steps&&i+j < n;j++) {
                if (i + nums[i+j] + j >= n-1) {
                    best_step = j;
                    break;
                } else 
                if (i+nums[i+j]+j > max_jump) {
                    best_step = j;
                    max_jump = i+nums[i+j]+j;
                }
            }

            i = best_step + i;
            ans += 1;
            if (i == n-1) {
                return ans;
            }

            if (i + nums[i] >= n-1) {
                if (best_step == 0) {
                    return ans;
                }
                return ans + 1;
            }
        }

        return ans+1;

    }
};

int main() {
    Solution s;
    vector<int> arg = {2,3,1,1,4};
    cout << s.jump(arg) << endl;
}