#include <vector>
#include <stdio.h>
using namespace std;

void print(vector<int> v) {
    printf("{ ");
    for(int i=0;i < v.size();i++) {
        printf("%d ",v[i]);
    }
    printf("} ");
    printf("\n");
}
class Solution {
public:
    /*vector<vector<int>>*/
    vector<vector<int>> combine(int n, int k) {
        vector<int> pointers;
        vector<vector<int>> res;
        if (k == 1) {
            for(int i=1;i <=n;i++) {
                pointers = {i};
                res.push_back(pointers);
            }
            return res;
        }
        for(int i=1;i <= k;i++) {
            pointers.push_back(i);
        }
        int i = 0;
        while(pointers[0]!=n-k+2) {
            res.push_back(pointers);
            print(pointers);
            int j = pointers.size()-1;
            do{
                if(pointers[j] == n-k+j+1) {
                    j--;
                } else {
                    break;
                }
            } while(j > 0 );

            if (j == pointers.size()-1) {
                pointers[j]++;
                continue;
            }
            pointers[j]++;
            do {
                pointers[j+1] = pointers[j]+1;
                j++;
            } while(j < pointers.size());
        }

        return res;
    }
};

int main() {
    Solution s;
    s.combine(10,3);
}