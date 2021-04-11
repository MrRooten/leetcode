#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> candidates;
    list<int> candidates2;
    int un_use_n = 0;
    vector<vector<int>> addTwoVector(vector<vector<int>> a, vector<vector<int>> b) {
        vector<vector<int>> res;
        if (a.size() == 0 || b.size() == 0) {
            return res;
        }

        for(auto i:a) {
            for(auto j:b) {
                vector<int> tmp;
                tmp.insert(tmp.begin(),i.begin(),i.end());
                tmp.insert(tmp.end(),j.begin(),j.end());
                res.push_back(tmp);
            }
        }

        return res;
    }
    int findMaxBeforeNum(int num) {
        int n = candidates.size();
        int i;
        for(i=0;candidates[i] < num&&i < n;i++) {

        }

        return candidates[i] > num?i-1:i;
    }
    vector<vector<int>> dp(int n,list<int>& stores) {
        vector<vector<int>> ans;
        if (n == 0) {
            return ans;
        }
        if (stores.front() > n) {
            return ans;
        } else if (stores.front() == n) {
            ans.push_back({1});
            stores.erase(find(stores.begin(),stores.end(),1));
            return ans;
        }


        if (n == un_use_n) {
            return ans;
        }
        int n_max = findMaxBeforeNum(n);


        for(int i=n_max;candidates[i] >= n/2;i--) {
            if (candidates[i] == n && (find(stores.begin(),stores.end(),n)!=stores.end())) {
                stores.erase(find(stores.begin(),stores.end(),n));
                ans.push_back({n});
                continue;
            }

            if (n == this->un_use_n) {
                continue;
            }
            vector<vector<int>> a = dp(i,stores);
            if (a.size() == 0) {
                break;
            }
            vector<vector<int>> b = dp(n-i,stores);
            vector<vector<int>> tmp = addTwoVector(a,b);
            if (tmp.size() != 0) {
                for (auto v : tmp) {
                    ans.push_back(v);
                }
            }
        }

        return ans;

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        this->candidates2.insert(candidates2.begin(),candidates.begin(),candidates.end());
        return dp(target,this->candidates2);
    }
};

int main() {
    vector<vector<int>> a = {{1,2,3},{4,5,6}};
    vector<vector<int>> b = {{8,9,0},{11,12,13}};
    Solution s;
    vector<int> v = {10,1,2,7,6,1,5};
    vector<vector<int>> res = s.combinationSum2(v,3);
}