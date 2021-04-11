#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getValueByIndex(list<string>& l,int i) {
        if (l.size() == 0) {
            return "";
        }
        auto l_front = l.begin();
        advance(l_front,i);
        return *l_front;
    }

    void removeNodeByIndex(list<string>& l,int i) {
        auto l_front = l.begin();
        advance(l_front,i);
        l.erase(l_front);
    }
    string getPermutation(int n, int k) {
        if (n == 1) {
            return "1";
        }
        list<string> nlist;
        vector<int> v(n+1);
        string ans;
        v[0] = 1;
        for(int i=1;i <=n;i++) {
            v[i] = i * v[i-1];
        }
        for(int i=1;i <=n;i++) {
            nlist.push_back(to_string(i));
        }
        int start;
        int j;
        for(j=n;j >=2;j--) {
            if ((k - 1) / v[j-1] !=0 ) {
                j--;
                break;
            } else {
                ans += getValueByIndex(nlist,0);
                removeNodeByIndex(nlist,0);
            }
        }
        int i = k-1;
        while(j!=0) {
            ans += getValueByIndex(nlist,(int)i/v[j]);
            removeNodeByIndex(nlist,(int)i/v[j]);
            i = i % v[j];
            j--;
        }
        ans += getValueByIndex(nlist,(int)0);
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.getPermutation(5,2) << endl;
}