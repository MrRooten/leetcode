#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxPos_first(vector<int>& v,int i,int j) {
        if (i >= j) {
            return j;
        }
        int max = v[i];
        int pos = i;
        do {
            if (v[i] > max) {
                pos = i;
                max = v[i];
            }
            i++;
        } while (i <= j);
        return pos;
    }

    int findMaxPos_last(vector<int>& v,int i,int j) {
        if (i >= j) {
            return max(i,j);
        }
        int max = v[j];
        int pos = j;
        do {
            if (v[j] > max) {
                pos = j;
                max = v[j];
            }
            j--;
        } while (j >= i);

        return pos;
    }
    int getVolume(vector<int>& height,int i,int j) {
        int lower = height[i] < height[j]? height[i] : height[j];
        
        int ans = 0;
        i += 1;
        while (i < j) {
            ans += lower - height[i];
            i++;
        }

        return ans;
    }
    int trap(vector<int>& height) {
        if (height.size() == 0 || height.size() == 1) {
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        while (height[l] <= height[l+1] && l < r) {
            l++;
        }

        while (height[r] <= height[r-1] && r > l) {
            r--;
        }

        if (r <= l) {
            return 0;
        }
        int ans = 0;
        int left = 0;
        int right = 0;
        int max_pos = findMaxPos_first(height,l,r);
        int i;
        int j = max_pos;
        while(true) {
            i = findMaxPos_last(height,l,j-1);
            ans += getVolume(height,i,j);
            j = i;
            if (i == l) {
                break;
            }
        }
        j = max_pos;
        while(true) {
            i = findMaxPos_first(height,j+1,r);
            ans += getVolume(height,j,i);
            j = i;
            if (i == r) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arg = {1000,999,998,997,996,995,994,993,992,991,990,989,988,987,986,985,984,983,982,981,980,979,978,977,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966,966};
    cout << s.trap(arg) << endl;
}