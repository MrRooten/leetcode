#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if (n == 0) {
            return 1;
        }
        if (nums[n-1] <= 0) {
            return 1;
        }

        if (nums[0] > 1) {
            return 1;
        }
        int i;
        for(i=0;i < n&&nums[i] <= 0;i++) {

        }

        if ( i == n-1&&nums[i]!=1) {
            return 1;
        }

        if (nums[i]!=1) {
            return 1;
        }

        while (i < n-1) {
            if (nums[i]+1!=nums[i+1] && nums[i]!=nums[i+1]) {
                return nums[i]+1;
            }
            i++;
        }

        return nums[n-1]+1;
    }
};

int main() {

}