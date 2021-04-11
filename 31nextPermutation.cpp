#include <vector>
#include <cstdio>
#include <climits>
using namespace std;
int getHighNumber(int n) {
    int res = n;
    while((n /= 10)!=0) {
        res = n;
    }
    return res;
}

int getBits(int n) {
    if (n == 0) {
        return 1;
    }
    int res = 0;
    while((n /= 10)) {
        res++;
    }
    return res;
}

void swap(int& i,int& j) {
    int temp = i;
    i = j;
    j = temp;
}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if (length == 0) {
            return ;
        }

        if (length == 1) {
            return ;
        }
        for(int i=length-2;i >= 0;i--) {
            int need = INT_MAX;
            int index = -1;
            for(int j=i+1;j < length;j++) {
                if (nums[j] < need && getHighNumber(nums[j]) >= getHighNumber(nums[i])) {
                    index = j;
                    need = nums[j];
                }
            }
            if (index==-1) {
                continue;
            }
            if (getHighNumber(need) == getHighNumber(nums[i])) {
                if (need == nums[i]) {
                    return ;
                }

                if(getBits(nums[i])==1) {
                    int temp = nums[i]*10 + getHighNumber(nums[i+1]);
                    if(temp > need) {
                        return ;
                    } else {
                        swap(nums[i],nums[index]);
                        return ;
                    }
                }

                if(getBits(need)==1) {
                    int temp = need*10 + getHighNumber(nums[i+1]);
                    if (temp > need) {
                        swap(nums[i],nums[index]);
                        return ;
                    } else {
                        return ;
                    }
                }

                if (getBits(nums[i])==3) {
                    swap(nums[i],nums[index]);
                    return ;
                }

                if(getBits(need)==3) {
                    return ;
                }
            } else {
                swap(nums[i],nums[index]);
                return ;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,5};
    s.nextPermutation(nums);

}